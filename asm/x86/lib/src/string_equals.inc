%ifndef STRING_EQUALS_INC
%define STRING_EQUALS_INC


; -[string_equals]-
; Compares two strings, if equal return 1, if not 0
; takes:
;	rdi - address to first string
;	rsi - address to second string
; modifies:
;	rax, rdx, rdi, rsi, r8, r9
; returns:
;	rax - 1 if strings are equal, 0 if not

extern string_equals

%endif ; STRING_EQUALS include guard
