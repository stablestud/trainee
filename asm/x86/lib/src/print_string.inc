
%ifndef PRINT_STRING_INC
%define PRINT_STRING_INC


; -[print_string]-
; Print a sequence of character to stdout
; takes:
;       rdi - address of string
; modifies:
;       rax, rcx, rdx, rdi, rsi, r8, r9, r10, r11
; returns:
;       nothing

extern print_string

%endif ; PRINT_STRING_INC
