
%ifndef PRINT_CHAR_INC
%define PRINT_CHAR_INC


; -[print_char]-
; Print a single character to stdout
; takes:
;       rdi - character to print
; modifies:
;       rax, rdx, rsi, rdi, rcx, r11
; returns:
;       nothing

extern print_char

%endif ; PRINT_CHAR_INC include guard
