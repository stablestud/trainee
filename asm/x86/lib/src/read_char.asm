
; -[read_char]-
; Read one character from stdin
; takes:
;       nothing
; modifies:
;       rax, rdx, rsi, rdi, rcx, r11
; returns:
;       rax - character read from stdin

global	read_char

align 16
read_char:
        xor     rax, rax
        xor     rdi, rdi
        mov     rdx, 1D
        push    rax
        mov     rsi, rsp
        syscall
        pop     rax
        ret
