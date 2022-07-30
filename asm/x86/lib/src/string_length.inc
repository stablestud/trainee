
%ifndef STRING_LENGTH_H
%define STRING_LENGTH_H


; -[string_length]-
; Counts the length of a string till \0 sign
; takes:
;       rdi - address of string
; modifies:
;       rax, r8, r9, r10, r11
; returns:
;       rax - size of the string counted excluding \0 sign

extern string_length

%endif ; STRING_LENGTH_H include guard
