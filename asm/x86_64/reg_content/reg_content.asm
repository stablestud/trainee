section .data
digits:         db      '0123456789-'

section .text
global _start

_start:
; signed int
                mov     rax, 0xFFFFFFFFFFFFFFFF ; value to be printed
                test    rax, rax                ; test for sign bit set
                jns     .cont

;neg
                lea     rsi, [digits + 10D]
                call    write_1B
                shl     rax, 1D
                shr     rax, 1D

.cont:
                push    rax

.loop:
                pop     rax
                jmp     _exit


write_1B:
                push    rax
                push    rdi
                push    rdx
                push    rcx
                mov     rax, 1D
                mov     rdi, 1D
                mov     rdx, 1D
                syscall
                pop     rcx
                pop     rdx
                pop     rdi
                pop     rax
                ret

_exit:
                mov     rax, 60D
                xor     rdi, rdi
                syscall
