
; -[print_char]-
; Print a single character to stdout
; takes:
;       rdi - character to print
; modifies:
;       rax, rdx, rsi, rdi, rcx, r11
; returns:
;       nothing

global	print_char

align 16
print_char:
        mov     eax, 1D
        push    rdi
        lea     rsi, [rsp]
        mov     edi, 1D
        mov     edx, 1D
        syscall
        pop     rdi
        ret
