# Self-checking RV32I test. Exits 0 on success, otherwise the failing test
# number (held in gp).
.equ UART, 0x10000000
.equ EXIT, 0x10000004

_start:
    li sp, 0x10000

    # register-register ALU
    li gp, 1;  li t0, 5; li t1, 7; add t2, t0, t1; li t3, 12; bne t2, t3, fail
    li gp, 2;  sub t2, t0, t1; li t3, -2; bne t2, t3, fail
    li gp, 3;  li t0, 0xF0F0; li t1, 0x0FF0; and t2, t0, t1; li t3, 0x00F0; bne t2, t3, fail
    li gp, 4;  or  t2, t0, t1; li t3, 0xFFF0; bne t2, t3, fail
    li gp, 5;  xor t2, t0, t1; li t3, 0xFF00; bne t2, t3, fail
    li gp, 6;  li t0, 1; li t1, 31; sll t2, t0, t1; li t3, 0x80000000; bne t2, t3, fail
    li gp, 7;  srl t3, t2, t1; li t4, 1; bne t3, t4, fail
    li gp, 8;  sra t3, t2, t1; li t4, -1; bne t3, t4, fail
    li gp, 9;  li t0, -1; li t1, 1; slt t2, t0, t1; li t3, 1; bne t2, t3, fail
    li gp, 10; sltu t2, t0, t1; bnez t2, fail
    li gp, 11; li t0, 33; li t1, 0x10; sll t2, t1, t0; li t3, 0x20; bne t2, t3, fail  # shamt uses low 5 bits

    # register-immediate ALU
    li gp, 20; li t0, 100; addi t1, t0, -200; li t2, -100; bne t1, t2, fail
    li gp, 21; slti t1, t0, 101; li t2, 1; bne t1, t2, fail
    li gp, 22; sltiu t1, t0, -1; li t2, 1; bne t1, t2, fail
    li gp, 23; xori t1, t0, -1; li t2, -101; bne t1, t2, fail
    li gp, 24; ori t1, t0, 0x7ff; li t2, 0x7ff; bne t1, t2, fail
    li gp, 25; andi t1, t0, 0x0f; li t2, 4; bne t1, t2, fail
    li gp, 26; li t0, -16; srai t1, t0, 2; li t2, -4; bne t1, t2, fail
    li gp, 27; srli t1, t0, 28; li t2, 0xf; bne t1, t2, fail
    li gp, 28; slli t1, t0, 4; li t2, -256; bne t1, t2, fail

    # upper immediates
    li gp, 30; lui t0, 0x12345; li t1, 0x12345000; bne t0, t1, fail
here:
    li gp, 31; auipc t0, 0; addi t0, t0, -4; la t1, here; bne t0, t1, fail

    # loads and stores
    li gp, 40; la s0, buf; sw zero, 0(s0); li t0, 0x80; sb t0, 0(s0); lb t1, 0(s0); li t2, -128; bne t1, t2, fail
    li gp, 41; lbu t1, 0(s0); li t2, 0x80; bne t1, t2, fail
    li gp, 42; li t0, 0x8001; sh t0, 2(s0); lh t1, 2(s0); li t2, -32767; bne t1, t2, fail
    li gp, 43; lhu t1, 2(s0); li t2, 0x8001; bne t1, t2, fail
    li gp, 44; lw t1, 0(s0); li t2, 0x80010080; bne t1, t2, fail
    li gp, 45; li t0, 0x5a; sb t0, 1(s0); lw t1, 0(s0); li t2, 0x80015a80; bne t1, t2, fail
    li gp, 46; li t0, 0xdeadbeef; sw t0, 4(s0); lw t1, 4(s0); bne t0, t1, fail
    li gp, 47; lbu t1, 7(s0); li t2, 0xde; bne t1, t2, fail
    li gp, 48; lh t1, 6(s0); li t2, 0xffffdead; bne t1, t2, fail
    li gp, 49; addi s1, s0, 8; lw t1, -4(s1); bne t0, t1, fail

    # branches: not taken
    li gp, 50; li t0, -1; li t1, 1
    beq  t0, t1, fail
    bne  t0, t0, fail
    blt  t1, t0, fail
    bge  t0, t1, fail
    bltu t0, t1, fail
    bgeu t1, t0, fail
    # branches: taken
    li gp, 51; beq  t0, t0, b1; j fail
b1: li gp, 52; bne  t0, t1, b2; j fail
b2: li gp, 53; blt  t0, t1, b3; j fail
b3: li gp, 54; bge  t1, t0, b4; j fail
b4: li gp, 55; bltu t1, t0, b5; j fail
b5: li gp, 56; bgeu t0, t1, b6; j fail
b6: li gp, 57; bge  t0, t0, b7; j fail
b7:
    # jumps
    li gp, 60; jal ra, func; li t1, 42; bne a0, t1, fail
    li gp, 61; li a0, 0; la t0, func; jalr ra, 0(t0); li t1, 42; bne a0, t1, fail
    li gp, 62; li a0, 0; la t0, func; addi t0, t0, 1; jalr ra, t0, 0; li t1, 42; bne a0, t1, fail  # bit 0 cleared
    li gp, 63; la t0, after; jal t1, after; after: bne t1, t0, fail   # link = pc+4

    # x0 is hardwired to zero
    li gp, 70; addi zero, zero, 5; bnez zero, fail
    li gp, 71; lui zero, 1; bnez zero, fail

    # recursion through the stack
    li gp, 80; li a0, 15; call fib; li t0, 610; bne a0, t0, fail

pass:
    la a0, s_pass; call puts
    li t0, EXIT; sw zero, 0(t0)
halt: j halt

fail:
    la a0, s_fail; call puts
    li t0, EXIT; sw gp, 0(t0)
    j halt

func:
    li a0, 42
    ret

fib:
    li   t0, 2
    blt  a0, t0, fib_ret
    addi sp, sp, -12
    sw   ra, 8(sp)
    sw   a0, 4(sp)
    addi a0, a0, -1
    call fib
    sw   a0, 0(sp)
    lw   a0, 4(sp)
    addi a0, a0, -2
    call fib
    lw   t0, 0(sp)
    add  a0, a0, t0
    lw   ra, 8(sp)
    addi sp, sp, 12
fib_ret:
    ret

puts:
    li   t0, UART
puts_loop:
    lbu  t1, 0(a0)
    beqz t1, puts_done
    sb   t1, 0(t0)
    addi a0, a0, 1
    j    puts_loop
puts_done:
    ret

s_pass: .asciz "test: PASS\n"
s_fail: .asciz "test: FAIL\n"
.align 2
buf: .word 0, 0
