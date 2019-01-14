
; -[print_uint]-
; Print unsigned integer in decimal base to stdout
; takes:
;       rdi - unsigned integer to be printed
; modifies:
;       rax, rdx, rcx, rsi, rdi, r9, r10, r11
; returns:
;       nothing

global	print_uint

align 16
print_uint:
        push    rbx
        mov     rbx, rsp
        mov     rax, rdi                        ; load quadword value to convert
        mov     rsi, 1D                         ; count char stored in r10
        xor     rcx, rcx                        ; count characters to print
        mov     r9,  0x30_30_30_30__30_30_30_30 ; converting bytes to ASCII
        xor     r10, r10                        ; temp storage for 8 characters
        mov     r11, 10D                        ; division
.loop:
        shl     r10, 8D
        xor     rdx, rdx
        div     r11
        or      byte r10b, dl
        inc     rcx
        test    rax, rax
        jz      .fill
        shl     byte sil, 1D
        jc      .flush
        jmp     .loop
align 16
.flush:
        or      r10, r9
        push    r10
        mov     rsi, 1D
        xor     r10, r10
        jmp     .loop
align 16
.fill:
        shl     byte sil, 1D
        jc      .print
        shl     r10, 8D
        jmp     .fill
align 16
.print:
        or      r10, r9
        push    r10
        mov     rax, 1D
        mov     rdx, rcx
        mov     rdi, 1D
        lea     rsi, [rbx]
        sub     rsi, rdx
        syscall
        lea     rsp, [rbx]
        pop     rbx
        ret
