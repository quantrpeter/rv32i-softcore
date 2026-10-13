# RV32I Soft Core on Verilator

A small, readable RISC-V CPU written in SystemVerilog and simulated with
[Verilator](https://verilator.org). It implements the full **RV32I** base integer
instruction set as a **single-cycle** core. Every instruction finishes in exactly one
clock. The project also includes a tiny SoC (RAM plus memory-mapped I/O), a C++
testbench, a self-contained Python assembler, and three test programs.

There are no external toolchains to install. Verilator, a C++ compiler and Python 3
are enough.

```
$ make run PROG=hello
Hello from RV32I on Verilator!
[sim] exit code 0 after 164 cycles
```

---

## Table of contents

1. [Quick start](#1-quick-start)
2. [Repository layout](#2-repository-layout)
3. [System architecture](#3-system-architecture)
4. [Memory map](#4-memory-map)
5. [The core: `rv32i_core`](#5-the-core-rv32i_core)
   1. [Design philosophy: single-cycle](#51-design-philosophy-single-cycle)
   2. [Datapath diagram](#52-datapath-diagram)
   3. [Port list](#53-port-list)
   4. [Instruction fetch](#54-instruction-fetch)
   5. [Decode and immediate generation](#55-decode-and-immediate-generation)
   6. [Register file](#56-register-file)
   7. [ALU](#57-alu)
   8. [Branch comparator](#58-branch-comparator)
   9. [Load/store unit](#59-loadstore-unit)
   10. [Control unit and next-PC logic](#510-control-unit-and-next-pc-logic)
   11. [Traps and halting](#511-traps-and-halting)
   12. [Sequential state and reset](#512-sequential-state-and-reset)
   13. [Life of one clock cycle](#513-life-of-one-clock-cycle)
6. [The SoC: `soc`](#6-the-soc-soc)
7. [The testbench: `sim/main.cpp`](#7-the-testbench-simmaincpp)
8. [The assembler: `tools/asm.py`](#8-the-assembler-toolsasmpy)
9. [Test programs](#9-test-programs)
10. [Writing your own program](#10-writing-your-own-program)
11. [Debugging: trace and waveforms](#11-debugging-trace-and-waveforms)
12. [Supported instructions](#12-supported-instructions)
13. [Limitations and ideas for extension](#13-limitations-and-ideas-for-extension)

---

## 1. Quick start

### Prerequisites

| Tool        | Tested version | Notes                                    |
|-------------|----------------|------------------------------------------|
| Verilator   | 5.052          | `brew install verilator` / distro package |
| C++ compiler| Apple clang    | C++17. Verilator invokes it for you.      |
| Python      | 3.8+           | Runs the assembler. No extra packages.    |
| GNU make    | any            |                                          |

### Commands

```sh
make                         # build the simulator  -> obj_dir/Vsoc
make run                     # assemble + run sw/hello.s
make run PROG=fib            # run sw/fib.s
make run PROG=test           # run the self-checking instruction test
make run PROG=hello ARGS=+trace            # print every executed instruction
make run PROG=fib ARGS=+vcd=build/fib.vcd  # dump a waveform
make test                    # run every program in sw/ and report PASS/FAIL
make clean                   # remove obj_dir/ and build/
```

`make test` output:

```
PASS fib
PASS hello
PASS test
```

Each program's console output goes to `build/<name>.log`.

---

## 2. Repository layout

```
cpu/
├── Makefile              build / run / test entry points
├── README.md             this file
├── rtl/
│   ├── rv32i_core.sv     the CPU: single-cycle RV32I datapath + control
│   └── soc.sv            top level: core + 64 KiB RAM + UART/EXIT registers
├── sim/
│   └── main.cpp          Verilator C++ testbench (clock, reset, exit handling, VCD)
├── tools/
│   └── asm.py            two-pass RV32I assembler -> $readmemh hex file
├── sw/
│   ├── hello.s           prints a string
│   ├── fib.s             recursive Fibonacci + decimal printing
│   └── test.s            self-checking test of every RV32I instruction class
├── build/                (generated) .hex images and .log files
└── obj_dir/              (generated) Verilator output and the Vsoc binary
```

### Build flow

```
   sw/prog.s                      rtl/*.sv  +  sim/main.cpp
       │                                   │
       │  python3 tools/asm.py             │  verilator --cc --exe --build
       ▼                                   ▼
   build/prog.hex                    obj_dir/Vsoc  (native executable)
       │                                   │
       └──────────────┬────────────────────┘
                      ▼
        ./obj_dir/Vsoc +prog=build/prog.hex
                      │
                      ├── UART output   → stdout
                      ├── status line   → stderr  ("[sim] exit code 0 after N cycles")
                      └── process exit  → 0 pass / 1 nonzero exit / 2 trap / 3 timeout
```

Verilator translates the SystemVerilog into C++ classes (`Vsoc`). It compiles them
together with `sim/main.cpp` into one native program. The hardware design is fixed at
build time. The software program is chosen at run time with the `+prog=` plusarg, so
switching programs never requires a rebuild.

---

## 3. System architecture

```
+------------------------------------------------------------------------------+
|  sim/main.cpp   (C++ testbench)                                              |
|    - toggles clk, holds rst for 2 cycles                                     |
|    - loops until done | trap | cycle limit                                   |
|    - optional VCD waveform dump                                              |
|                                                                              |
|      clk, rst                                        done, exit_code, trap   |
|         │                                                  ▲                 |
|  +------│--------------------------------------------------│--------------+  |
|  |      ▼              soc  (rtl/soc.sv)                   │              |  |
|  |                                                                        |  |
|  |  +------------------------+  imem_addr  +--------------------------+   |  |
|  |  |                        |------------>|                          |   |  |
|  |  |                        |<------------|        RAM               |   |  |
|  |  |                        |  imem_rdata |   mem[0:16383]           |   |  |
|  |  |      rv32i_core        |             |   16384 x 32-bit         |   |  |
|  |  |  (rtl/rv32i_core.sv)   |             |   = 64 KiB               |   |  |
|  |  |                        |  dmem_addr  |   async read,            |   |  |
|  |  |  PC, 32 x 32 regfile,  |-----+------>|   sync byte-masked write |   |  |
|  |  |  decode, ALU, branch,  |     │       |   init: $readmemh(+prog) |   |  |
|  |  |  load/store, control   |  dmem_wdata +--------------------------+   |  |
|  |  |                        |  dmem_wstrb             ▲                  |  |
|  |  |                        |-----+-------------------┤ is_io = 0        |  |
|  |  |                        |     │                   │                  |  |
|  |  |                        |     │  address decode:  │                  |  |
|  |  |                        |     │  is_io =          │                  |  |
|  |  |                        |     │  addr[31:28]==1   │                  |  |
|  |  |                        |     │                   │ is_io = 1        |  |
|  |  |                        |     │       +-----------▼--------------+   |  |
|  |  |                        |     +------>|  MMIO                    |   |  |
|  |  |                        |             |  0x1000_0000 UART_TX ────────────> stdout
|  |  |                        |<------------|  0x1000_0004 EXIT   ─────────────> done, exit_code
|  |  |                        |  dmem_rdata |  (reads return 0)        |   |  |
|  |  +-----------+------------+  (RAM or 0) +--------------------------+   |  |
|  |              │ trap                                                    |  |
|  +--------------│---------------------------------------------------------+  |
|                 ▼                                                            |
+------------------------------------------------------------------------------+
```

There are three layers:

* **`rv32i_core`** is the CPU. It knows nothing about the memory map. It sees two
  memory ports, one for instructions and one for data, and both are expected to
  answer within the same cycle.
* **`soc`** is the "motherboard". It owns the RAM, decodes addresses, and implements
  two memory-mapped registers used to print characters and to end the simulation.
* **`main.cpp`** acts as the outside world. It drives the clock and reset and
  decides when the simulation stops.

The core has a **Harvard-style interface** with separate instruction and data ports,
but the SoC attaches both ports to the **same RAM array**. In effect it is a
von Neumann machine. Code and data share one 64 KiB address space, so a program can
read its own instructions or keep string constants next to its code, as all the
example programs do.

---

## 4. Memory map

| Address range               | Size    | Name      | Read             | Write                                    |
|-----------------------------|---------|-----------|------------------|------------------------------------------|
| `0x0000_0000 – 0x0000_FFFF` | 64 KiB  | RAM       | data             | data, with byte/halfword/word masks      |
| `0x1000_0000`               | 4 B     | `UART_TX` | `0`              | low byte printed to stdout immediately   |
| `0x1000_0004`               | 4 B     | `EXIT`    | `0`              | stops simulation, value = exit code      |

Details worth knowing:

* **Reset vector:** execution starts at `0x0000_0000` (the core's `RESET_PC` parameter).
* **Stack:** nothing sets it up for you. The programs do `li sp, 0x10000`, which is
  the top of RAM. The stack grows downward.
* **Decode is partial.** Any address whose top nibble is `0x1` counts as I/O. Inside
  that region only bits `[3:0]` are checked, so `0x1000_0000`, `0x1234_5670`, etc.
  all reach `UART_TX`. Any other address is treated as RAM and wraps modulo 64 KiB,
  because only address bits `[15:2]` index the array. Wrapping is cheap in hardware
  and harmless for well-behaved programs.
* **Instruction fetch always comes from RAM.** The instruction port has no I/O decode.

---

## 5. The core: `rv32i_core`

File: [rtl/rv32i_core.sv](rtl/rv32i_core.sv)

### 5.1 Design philosophy: single-cycle

In a **single-cycle** CPU, all the work for one instruction happens in **one clock
period**:

1. Fetch the instruction.
2. Decode it.
3. Read the registers.
4. Compute the result.
5. Access memory.
6. Choose the next PC.

All six steps are **pure combinational logic**. Only the architectural state (PC,
registers, memory) is updated at the clock's rising edge.

Consequences:

| Property                   | Single-cycle (this design)                                |
|----------------------------|-----------------------------------------------------------|
| CPI (cycles/instruction)   | **exactly 1**, always                                     |
| Hazards / forwarding       | none: each instruction sees the previous one's results    |
| Branch penalty             | none                                                      |
| Clock speed (real silicon) | slow: the period must cover the longest path (a load)    |
| Memory requirement         | instruction and data reads must be combinational         |
| Code complexity            | minimal: about 200 lines of RTL                           |

In simulation, clock speed is meaningless and clarity is everything, which makes
single-cycle the ideal teaching design. Section 13 describes how to pipeline it.

### 5.2 Datapath diagram

Signal names match the RTL. Thick vertical arrows show the main flow from top to
bottom. Everything inside the large box is combinational, except the PC, the
register file write port, and the `halted` flag, which update on `posedge clk`.

```
                                       ┌────────────────────────────────────────────────────┐
                                       │                  NEXT-PC MUX                       │
                                       │  default ............... pc + 4                    │
                                       │  JAL ................... pc + imm_j                │
                                       │  BRANCH & take_branch .. pc + imm_b                │
                                       │  JALR .................. (rs1_val + imm_i) & ~1    │
                                       └───────────────────────────────┬────────────────────┘
                                                                       │ pc_next
             ┌─────────────────────────────────────────────────────────┘
             │        (PC only updates if !illegal && !halted)
             ▼
       ┌───────────┐  posedge clk
       │  PC  reg  │◄──────────
       └─────┬─────┘
             │ pc ───────────────────────────────────────────────► imem_addr ═══► RAM
             │                                                                    │
             │                                       imem_rdata = insn ◄══════════┘
             │                                                │
             │                        ┌───────────────────────▼────────────────────────┐
             │                        │                   DECODE                       │
             │                        │ opcode=insn[6:0]   rd=insn[11:7]               │
             │                        │ funct3=insn[14:12] rs1=insn[19:15]             │
             │                        │ rs2=insn[24:20]    funct7=insn[31:25]          │
             │                        │ imm_i imm_s imm_b imm_u imm_j (sign-extended)  │
             │                        └───┬───────────────┬───────────────────┬────────┘
             │                     rs1,rs2│           imms│      opcode,f3,f7 │
             │                            ▼               │                   ▼
             │                ┌──────────────────────┐    │       ┌───────────────────────┐
             │                │   REGISTER FILE      │    │       │      CONTROL          │
             │                │   regs[0:31] x 32b   │    │       │  rd_we   store_en     │
             │      rd_val ──►│   2 async reads      │    │       │  rd_val select        │
             │   (write port, │   1 sync write       │    │       │  pc_next select       │
             │   rd_we && rd≠0│   x0 never written   │    │       │  illegal              │
             │   posedge clk) └───┬──────────────┬───┘    │       └───────────────────────┘
             │                    │rs1_val       │rs2_val │
             │                    │              │        │
             │                    │       ┌──────▼────────▼──┐
             │                    │       │ alu_b MUX         │  OP_REG ? rs2_val : imm_i
             │                    │       └──────┬────────────┘
             │                    │              │
             │          ┌─────────▼──────────────▼───┐     ┌──────────────────────────┐
             │          │           ALU              │     │    BRANCH COMPARATOR     │
             │          │ ADD/SUB SLL SLT SLTU XOR   │     │ EQ NE LT GE LTU GEU      │
             │          │ SRL/SRA OR AND             │     │ (rs1_val vs rs2_val)     │
             │          └─────────┬──────────────────┘     └────────────┬─────────────┘
             │                    │ alu_out                             │ take_branch
             │                    │                                     └──► NEXT-PC MUX
             │                    │
             │          ┌─────────┴───────────────────────────────────────────────────┐
             │          │                 LOAD / STORE UNIT                           │
             │          │ dmem_addr  = rs1_val + (STORE ? imm_s : imm_i)  ═══► RAM/IO │
             │          │ dmem_wdata = rs2_val << (8*addr[1:0])           ═══► RAM/IO │
             │          │ dmem_wstrb = size mask << addr[1:0]  (stores only)          │
             │          │ load_val   = extend((dmem_rdata >> 8*addr[1:0]))◄═══ RAM/IO │
             │          │ misaligned check                                            │
             │          └─────────┬───────────────────────────────────────────────────┘
             │                    │ load_val
             │                    ▼
             │          ┌──────────────────────────────────────────────┐
             │          │              WRITEBACK MUX (rd_val)          │
             └─────────►│  LUI: imm_u     AUIPC: pc + imm_u            │──► regfile write port
               pc       │  JAL/JALR: pc + 4                             │
                        │  LOAD: load_val  OP/OP-IMM: alu_out           │
                        └──────────────────────────────────────────────┘
```

### 5.3 Port list

| Port         | Dir | Width | Meaning                                                         |
|--------------|-----|-------|-----------------------------------------------------------------|
| `clk`        | in  | 1     | Clock. All state updates on the rising edge.                    |
| `rst`        | in  | 1     | Synchronous, active-high reset.                                 |
| `imem_addr`  | out | 32    | Instruction address (= PC).                                     |
| `imem_rdata` | in  | 32    | Instruction word at `imem_addr`, **same cycle**.                |
| `dmem_addr`  | out | 32    | Data address (byte address, computed every cycle).              |
| `dmem_wdata` | out | 32    | Store data, already shifted into the correct byte lanes.        |
| `dmem_wstrb` | out | 4     | Byte-write enables. Non-zero only for a committing store.       |
| `dmem_rdata` | in  | 32    | Aligned 32-bit word containing `dmem_addr`, **same cycle**.     |
| `trap`       | out | 1     | High once the core has halted on a trap.                        |

There is no separate "read enable". `dmem_addr` is driven for every instruction,
and the memory simply returns whatever is there. Reading has no side effects in this
SoC, so this is safe. A store is signalled purely by `dmem_wstrb != 0`.

Parameter: `RESET_PC` (default `32'h0000_0000`).

### 5.4 Instruction fetch

```systemverilog
assign imem_addr = pc;
wire [31:0] insn = imem_rdata;
```

That is all there is. Because the RAM is read asynchronously, the instruction for the
current PC is available a moment after the PC changes. The core has no fetch buffer,
instruction cache, or prefetching.

### 5.5 Decode and immediate generation

RV32I has six instruction formats. Register specifiers (`rs1`, `rs2`, `rd`) are
always in the same bit positions, which is why the register file can be read before
the instruction is even known to use those registers.

```
 31          25 24      20 19      15 14  12 11          7 6        0
+--------------+----------+----------+------+-------------+----------+
|    funct7    |   rs2    |   rs1    |funct3|     rd      |  opcode  |  R-type  (add, sub, ...)
+--------------+----------+----------+------+-------------+----------+
|        imm[11:0]        |   rs1    |funct3|     rd      |  opcode  |  I-type  (addi, lw, jalr)
+--------------+----------+----------+------+-------------+----------+
|  imm[11:5]   |   rs2    |   rs1    |funct3|  imm[4:0]   |  opcode  |  S-type  (sw, sh, sb)
+--------------+----------+----------+------+-------------+----------+
| imm[12|10:5] |   rs2    |   rs1    |funct3| imm[4:1|11] |  opcode  |  B-type  (beq, ...)
+--------------+----------+----------+------+-------------+----------+
|                 imm[31:12]                |     rd      |  opcode  |  U-type  (lui, auipc)
+-------------------------------------------+-------------+----------+
|            imm[20|10:1|11|19:12]          |     rd      |  opcode  |  J-type  (jal)
+-------------------------------------------+-------------+----------+
```

The core computes **all five immediates in parallel**. The control logic then picks
the one it needs. This costs a few wires and saves a mux on the decode path:

```systemverilog
imm_i = {{20{insn[31]}}, insn[31:20]};                                   // 12-bit signed
imm_s = {{20{insn[31]}}, insn[31:25], insn[11:7]};                       // 12-bit signed
imm_b = {{19{insn[31]}}, insn[31], insn[7], insn[30:25], insn[11:8], 1'b0}; // 13-bit, even
imm_u = {insn[31:12], 12'b0};                                            // upper 20 bits
imm_j = {{11{insn[31]}}, insn[31], insn[19:12], insn[20], insn[30:21], 1'b0}; // 21-bit, even
```

The sign bit is always `insn[31]`, which keeps the sign-extension logic tiny. That is
also why the B/J immediate bits look scrambled: the ISA keeps as many immediate bits
as possible in the same position across formats.

Opcodes recognised (`insn[6:0]`):

| Constant    | Bits      | Instructions                                    |
|-------------|-----------|-------------------------------------------------|
| `OP_LUI`    | `0110111` | `lui`                                           |
| `OP_AUIPC`  | `0010111` | `auipc`                                         |
| `OP_JAL`    | `1101111` | `jal`                                           |
| `OP_JALR`   | `1100111` | `jalr`                                          |
| `OP_BRANCH` | `1100011` | `beq bne blt bge bltu bgeu`                     |
| `OP_LOAD`   | `0000011` | `lb lh lw lbu lhu`                              |
| `OP_STORE`  | `0100011` | `sb sh sw`                                      |
| `OP_IMM`    | `0010011` | `addi slti sltiu xori ori andi slli srli srai`  |
| `OP_REG`    | `0110011` | `add sub sll slt sltu xor srl sra or and`       |
| `OP_FENCE`  | `0001111` | `fence` (executed as a no-op)                   |
| `OP_SYSTEM` | `1110011` | `ecall ebreak` (halt the core, see 5.11)        |

### 5.6 Register file

```systemverilog
logic [31:0] regs[32];
wire  [31:0] rs1_val = regs[rs1];
wire  [31:0] rs2_val = regs[rs2];
```

* **32 × 32-bit**, two asynchronous read ports and one synchronous write port.
* **`x0` is hardwired to zero.** Rather than adding a mux on every read, the core
  makes sure `regs[0]` is reset to 0 and **never written** (`rd != 0` guards the
  write). Reads of `x0` therefore always return 0 for free. `test.s` checks this
  with `addi zero, zero, 5` and `lui zero, 1`.
* The write happens at the clock edge **at the end** of the instruction. The next
  instruction reads the new value combinationally. Single-cycle designs need no
  forwarding.
* All registers are cleared on reset. The ISA does not require it, but it makes
  simulations deterministic.

### 5.7 ALU

The ALU has two operands:

* **A** is always `rs1_val`.
* **B** is `rs2_val` for `OP_REG` and `imm_i` for everything else (`alu_b` mux).

The operation is selected directly by `funct3`, because RISC-V uses the same
`funct3` encoding for register and immediate ALU instructions. `insn[30]` (bit 5 of
`funct7`) selects the "alternate" operation:

| `funct3` | Operation       | `alu_alt = 0`  | `alu_alt = 1`  | Notes                         |
|----------|-----------------|----------------|----------------|-------------------------------|
| `000`    | add             | `a + b`        | `a - b`        | SUB only exists for `OP_REG`  |
| `001`    | shift left      | `a << b[4:0]`  | –              |                               |
| `010`    | set less than   | `$signed(a) < $signed(b)` | –   | result is 0 or 1              |
| `011`    | set less than U | `a < b`        | –              | unsigned compare              |
| `100`    | xor             | `a ^ b`        | –              |                               |
| `101`    | shift right     | `a >> b[4:0]`  | `a >>> b[4:0]` | logical vs arithmetic         |
| `110`    | or              | `a \| b`       | –              |                               |
| `111`    | and             | `a & b`        | –              |                               |

```systemverilog
wire alu_alt = insn[30] && (is_reg_op || funct3 == 3'b101);
```

This condition matters. For `addi`, `insn[30]` is part of the **immediate**, so a
negative `addi` like `addi t1, t0, -200` has `insn[30] = 1`. If that bit selected
SUB, `addi` would subtract. The guard enables `alu_alt` only for register ops (SUB,
SRA) and for shifts (SRAI, where `insn[30]` really is an opcode bit).

Shift amounts use only the low 5 bits (`b[4:0]`), as the spec requires. `test.s`
test 11 checks that shifting by 33 behaves like shifting by 1.

### 5.8 Branch comparator

This is a separate comparator on `rs1_val` vs `rs2_val`. It runs in parallel with
the ALU and does not reuse it, because the ALU's B operand might be an immediate.

| `funct3` | Instr  | Condition                          |
|----------|--------|------------------------------------|
| `000`    | `beq`  | `rs1 == rs2`                       |
| `001`    | `bne`  | `rs1 != rs2`                       |
| `100`    | `blt`  | `$signed(rs1) <  $signed(rs2)`     |
| `101`    | `bge`  | `$signed(rs1) >= $signed(rs2)`     |
| `110`    | `bltu` | `rs1 <  rs2` (unsigned)            |
| `111`    | `bgeu` | `rs1 >= rs2` (unsigned)            |
| `010/011`| –      | reserved → illegal instruction     |

The branch target `pc + imm_b` is computed by its own adder in the next-PC logic.

### 5.9 Load/store unit

Memory is organised as **32-bit words**. Loads and stores of bytes and halfwords
must be mapped onto a word, so the unit does three things:

**1. Address generation**

```systemverilog
assign dmem_addr = rs1_val + (opcode == OP_STORE ? imm_s : imm_i);
wire [1:0] byte_off = dmem_addr[1:0];
```

The memory uses `dmem_addr[15:2]` to select the word, and the core uses
`byte_off` to select the bytes within it.

**2. Stores: lane steering and byte strobes**

The store data is shifted left so the bytes land in the correct "lane". A strobe
mask then tells the memory which lanes to actually write:

```
    dmem_wdata = rs2_val << (8 * byte_off)

    store_mask:   sb → 4'b0001 << byte_off
                  sh → 4'b0011 << byte_off
                  sw → 4'b1111
```

Example: `sb` of value `0x…AB` to address `0x102` (`byte_off = 2`):

```
              byte lane:    [3]     [2]     [1]     [0]
   rs2_val              =  ..      ..      ..      AB
   dmem_wdata = rs2<<16 =  ..      AB      ..      ..
   dmem_wstrb           =   0       1       0       0     → only lane 2 is written
   memory word 0x100    :  old     AB      old     old
```

**3. Loads: extract and extend**

The memory returns the whole aligned word. The core shifts it right so the wanted
byte or halfword sits at bit 0, then sign- or zero-extends it:

```
    ld_shifted = dmem_rdata >> (8 * byte_off)

    lb  : {{24{ld_shifted[7]}},  ld_shifted[7:0]}     sign-extend byte
    lh  : {{16{ld_shifted[15]}}, ld_shifted[15:0]}    sign-extend halfword
    lw  : dmem_rdata                                  whole word
    lbu : {24'b0, ld_shifted[7:0]}                    zero-extend byte
    lhu : {16'b0, ld_shifted[15:0]}                   zero-extend halfword
```

Example: `lh` from `0x106` when word `0x104` holds `0xDEADBEEF`:

```
    dmem_rdata         = DE AD BE EF
    >> 16              = 00 00 DE AD
    sign-extend [15:0] = FF FF DE AD   (= -8531)
```

**Alignment**

A halfword must be 2-byte aligned and a word must be 4-byte aligned. Otherwise the
access is flagged as misaligned and the core traps:

```systemverilog
misaligned = (funct3[1:0] == 2'b01 && byte_off[0]) ||   // lh/lhu/sh at odd address
             (funct3[1:0] == 2'b10 && byte_off != 0);   // lw/sw not word aligned
```

Misaligned accesses are allowed by the spec to trap, and trapping keeps the hardware
simple: an access never spans two words.

### 5.10 Control unit and next-PC logic

A single `always_comb` block decodes `opcode` into the control signals. Defaults are
set first (`pc_next = pc+4`, `rd_val = alu_out`, nothing written), and each opcode
overrides only what it needs:

| Opcode      | `rd_we` | `rd_val`      | `pc_next`                         | Memory      | Illegal when                                       |
|-------------|:-------:|---------------|-----------------------------------|-------------|----------------------------------------------------|
| `LUI`       | 1       | `imm_u`       | `pc+4`                            | –           | –                                                  |
| `AUIPC`     | 1       | `pc + imm_u`  | `pc+4`                            | –           | –                                                  |
| `JAL`       | 1       | `pc + 4`      | `pc + imm_j`                      | –           | –                                                  |
| `JALR`      | 1       | `pc + 4`      | `(rs1_val + imm_i) & ~1`          | –           | `funct3 != 0`                                      |
| `BRANCH`    | 0       | –             | `take_branch ? pc+imm_b : pc+4`   | –           | `funct3` = `010`/`011`                             |
| `LOAD`      | 1       | `load_val`    | `pc+4`                            | read        | `funct3` = `011`/`110`/`111`, or misaligned        |
| `STORE`     | 0       | –             | `pc+4`                            | write       | `funct3[2]` set or `funct3` = `011`, or misaligned |
| `OP_IMM`    | 1       | `alu_out`     | `pc+4`                            | –           | bad `funct7` on `slli`/`srli`/`srai`               |
| `OP_REG`    | 1       | `alu_out`     | `pc+4`                            | –           | `funct7` not `0x00` (or `0x20` for `sub`/`sra`)    |
| `FENCE`     | 0       | –             | `pc+4`                            | –           | –                                                  |
| `SYSTEM`    | 0       | –             | –                                 | –           | always (ECALL / EBREAK halt)                       |
| other       | 0       | –             | –                                 | –           | always                                             |

Then there is a final global check:

```systemverilog
if (pc_next[1:0] != 2'b00) illegal = 1'b1;   // no compressed (C) extension
```

Without the C extension, every instruction is 4-byte aligned. A jump or branch to a
non-aligned target is therefore an *instruction-address-misaligned* exception.
`JALR` clears bit 0 as the spec requires (`& ~1`). `test.s` test 62 relies on this,
but bit 1 is still checked.

**Why `x0` as `rd` is fine for jumps:** `j label` is `jal x0, label` and `ret` is
`jalr x0, 0(ra)`. They "write" the link address to `x0`, and the write is silently
dropped.

### 5.11 Traps and halting

This core does **not** implement the privileged architecture: no CSRs, no `mtvec`,
no exception handlers. Any exceptional condition simply **halts** the core:

* an illegal or unsupported instruction (including an all-zero word, which is how
  running off the end of a program usually shows up)
* a misaligned load or store
* a misaligned jump or branch target
* `ecall` or `ebreak`

When `illegal` is high:

1. **Nothing is committed.** The PC does not advance, no register is written, and
   `dmem_wstrb` is forced to `0`, so a faulting store never modifies memory.
2. `halted` is set at the clock edge. From then on the core is frozen.
3. A diagnostic is printed, for example:
   ```
   [core] TRAP: illegal/misaligned insn 00000000 at pc=00000040
   [core] EBREAK at pc=0000001c
   ```
4. The `trap` output goes high. The testbench sees it and exits with status 2.

This "precise halt" makes debugging easy. When the core stops, the PC still points
at the guilty instruction.

### 5.12 Sequential state and reset

Only three things in the core hold state:

| State      | Width     | Reset value  | Updated when                         |
|------------|-----------|--------------|--------------------------------------|
| `pc`       | 32        | `RESET_PC`   | every cycle, if `!illegal && !halted`|
| `regs[1..31]` | 32 × 31 | `0`        | `rd_we && rd != 0 && !illegal && !halted` |
| `halted`   | 1         | `0`          | set when `illegal`                   |

```systemverilog
always_ff @(posedge clk) begin
  if (rst) begin
    pc <= RESET_PC; halted <= 0; regs[*] <= 0;
  end else if (!halted) begin
    if (illegal) halted <= 1;                       // + $display diagnostic
    else begin
      pc <= pc_next;
      if (rd_we && rd != 0) regs[rd] <= rd_val;
    end
  end
end
```

Reset is **synchronous**: it takes effect at a clock edge while `rst` is high.
`dmem_wstrb` is also gated with `!rst`, so no garbage store can happen during reset.

### 5.13 Life of one clock cycle

The following shows `lw a0, 8(sp)` at `pc = 0x40`, followed by the next instruction.

```
             ┌──────────┐          ┌──────────┐          ┌──────────┐
  clk  ──────┘          └──────────┘          └──────────┘          └──
             ▲                     ▲                     ▲
             │ edge N              │ edge N+1            │ edge N+2
             │                     │                     │
  pc     ════╪═══ 0x40 ════════════╪═══ 0x44 ════════════╪═══ 0x48 ═══
             │                     │                     │
             │ ◄── combinational settle for "lw" ──►     │
             │  1. imem_rdata = mem[0x40>>2]             │
             │  2. decode: LOAD, rs1=sp, rd=a0, imm=8    │
             │  3. rs1_val = regs[sp]                    │
             │  4. dmem_addr = sp + 8                    │
             │  5. dmem_rdata = mem[(sp+8)>>2]           │
             │  6. load_val (lw → whole word)            │
             │  7. rd_val = load_val, rd_we = 1          │
             │  8. pc_next = 0x44                        │
             │                     │                     │
             │                     │ at edge N+1:        │
             │                     │   pc     <= 0x44    │
             │                     │   regs[a0] <= load_val
             │                     │                     │
             │                     │ ◄── next instr already sees new a0
```

The critical path is the longest chain of logic that must settle within one period.
Here it is the load:
`pc → RAM → decode → regfile read → adder → RAM → shifter → extender → regfile input`.
On real hardware this is what limits the clock frequency of a single-cycle design.

---

## 6. The SoC: `soc`

File: [rtl/soc.sv](rtl/soc.sv)

### RAM

```systemverilog
parameter int MEM_WORDS = 16384;          // 64 KiB
localparam int AW = $clog2(MEM_WORDS);    // 14
logic [31:0] mem[MEM_WORDS];

assign imem_rdata = mem[imem_addr[AW+1:2]];                 // async read
assign dmem_rdata = is_io ? 32'b0 : mem[dmem_addr[AW+1:2]]; // async read
```

* **Word-addressed** array, indexed with byte-address bits `[15:2]`.
* **Two asynchronous read ports** (instruction and data) and **one synchronous
  write port** with per-byte enables:

  ```systemverilog
  for (int i = 0; i < 4; i++)
    if (dmem_wstrb[i]) mem[dword][i*8 +: 8] <= dmem_wdata[i*8 +: 8];
  ```

* **Program loading:** at time 0 the array is zeroed, then filled with
  `$readmemh(prog, mem)`. `prog` comes from the `+prog=<file>` plusarg. The hex
  file has one 32-bit little-endian word per line, starting at address 0:

  ```
  00000517     ← word at 0x00: auipc a0, 0
  03450513     ← word at 0x04: addi  a0, a0, 52
  100002b7     ← word at 0x08: lui   t0, 0x10000
  00028293     ← word at 0x0c: addi  t0, t0, 0
  ```

  If `+prog` is missing, the simulation stops with `$fatal`.

### Address decode and MMIO

```systemverilog
wire is_io = dmem_addr[31:28] == 4'h1;
```

Writes (any non-zero `dmem_wstrb`) to the I/O region are routed by `dmem_addr[3:0]`:

| Offset | Register  | Effect on write                                                       |
|--------|-----------|-----------------------------------------------------------------------|
| `0x0`  | `UART_TX` | `$write("%c", wdata[7:0]); $fflush;` prints one character immediately |
| `0x4`  | `EXIT`    | `done <= 1; exit_code <= wdata;`                                      |
| other  | –         | ignored                                                               |

Both `sb` and `sw` to `UART_TX` work: for offset 0 the character is always in lane 0.

I/O reads return `0`. This SoC has no input device or status register. The UART is
"infinitely fast" and never busy, so software never needs to poll it.

### Instruction trace

With `+trace`, the SoC prints the PC and instruction word at every rising edge
where the core is running:

```systemverilog
always_ff @(posedge clk)
  if (trace_en && !rst && !trap) $display("[trace] pc=%08x insn=%08x", imem_addr, imem_rdata);
```

### SoC ports

| Port        | Dir | Width | Meaning                                         |
|-------------|-----|-------|-------------------------------------------------|
| `clk`       | in  | 1     | clock                                           |
| `rst`       | in  | 1     | synchronous active-high reset                   |
| `done`      | out | 1     | program wrote `EXIT`                            |
| `exit_code` | out | 32    | value written to `EXIT`                         |
| `trap`      | out | 1     | core halted on a trap                           |

---

## 7. The testbench: `sim/main.cpp`

The testbench is the only non-synthesizable "hardware". It plays the role of the
oscillator and the reset button.

### Clocking

Each call to `tick()` produces one full clock cycle and advances simulated time
by 2 units:

```
        tick():   clk=1 → eval() → [dump]  → time++
                  clk=0 → eval() → [dump]  → time++
                  cycle++
```

`eval()` makes Verilator propagate all combinational logic and run any `always_ff`
blocks triggered by the edge.

### Run sequence

```
   ┌────────────────────────────┐
   │ parse plusargs             │  +prog  +max-cycles  +vcd  +trace
   └─────────────┬──────────────┘
                 ▼
   ┌────────────────────────────┐
   │ rst = 1, 2 ticks           │  core/SoC state initialised
   │ rst = 0, cycle = 0         │
   └─────────────┬──────────────┘
                 ▼
   ┌────────────────────────────┐   no
   │ done || trap ||            ├────────► tick() ──┐
   │ cycle >= max_cycles ?      │◄──────────────────┘
   └─────────────┬──────────────┘
                 │ yes
                 ▼
   ┌────────────────────────────┐
   │ close VCD, final(),        │
   │ report on stderr, exit     │
   └────────────────────────────┘
```

### Plusargs

| Plusarg            | Default  | Meaning                                    |
|--------------------|----------|--------------------------------------------|
| `+prog=<file.hex>` | required | program image to load into RAM             |
| `+max-cycles=<n>`  | 10000000 | stop with a timeout after this many cycles |
| `+vcd=<file.vcd>`  | off      | write a VCD waveform of every signal       |
| `+trace`           | off      | print every executed instruction           |

### Process exit status

| Status | Meaning                              | stderr message                          |
|--------|--------------------------------------|-----------------------------------------|
| `0`    | program wrote `0` to `EXIT`          | `[sim] exit code 0 after N cycles`      |
| `1`    | program wrote a non-zero exit code   | `[sim] exit code K after N cycles`      |
| `2`    | core trapped                         | `[sim] core trapped after N cycles`     |
| `3`    | cycle limit reached                  | `[sim] timeout after N cycles`          |

`make test` relies on this: a program "passes" if and only if the simulator exits
with status 0.

Since CPI is exactly 1, **the cycle count equals the number of instructions
executed**.

---

## 8. The assembler: `tools/asm.py`

There is no RISC-V GCC/LLVM toolchain dependency. A ~400-line Python assembler turns
`.s` files into `$readmemh` hex images.

```
python3 tools/asm.py sw/hello.s -o build/hello.hex       # assemble
python3 tools/asm.py sw/hello.s -o build/hello.hex -l    # also print the symbol table
```

### How it works: two passes

```
              source text
                   │
     ┌─────────────▼─────────────────────────────────────────┐
     │ PASS 1: layout                                        │
     │  - strip '#' comments, split on ';' (quote-aware)     │
     │  - define labels at the current address               │
     │  - evaluate .equ constants                            │
     │  - work out each statement's SIZE and advance pc      │
     │  - record items: (kind, addr, line, ...)              │
     └─────────────┬─────────────────────────────────────────┘
                   │ symbol table complete (forward refs resolved)
     ┌─────────────▼─────────────────────────────────────────┐
     │ PASS 2: encode                                        │
     │  - evaluate operands using the full symbol table      │
     │  - expand pseudo-instructions                         │
     │  - range-check immediates / offsets                   │
     │  - write little-endian bytes into the image           │
     └─────────────┬─────────────────────────────────────────┘
                   ▼
           image → one hex word per line
```

Two passes are needed because of **forward references**. In `beqz t1, done`, the
label `done` is defined later in the file. Pass 1 just reserves 4 bytes; pass 2 knows
where `done` is and computes the offset.

### The `li` sizing subtlety

`li rd, value` expands to **one** instruction (`addi rd, x0, value`) if the value
fits in 12 signed bits, and to **two** otherwise (`lui` + `addi`). Pass 1 must
decide the size *before* it knows all symbols:

* If the value can be evaluated in pass 1 (a literal, an earlier `.equ`, an earlier
  label) **and** fits in 12 bits → 1 word.
* Otherwise → 2 words.

Pass 2 always emits exactly the size decided in pass 1. Without that rule, a later
label address could shift and invalidate every offset already computed.

### `%hi` / `%lo` and the rounding trick

`lui` loads the upper 20 bits, and `addi` adds a **sign-extended** 12-bit value. If
bit 11 of the low part is set, `addi` effectively subtracts, so the upper part must
be rounded up to compensate:

```python
hi(v) = ((v + 0x800) >> 12) & 0xFFFFF
lo(v) = sign_extend_12(v & 0xFFF)
```

Example, `li t0, 0xDEADBEEF`:

```
lo = 0xEEF → bit 11 set → -0x111
hi = (0xDEADBEEF + 0x800) >> 12 = 0xDEADC
lui  t0, 0xDEADC      → t0 = 0xDEADC000
addi t0, t0, -0x111   → t0 = 0xDEADBEEF ✓
```

`la rd, label` uses the same split on the **PC-relative** offset
(`auipc` + `addi`), so code is position independent.

### Supported syntax

* **Registers:** `x0`–`x31` and ABI names (`zero ra sp gp tp t0–t6 s0–s11 a0–a7 fp`).
* **Numbers:** decimal, `0x` hex, `0b` binary, char literals `'A'`, `'\n'`.
* **Expressions:** sums and differences of numbers and symbols (`buf+4`, `END-START`),
  `%hi(x)`, `%lo(x)`.
* **Labels:** `name:` (several per line allowed, may share a line with code).
* **Separators:** `;` puts several statements on one line. `#` starts a comment.

Directives:

| Directive                    | Effect                                           |
|------------------------------|--------------------------------------------------|
| `.word a, b, ...`            | 32-bit values (expressions allowed, e.g. labels) |
| `.half`, `.byte`             | 16- / 8-bit values                               |
| `.ascii "s"`                 | bytes of string                                  |
| `.asciz "s"` / `.string "s"` | bytes of string + NUL                            |
| `.space n`                   | `n` zero bytes                                   |
| `.align n`                   | pad with zeros to a `2^n` boundary               |
| `.equ name, v` / `.set`      | define a constant                                |
| `.text .data .globl .section`| accepted and ignored (single flat image)         |

Pseudo-instructions:

| Pseudo                 | Expansion                                   |
|------------------------|---------------------------------------------|
| `nop`                  | `addi x0, x0, 0`                            |
| `li rd, imm`           | `addi rd, x0, imm` or `lui` + `addi`        |
| `la rd, sym`           | `auipc rd, %hi(off)` + `addi rd, rd, %lo(off)` |
| `mv rd, rs`            | `addi rd, rs, 0`                            |
| `not rd, rs`           | `xori rd, rs, -1`                           |
| `neg rd, rs`           | `sub rd, x0, rs`                            |
| `seqz rd, rs`          | `sltiu rd, rs, 1`                           |
| `snez rd, rs`          | `sltu rd, x0, rs`                           |
| `j off`                | `jal x0, off`                               |
| `jal off`              | `jal ra, off`                               |
| `call off`             | `jal ra, off` (±1 MiB reach)                |
| `jr rs`                | `jalr x0, 0(rs)`                            |
| `jalr rs`              | `jalr ra, 0(rs)`                            |
| `ret`                  | `jalr x0, 0(ra)`                            |
| `beqz/bnez/bltz/bgez rs, off` | branch against `x0`                  |
| `blez/bgtz rs, off`    | `bge x0, rs` / `blt x0, rs`                 |
| `bgt/ble/bgtu/bleu a, b, off` | swapped-operand `blt/bge/bltu/bgeu`  |

Errors are reported with a line number, for example
`sw/foo.s: line 12: immediate 5000 out of range [-2048, 2047]`.

---

## 9. Test programs

| Program        | What it does                                                                 | Cycles     |
|----------------|------------------------------------------------------------------------------|------------|
| `sw/hello.s`   | Prints `Hello from RV32I on Verilator!` byte by byte through `UART_TX`.      | 164        |
| `sw/fib.s`     | Prints `fib(0)` … `fib(24)` using naive recursion (stack, `call`/`ret`) and a decimal printer built on repeated subtraction (RV32I has no divide). | ~3.7 M |
| `sw/test.s`    | Self-checking test of every instruction class. Prints `test: PASS` / `test: FAIL` and exits with the failing test number. | ~19 k |

### What `test.s` covers

Each check loads its test number into `gp` first. On mismatch it jumps to `fail`,
which writes `gp` to `EXIT`, so a non-zero exit code tells you exactly which check
broke.

| Tests  | Area                                                                                     |
|--------|------------------------------------------------------------------------------------------|
| 1–11   | `add sub and or xor sll srl sra slt sltu`; shift amount masked to 5 bits                 |
| 20–28  | `addi slti sltiu xori ori andi srai srli slli` incl. negative immediates                 |
| 30–31  | `lui`, `auipc` (checked against `la`)                                                    |
| 40–49  | `sb sh sw lb lbu lh lhu lw`: sign/zero extension, byte lanes, negative offsets           |
| 50–57  | all six branches, both not-taken and taken, incl. signed vs unsigned edge cases          |
| 60–63  | `jal`, `jalr` (both syntaxes), `jalr` clearing bit 0, link register = `pc+4`             |
| 70–71  | writes to `x0` are discarded                                                             |
| 80     | recursive `fib(15) = 610` through the stack                                              |

---

## 10. Writing your own program

1. Create `sw/myprog.s`.
2. `make run PROG=myprog`. It is also picked up automatically by `make test`.

Template:

```asm
.equ UART, 0x10000000
.equ EXIT, 0x10000004

_start:                     # execution begins at address 0
    li   sp, 0x10000        # stack at top of RAM (if you need one)

    li   t0, UART
    li   t1, 'A'
    sb   t1, 0(t0)          # print 'A'
    li   t1, '\n'
    sb   t1, 0(t0)

    li   t0, EXIT
    li   t1, 0              # 0 = success
    sw   t1, 0(t0)          # simulation stops here
halt:
    j    halt               # never reached in simulation, but good hygiene
```

Rules of the road:

* Code starts at `0x0`, so put your entry point first.
* **Always finish by writing `EXIT`.** Falling off the end of your code executes
  zeroed memory, which is an illegal instruction, and the core traps (status 2).
* Put data after code, and use `.align 2` before `.word` data that follows strings.
* The standard RISC-V calling convention is a good idea: args/results in `a0–a7`,
  return address in `ra`, callee-saved `s0–s11`, temporaries `t0–t6`.

---

## 11. Debugging: trace and waveforms

### Instruction trace

```
$ make run PROG=hello ARGS=+trace
[trace] pc=00000000 insn=00000517      auipc a0, 0
[trace] pc=00000004 insn=03450513      addi  a0, a0, 52      (la a0, msg)
[trace] pc=00000008 insn=100002b7      lui   t0, 0x10000
[trace] pc=0000000c insn=00028293      addi  t0, t0, 0       (li t0, UART)
[trace] pc=00000010 insn=00054303      lbu   t1, 0(a0)
[trace] pc=00000014 insn=00030863      beqz  t1, done
[trace] pc=00000018 insn=00628023      sb    t1, 0(t0)
H[trace] pc=0000001c insn=00150513     addi  a0, a0, 1
...
```

(The disassembly comments are added here for illustration; the simulator prints the
raw words.) UART output is interleaved with the trace, which is why `H` appears
right after the `sb`.

Use the symbol table to map PCs back to labels:

```
$ python3 tools/asm.py sw/hello.s -o build/hello.hex -l
00000000 _start
00000010 loop
00000024 done
00000030 halt
00000034 msg
```

### Waveforms

```
make run PROG=test ARGS=+vcd=build/test.vcd
gtkwave build/test.vcd        # or: surfer build/test.vcd
```

Every internal signal is visible under `TOP.soc.core.*`. Useful signals to add:
`pc`, `insn`, `opcode`, `rs1_val`, `rs2_val`, `alu_out`, `dmem_addr`, `dmem_wstrb`,
`rd`, `rd_val`, `rd_we`, `illegal`. For long programs, combine with
`+max-cycles=<n>` to keep the file small.

---

## 12. Supported instructions

All 40 RV32I base instructions are decoded. `fence` is a no-op, and `ecall`/`ebreak`
halt the core because there is no trap handler to jump to:

| Class          | Instructions                                                      |
|----------------|-------------------------------------------------------------------|
| Upper imm.     | `lui auipc`                                                        |
| Jumps          | `jal jalr`                                                         |
| Branches       | `beq bne blt bge bltu bgeu`                                        |
| Loads          | `lb lh lw lbu lhu`                                                 |
| Stores         | `sb sh sw`                                                         |
| ALU immediate  | `addi slti sltiu xori ori andi slli srli srai`                     |
| ALU register   | `add sub sll slt sltu xor srl sra or and`                          |
| Memory order   | `fence` (no-op: single hart, in-order, no caches)                  |
| System         | `ecall ebreak`: halt the core (no trap handler)                    |

Not implemented: Zicsr (`csrr*`), M (mul/div), A (atomics), C (compressed),
F/D (floating point), interrupts, privilege modes.

---

## 13. Limitations and ideas for extension

| Limitation                            | Why                                   | How to extend                                                                                                                                       |
|---------------------------------------|---------------------------------------|-----------------------------------------------------------------------------------------------------------------------------------------------------|
| **Async RAM reads**                   | Needed for single-cycle               | FPGA block RAM reads synchronously. To synthesise, either use LUT-RAM (small memories), or split into a 2-stage (fetch / execute) or 5-stage pipeline. |
| **One instruction per cycle, long critical path** | Single-cycle design       | Classic 5-stage pipeline (IF/ID/EX/MEM/WB) with forwarding and hazard detection. This core's blocks map directly onto those stages.                  |
| **No multiply/divide**                | RV32I only                            | Add the **M** extension: `funct7 = 0x01` under `OP_REG`. A combinational `*` is fine in simulation; a multicycle divider is a good exercise.        |
| **Traps just halt**                   | No CSRs                               | Implement Zicsr + machine mode: `mtvec`, `mepc`, `mcause`, `mstatus`, `mret`. Redirect `pc_next` to `mtvec` instead of halting.                    |
| **No C compiler support**             | No toolchain dependency               | Install `riscv64-unknown-elf-gcc` (`-march=rv32i -mabi=ilp32`), add a `crt0.s` that sets `sp` and calls `main`, a linker script placing `.text` at 0, then `objcopy -O verilog` or a small ELF→hex script. |
| **No input / timer**                  | Minimal SoC                           | Add MMIO registers: a cycle counter at `0x1000_0008`, a UART RX FIFO, or a timer interrupt.                                                         |
| **Not compliance-tested**             | Uses own test only                    | Run the official [riscv-arch-test](https://github.com/riscv-non-isa/riscv-arch-test) suite for RV32I.                                                |
