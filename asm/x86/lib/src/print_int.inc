
%ifndef PRINT_INT_INC
%define PRINT_INT_INC

; -[print_int]-
; Print signed integer in decimal base to stdout
; takes:
;       rdi - signed integer to be printed
; modifies:
;       rax, rdx, rcx, rsi, rdi, r9, r11
; returns:
;       nothing

extern print_int

%endif ; PRINT_INT_INC include guard
