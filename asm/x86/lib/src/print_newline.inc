
%ifndef PRINT_NEWLINE_INC
%define PRINT_NEWLINE_INC

; -[print_newline]-
; Print the newline (0x0A / \n ) character to stdout
; takes:
;       nothing
; modifies:
;       rax, rdx, rdi, rsi, rcx, r11
; returns:
;       nothing

extern print_newline

%endif ; PRINT_NEWLINE_INC include guard
