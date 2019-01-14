
%ifndef PRINT_UINT_INC
%define PRINT_UINT_INC


; -[print_uint]-
; Print unsigned integer in decimal base to stdout
; takes:
;       rdi - unsigned integer to be printed
; modifies:
;       rax, rdx, rcx, rsi, rdi, r9, r10, r11
; returns:
;       nothing

extern print_uint

%endif ; PRINT_UINT_INC include guard
