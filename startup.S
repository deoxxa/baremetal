.global _start

_start:
ldr sp, = sp_top
bl main
b .
