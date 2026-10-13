# Print fib(0)..fib(24) computed recursively (exercises calls and the stack).
.equ UART, 0x10000000
.equ EXIT, 0x10000004

_start:
    li   sp, 0x10000          # top of 64 KiB RAM
    li   s0, 0                # n
    li   s1, 25
next:
    la   a0, s_fib; call puts
    mv   a0, s0;    call print_dec
    la   a0, s_eq;  call puts
    mv   a0, s0;    call fib
    call print_dec
    li   a0, '\n';  call putc
    addi s0, s0, 1
    blt  s0, s1, next
    li   t0, EXIT
    sw   zero, 0(t0)
halt: j halt

# a0 = fib(a0)
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

putc:
    li   t0, UART
    sb   a0, 0(t0)
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

# Print unsigned a0 in decimal (no divider: repeated subtraction of powers of 10).
print_dec:
    la   t0, pow10
    li   t3, 0                # set once a non-zero digit has been printed
pd_loop:
    lw   t1, 0(t0)
    beqz t1, pd_done
    li   t2, 0
pd_sub:
    bltu a0, t1, pd_emit
    sub  a0, a0, t1
    addi t2, t2, 1
    j    pd_sub
pd_emit:
    bnez t2, pd_put
    bnez t3, pd_put
    li   t4, 1
    beq  t1, t4, pd_put       # always print the units digit
    j    pd_next
pd_put:
    li   t3, 1
    addi t2, t2, '0'
    li   t4, UART
    sb   t2, 0(t4)
pd_next:
    addi t0, t0, 4
    j    pd_loop
pd_done:
    ret

s_fib: .asciz "fib("
s_eq:  .asciz ") = "
.align 2
pow10: .word 1000000000, 100000000, 10000000, 1000000, 100000, 10000, 1000, 100, 10, 1, 0
