.global _start

_start:
/* 1mb stack space */
ldr sp, =(stack_limit + (1024 * 1024))
bl main
b .
