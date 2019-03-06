
; -[print_string]-
; Print a sequence of character to stdout
; takes:
;       rdi - address of string
; modifies:
;       rax, rcx, rdx, rdi, rsi, r8, r9, r10, r11
; returns:
;       nothing

global	print_string

align 16
print_string:
        call    string_length
        lea     rsi, [rdi]
        mov     edi, 1D
        mov     rdx, rax 
        mov     rax, 1D
        syscall
        ret
