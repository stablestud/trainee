
; -[print_newline]-
; Print the newline (0x0A / \n ) character to stdout
; takes:
;       nothing
; modifies:
;       rax, rdx, rdi, rsi, rcx, r11
; returns:
;       nothing

global	print_newline

align 16
print_newline:
        mov     eax, 1D
        mov     edx, 1D
        mov     edi, 1D
        push    0x0A
        lea     rsi, [rsp]
        syscall
        pop     rdi
        ret
