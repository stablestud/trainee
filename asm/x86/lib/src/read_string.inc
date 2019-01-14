
%ifndef READ_STRING_INC
%define READ_STRING_INC


; -[read_string]-
; Read a string of fixed maximum size from stdin, removes \n from the end
; takes:
;       rdi - buffer address to save the string to plus space for \0 sign
;       rsi - size of the buffer
; modifies:
;       rax, rdx, rdi, rsi, rcx, r11
; returns:
;       rax - returns buffer starting address

extern read_string

%endif ; READ_STRING_INC
