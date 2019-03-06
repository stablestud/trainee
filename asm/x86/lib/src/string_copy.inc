
%ifndef STRING_COPY_INC
%define STRING_COPY_INC


; -[string_copy]-
; Copies string to destination
; takes:
;	rdi - address of string
;	rsi - address of buffer (destination)
;	rdx - length of buffer
; modifies:
; 	rax, rcx, rsi, rdi, r9, r10, r8
; returns:
;	rax - buffers address if string was copied, 0 otherwise

extern string_copy

%endif ; STRING_COPY_INC include guard
