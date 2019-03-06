
%ifndef STRING_TO_INT_INC
%define STRING_TO_INT_INC

; -[string_to_int]-
; parse a string containing a signed number to an signed integer
; takes:
;       rdi - string address to read from, string must be terminated with \0
; modifies:
;       rax, rcx, rdx, rsi, rdi, r8, r9, r10, r11
; returns:
;       rax - signed integer value, -1 on failure
;	rdx - number of characters processed

extern string_to_int

%endif ; STRING_TO_INT_INC include guard
