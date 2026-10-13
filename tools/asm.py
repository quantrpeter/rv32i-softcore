#!/usr/bin/env python3
"""Tiny two-pass RV32I assembler that emits a $readmemh-compatible hex file.

Supports all RV32I instructions, common pseudo-instructions (li, la, mv, not,
neg, j, jr, ret, call, nop, seqz, snez, beqz/bnez/blez/bgez/bltz/bgtz,
bgt/ble/bgtu/bleu), %hi/%lo, labels, ';' statement separators, '#' comments,
and the directives .word .half .byte .ascii .asciz/.string .space .align
.equ/.set (.text/.data/.globl/.section are accepted and ignored).
"""
import argparse
import ast
import re
import sys

ABI = ("zero ra sp gp tp t0 t1 t2 s0 s1 a0 a1 a2 a3 a4 a5 a6 a7 "
       "s2 s3 s4 s5 s6 s7 s8 s9 s10 s11 t3 t4 t5 t6").split()
REGS = {f"x{i}": i for i in range(32)}
REGS.update({n: i for i, n in enumerate(ABI)})
REGS["fp"] = 8

R_OPS = {"add": (0, 0x00), "sub": (0, 0x20), "sll": (1, 0x00), "slt": (2, 0x00),
         "sltu": (3, 0x00), "xor": (4, 0x00), "srl": (5, 0x00), "sra": (5, 0x20),
         "or": (6, 0x00), "and": (7, 0x00)}
I_OPS = {"addi": 0, "slti": 2, "sltiu": 3, "xori": 4, "ori": 6, "andi": 7}
SHIFT_OPS = {"slli": (1, 0x00), "srli": (5, 0x00), "srai": (5, 0x20)}
LOADS = {"lb": 0, "lh": 1, "lw": 2, "lbu": 4, "lhu": 5}
STORES = {"sb": 0, "sh": 1, "sw": 2}
BRANCHES = {"beq": 0, "bne": 1, "blt": 4, "bge": 5, "bltu": 6, "bgeu": 7}
SWAPPED_BRANCHES = {"bgt": "blt", "ble": "bge", "bgtu": "bltu", "bleu": "bgeu"}
ZERO_BRANCHES = {"beqz": ("beq", False), "bnez": ("bne", False), "bgez": ("bge", False),
                 "bltz": ("blt", False), "blez": ("bge", True), "bgtz": ("blt", True)}


class AsmError(Exception):
    pass


def hi(v):
    return ((v + 0x800) >> 12) & 0xFFFFF


def lo(v):
    v &= 0xFFF
    return v - 0x1000 if v & 0x800 else v


def evaluate(expr, syms):
    expr = expr.strip()
    m = re.fullmatch(r"%(hi|lo)\((.*)\)", expr)
    if m:
        v = evaluate(m[2], syms)
        return hi(v) if m[1] == "hi" else lo(v)
    tokens = re.findall(r"'(?:\\.|[^'\\])'|[A-Za-z0-9_.$]+|[+-]|\S", expr)
    if not tokens:
        raise AsmError("empty expression")
    total, sign, expect_term = 0, 1, True
    for tok in tokens:
        if tok in "+-":
            if expect_term:
                sign = -sign if tok == "-" else sign
            else:
                sign, expect_term = (1 if tok == "+" else -1), True
            continue
        if not expect_term:
            raise AsmError(f"bad expression '{expr}'")
        if tok.startswith("'"):
            val = ord(ast.literal_eval(tok))
        elif tok[0].isdigit():
            val = int(tok, 0)
        elif tok in syms:
            val = syms[tok]
        else:
            raise AsmError(f"undefined symbol '{tok}'")
        total += sign * val
        sign, expect_term = 1, False
    if expect_term:
        raise AsmError(f"bad expression '{expr}'")
    return total


def reg(name):
    try:
        return REGS[name.strip()]
    except KeyError:
        raise AsmError(f"unknown register '{name}'") from None


def mem_operand(text):
    m = re.fullmatch(r"(.*)\(\s*(\w+)\s*\)", text.strip())
    if not m:
        raise AsmError(f"expected offset(reg), got '{text}'")
    return (m[1].strip() or "0"), reg(m[2])


def check_range(val, bits, what, signed=True):
    lo_, hi_ = (-(1 << (bits - 1)), (1 << (bits - 1)) - 1) if signed else (0, (1 << bits) - 1)
    if not lo_ <= val <= hi_:
        raise AsmError(f"{what} {val} out of range [{lo_}, {hi_}]")


# --- encoders -----------------------------------------------------------------
def enc_r(f7, rs2, rs1, f3, rd, op=0x33):
    return f7 << 25 | rs2 << 20 | rs1 << 15 | f3 << 12 | rd << 7 | op


def enc_i(imm, rs1, f3, rd, op):
    check_range(imm, 12, "immediate")
    return (imm & 0xFFF) << 20 | rs1 << 15 | f3 << 12 | rd << 7 | op


def enc_s(imm, rs2, rs1, f3):
    check_range(imm, 12, "offset")
    imm &= 0xFFF
    return (imm >> 5) << 25 | rs2 << 20 | rs1 << 15 | f3 << 12 | (imm & 0x1F) << 7 | 0x23


def enc_b(off, rs2, rs1, f3):
    check_range(off, 13, "branch offset")
    if off & 1:
        raise AsmError("misaligned branch target")
    off &= 0x1FFF
    return ((off >> 12) & 1) << 31 | ((off >> 5) & 0x3F) << 25 | rs2 << 20 | rs1 << 15 | \
        f3 << 12 | ((off >> 1) & 0xF) << 8 | ((off >> 11) & 1) << 7 | 0x63


def enc_u(imm20, rd, op):
    return (imm20 & 0xFFFFF) << 12 | rd << 7 | op


def enc_j(off, rd):
    check_range(off, 21, "jump offset")
    if off & 1:
        raise AsmError("misaligned jump target")
    off &= 0x1FFFFF
    return ((off >> 20) & 1) << 31 | ((off >> 1) & 0x3FF) << 21 | ((off >> 11) & 1) << 20 | \
        ((off >> 12) & 0xFF) << 12 | rd << 7 | 0x6F


# --- source handling ----------------------------------------------------------
def split_outside_quotes(text, seps):
    """Split text on any char in seps that is not inside a '...' or "..." literal.
    A '#' outside quotes ends the line."""
    parts, cur, quote, i = [], "", None, 0
    while i < len(text):
        c = text[i]
        if quote:
            cur += c
            if c == "\\" and i + 1 < len(text):
                cur += text[i + 1]
                i += 1
            elif c == quote:
                quote = None
        elif c in "'\"":
            quote, cur = c, cur + c
        elif c == "#":
            break
        elif c in seps:
            parts.append(cur)
            cur = ""
        else:
            cur += c
        i += 1
    parts.append(cur)
    return [p.strip() for p in parts]


def fits12(expr, syms):
    try:
        v = evaluate(expr, syms)
    except AsmError:
        return False
    return -2048 <= v <= 2047


def size_of(mn, args, syms):
    if mn == "li":
        return 1 if fits12(args[1], syms) else 2
    if mn == "la":
        return 2
    return 1


def assemble(source):
    # Pass 1: collect statements, assign addresses, define labels/constants.
    syms, items, pc = {}, [], 0
    for lineno, line in enumerate(source.splitlines(), 1):
        for stmt in split_outside_quotes(line, ";"):
            try:
                while (m := re.match(r"([A-Za-z_.$][\w.$]*)\s*:(.*)", stmt)):
                    if m[1] in syms:
                        raise AsmError(f"duplicate symbol '{m[1]}'")
                    syms[m[1]] = pc
                    stmt = m[2].strip()
                if not stmt:
                    continue
                mn, _, rest = stmt.partition(" ")
                mn, rest = mn.lower(), rest.strip()
                if mn.startswith("."):
                    pc = directive(mn, rest, pc, syms, items, lineno)
                    continue
                args = split_outside_quotes(rest, ",") if rest else []
                if pc % 4:
                    raise AsmError("instruction at unaligned address")
                n = size_of(mn, args, syms)
                items.append(("insn", pc, lineno, mn, args, n))
                pc += 4 * n
            except AsmError as e:
                raise AsmError(f"line {lineno}: {e}") from None

    # Pass 2: encode.
    image = bytearray(pc)
    for item in items:
        kind, addr, lineno = item[:3]
        try:
            if kind == "data":
                image[addr:addr + len(item[3])] = item[3]
            elif kind == "dataexpr":
                width, expr = item[3], item[4]
                val = evaluate(expr, syms) & ((1 << (8 * width)) - 1)
                image[addr:addr + width] = val.to_bytes(width, "little")
            else:
                _, _, _, mn, args, n = item
                words = encode(mn, args, addr, n, syms)
                assert len(words) == n, (mn, words)
                for i, w in enumerate(words):
                    image[addr + 4 * i:addr + 4 * i + 4] = (w & 0xFFFFFFFF).to_bytes(4, "little")
        except AsmError as e:
            raise AsmError(f"line {lineno}: {e}") from None
    return image, syms


def directive(mn, rest, pc, syms, items, lineno):
    if mn in (".text", ".data", ".globl", ".global", ".section", ".type", ".size"):
        return pc
    if mn in (".equ", ".set"):
        name, expr = split_outside_quotes(rest, ",")
        syms[name] = evaluate(expr, syms)
        return pc
    if mn in (".word", ".half", ".byte"):
        width = {".word": 4, ".half": 2, ".byte": 1}[mn]
        for expr in split_outside_quotes(rest, ","):
            items.append(("dataexpr", pc, lineno, width, expr))
            pc += width
        return pc
    if mn in (".ascii", ".asciz", ".string"):
        data = ast.literal_eval(rest).encode("latin-1")
        if mn != ".ascii":
            data += b"\0"
        items.append(("data", pc, lineno, data))
        return pc + len(data)
    if mn == ".space":
        n = evaluate(rest, syms)
        items.append(("data", pc, lineno, bytes(n)))
        return pc + n
    if mn == ".align":
        align = 1 << evaluate(rest, syms)
        pad = (-pc) % align
        items.append(("data", pc, lineno, bytes(pad)))
        return pc + pad
    raise AsmError(f"unknown directive '{mn}'")


def encode(mn, a, pc, n, syms):
    def ev(expr):
        return evaluate(expr, syms)

    def need(k):
        if len(a) != k:
            raise AsmError(f"'{mn}' expects {k} operands, got {len(a)}")

    # pseudo-instructions
    if mn == "nop":
        return [enc_i(0, 0, 0, 0, 0x13)]
    if mn == "li":
        need(2)
        rd, v = reg(a[0]), ev(a[1])
        if n == 1:
            return [enc_i(v, 0, 0, rd, 0x13)]
        check_range(v, 32, "li value") if v < 0 else check_range(v, 32, "li value", signed=False)
        return [enc_u(hi(v), rd, 0x37), enc_i(lo(v), rd, 0, rd, 0x13)]
    if mn == "la":
        need(2)
        rd, off = reg(a[0]), ev(a[1]) - pc
        return [enc_u(hi(off), rd, 0x17), enc_i(lo(off), rd, 0, rd, 0x13)]
    if mn == "mv":
        need(2)
        return [enc_i(0, reg(a[1]), 0, reg(a[0]), 0x13)]
    if mn == "not":
        need(2)
        return [enc_i(-1, reg(a[1]), 4, reg(a[0]), 0x13)]
    if mn == "neg":
        need(2)
        return [enc_r(0x20, reg(a[1]), 0, 0, reg(a[0]))]
    if mn == "seqz":
        need(2)
        return [enc_i(1, reg(a[1]), 3, reg(a[0]), 0x13)]
    if mn == "snez":
        need(2)
        return [enc_r(0, reg(a[1]), 0, 3, reg(a[0]))]
    if mn == "j":
        need(1)
        return [enc_j(ev(a[0]) - pc, 0)]
    if mn == "call":
        need(1)
        return [enc_j(ev(a[0]) - pc, 1)]
    if mn == "jr":
        need(1)
        return [enc_i(0, reg(a[0]), 0, 0, 0x67)]
    if mn == "ret":
        need(0)
        return [enc_i(0, 1, 0, 0, 0x67)]
    if mn in ZERO_BRANCHES:
        need(2)
        base, swap = ZERO_BRANCHES[mn]
        r = reg(a[0])
        rs1, rs2 = (0, r) if swap else (r, 0)
        return [enc_b(ev(a[1]) - pc, rs2, rs1, BRANCHES[base])]
    if mn in SWAPPED_BRANCHES:
        need(3)
        return [enc_b(ev(a[2]) - pc, reg(a[0]), reg(a[1]), BRANCHES[SWAPPED_BRANCHES[mn]])]

    # base instructions
    if mn in R_OPS:
        need(3)
        f3, f7 = R_OPS[mn]
        return [enc_r(f7, reg(a[2]), reg(a[1]), f3, reg(a[0]))]
    if mn in I_OPS:
        need(3)
        return [enc_i(ev(a[2]), reg(a[1]), I_OPS[mn], reg(a[0]), 0x13)]
    if mn in SHIFT_OPS:
        need(3)
        f3, f7 = SHIFT_OPS[mn]
        sh = ev(a[2])
        check_range(sh, 5, "shift amount", signed=False)
        return [enc_i(f7 << 5 | sh, reg(a[1]), f3, reg(a[0]), 0x13)]
    if mn in LOADS:
        need(2)
        off, rs1 = mem_operand(a[1])
        return [enc_i(ev(off), rs1, LOADS[mn], reg(a[0]), 0x03)]
    if mn in STORES:
        need(2)
        off, rs1 = mem_operand(a[1])
        return [enc_s(ev(off), reg(a[0]), rs1, STORES[mn])]
    if mn in BRANCHES:
        need(3)
        return [enc_b(ev(a[2]) - pc, reg(a[1]), reg(a[0]), BRANCHES[mn])]
    if mn in ("lui", "auipc"):
        need(2)
        v = ev(a[1])
        check_range(v, 20, "upper immediate", signed=False)
        return [enc_u(v, reg(a[0]), 0x37 if mn == "lui" else 0x17)]
    if mn == "jal":
        if len(a) == 1:
            return [enc_j(ev(a[0]) - pc, 1)]
        need(2)
        return [enc_j(ev(a[1]) - pc, reg(a[0]))]
    if mn == "jalr":
        if len(a) == 1:                     # jalr rs1
            return [enc_i(0, reg(a[0]), 0, 1, 0x67)]
        if len(a) == 2:                     # jalr rd, off(rs1)
            off, rs1 = mem_operand(a[1])
            return [enc_i(ev(off), rs1, 0, reg(a[0]), 0x67)]
        need(3)                             # jalr rd, rs1, off
        return [enc_i(ev(a[2]), reg(a[1]), 0, reg(a[0]), 0x67)]
    if mn == "fence":
        return [0x0FF0000F]
    if mn == "ecall":
        return [0x00000073]
    if mn == "ebreak":
        return [0x00100073]
    raise AsmError(f"unknown instruction '{mn}'")


def main():
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("source")
    ap.add_argument("-o", "--output", required=True, help="output .hex file")
    ap.add_argument("-l", "--listing", action="store_true", help="print symbol table")
    args = ap.parse_args()
    with open(args.source) as f:
        try:
            image, syms = assemble(f.read())
        except AsmError as e:
            sys.exit(f"{args.source}: {e}")
    image += bytes((-len(image)) % 4)
    with open(args.output, "w") as f:
        for i in range(0, len(image), 4):
            f.write(f"{int.from_bytes(image[i:i + 4], 'little'):08x}\n")
    if args.listing:
        for name, val in sorted(syms.items(), key=lambda kv: kv[1]):
            print(f"{val:08x} {name}")


if __name__ == "__main__":
    main()
