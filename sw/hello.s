# Print a string over the UART, then exit with code 0.
.equ UART, 0x10000000
.equ EXIT, 0x10000004

_start:
    la   a0, msg
    li   t0, UART
loop:
    lbu  t1, 0(a0)
    beqz t1, done
    sb   t1, 0(t0)
    addi a0, a0, 1
    j    loop
done:
    li   t0, EXIT
    sw   zero, 0(t0)
halt:
    j    halt

msg: .asciz "Hello from RV32I on Verilator!\n"
