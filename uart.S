.global putchar

.equ UART0_PTR, 0x0101f1000

putchar:
ldr r1, =(UART0_PTR)
str r0, [r1]
mov pc, lr
