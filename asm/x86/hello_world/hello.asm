global _start

section .data
message:        db 'Hello World!', 10

section .text
_start:         mov     rax, 1          ; 'write syscall number
                mov     rdi, 1          ; stdout descriptor
                mov     rsi, message    ; string address
                mov     rdx, 13         ; string length in bytes
                syscall

                mov     rax, 60         ; 'exit' syscall number
        REX.W   xor     rdi, rdi        ; zeroing rdi for return type
                syscall
