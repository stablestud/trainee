
; -[print_int]-
; Print signed integer in decimal base to stdout
; takes:
;       rdi - signed integer to be printed
; modifies:
;       rax, rdx, rcx, rsi, rdi, r9, r11
; returns:
;       nothing

global	print_int

align 16
print_int:
        push    rbx
        mov     rbx, rsp
        mov     rax, rdi                        ; load quadword value to convert
        mov     r11, 10D                        ; division
        test    rax, rax
        jns     .loop
        neg     rax
.loop:
        xor     rdx, rdx
        idiv    r11
        or      dl, 0x30
        dec     rbx
        mov     byte [rbx], dl
        test    rax, rax
        jnz     .loop
.sign:
        test    rdi, rdi
        jns     .print
        dec     rbx
        mov     byte [rbx], 0x2D
.print:
        mov     rax, rsp
        sub     rax, rbx
        mov     rdx, rax
        mov     rax, 1D
        mov     rdi, 1D
        lea     rsi, [rbx]
        syscall
        pop     rbx
        ret
