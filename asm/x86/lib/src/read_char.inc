
%ifndef READ_CHAR_INC
%define READ_CHAR_INC


; -[read_char]-
; Read one character from stdin
; takes:
;       nothing
; modifies:
;       rax, rdx, rsi, rdi, rcx, r11
; returns:
;       rax - character read from stdin

extern read_char

%endif ; READ_CHAR_INC include guard
