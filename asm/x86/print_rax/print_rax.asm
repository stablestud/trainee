section .data
hex_enc:        dd      '0123456789ABCDEF', 10D
number:         dq      8841D, 99D, 325D

section .text
global _start
_start:
                ; Calculates how many qword values have been pushed to the stack
                mov     rax, rsp

                push    word 12D
                push    word 12D

                mov     rdi, rsp
                sub     rax, rdi
                ;mov     rdi, 8D
                ;div     rdi
                ; End of calculation

                ;mov     rax, -1D
                ;mov     eax, -1D

                mov     rdi, 1D
                mov     rdi, 1D
                mov     rdi, 1D
                mov     rdx, 1D
                mov     rcx, 64D
.loop:          
                push    rax

                sub     rcx, 4D
                sar     rax, cl
                and     rax, 0xF
                lea     rsi, [hex_enc + rax]

                mov     rax, 1D
                push    rcx
                syscall
                pop     rcx
                pop     rax
                test    rcx, rcx
                jnz     _start.loop

_exit:
                mov     rax, 60D
                xor     rdi, rdi
                syscall
