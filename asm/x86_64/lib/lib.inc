section .text


; -[exit]-
; Terminates the program
; takes:
;       rdi - exit code of program
; edtis:
;       rax, rcx, r11
; returns:
;       nothing

exit:
        mov     eax, 60D
        syscall


; -[string_length]-
; Counts the length of a string till \0 sign
; takes:
;       rdi - address of string
; edits:
;       rax
; returns:
;       rax - size of the string counted without \0 sign

string_length:
        xor     rax, rax
.loop:
        cmp     byte [rdi + rax], 0D
        jz      .ret
        inc     rax
        jmp     .loop
.ret:
        ret


; -[print_char]-
; Print a single character to stdout
; takes:
;       rdi - character to print
; modifies:
;       rax, rdx, rsi, rdi, rcx, r11
; returns:
;       nothing

print_char:
        mov     eax, 1D
        push    rdi
        lea     rsi, [rsp]
        mov     edi, 1D
        mov     edx, 1D
        syscall
        pop     rdi
        ret


; -[print_string]-
; Print a sequence of character to stdout
; takes:
;       rdi - address of string
; modifies:
;       rax, rdx, rsi, rdi, rcx, r11
; returns:
;       nothing

print_string:
        call    string_length
        lea     rsi, [rdi]
        mov     edi, 1D
        mov     rdx, rax 
        mov     eax, 1D
        syscall
        ret


; -[print_newline]-
; Print the newline (0x0A / \n ) character to stdout
; takes:
;       nothing
; modifies:
;       rax, rdx, rdi, rsi, rcx, r11
; returns:
;       nothing

print_newline:
        mov     eax, 1D
        mov     edx, 1D
        mov     edi, 1D
        push    0x0A
        lea     rsi, [rsp]
        syscall
        pop     rdi
        ret


; -[print_uint]-
; Print unsigned integer in decimal base to stdout
; takes:
;       rdi - unsigned integer to be printed
; modifies:
;       rax, rdx, rcx, r9, r10, r11
; returns:
;       nothing

print_uint:
        push    rbx
        mov     rax, rdi                        ; load quadword value to convert
        mov     rsi, 1D                         ; count char stored in r10
        xor     rcx, rcx                        ; count characters to print
        mov     r9,  0x30_30_30_30__30_30_30_30 ; converting bytes to ASCII
        xor     r10, r10                        ; temp storage for 8 characters
        mov     r11, 10D                        ; divisor
        mov     rbx, rsp
        sub     rsp, 16D
.loop:
        shl     r10, 8D
        xor     rdx, rdx
        div     r11
        or      byte r10b, dl
        inc     rcx
        test    rax, rax
        jz      .print
        shl     byte sil, 1D
        mov     rdi, 20
        jc      .empty
        jmp     .loop
.empty:
        or      r10, r9
        push    r10
        add     rsp, 16D
        mov     rsi, 1D
        jmp     .loop
.print:
        or      r10, r9
        push    r10
        mov     rax, 1D
        mov     rdx, rcx
        mov     rdi, 1D
        lea     rsi, [rbx - 24D]
        syscall
        lea     rsp, [rbx]
        pop     rbx
        ret
        

global _start
_start:
        mov     rdi, 0xFF_FF_FF_FF__FF_FF_FF_FF
        call    print_uint
        call    print_newline
        call    exit
