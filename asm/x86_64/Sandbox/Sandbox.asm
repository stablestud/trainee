section .data

section .text
global _start
global _exit

_start:
        mov     rax, 2       
        mov     rdi, 4
        div     rdi
_exit:
        mov     rdi, rax
        mov     rax, 60D
        syscall
