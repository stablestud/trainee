global _start
global _exit

section .data
string: db      'q123 12 12312 ', 0

section .text

strlen:
        xor     rax, rax
.loop:
        cmp     byte [rdi + rax], 0
        jz     .ret
        inc     rax
        jmp     .loop
.ret:
        ret

_start: 
        mov     rdi, string
        call strlen
        mov     rdi, rax

_exit:
        mov     rax, 60
        syscall
