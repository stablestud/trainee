%ifndef STRING_TO_UINT_INC
%define STRING_TO_UINT_INC

; -[string_to_uint]-
; parse a string containing a unsigned number to an unsigned integer
; takes:
;       rdi - string address to read from, string must be terminated with \0
; modifies:
;       rax, rdx, rcx, rdi, r9, r10, r11
; returns:
;       rax - unsigned integer value, -1 on failure
;	rdx - number of characters processed

extern string_to_uint.inc

%endif ; STRING_TO_UINT_INC includde guard
