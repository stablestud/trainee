
%ifndef CALLISO_INC
%define CALLISO_INC

; -[calliso]-
; Call isolator, makes a call to the address pushed previously onto the stack,
; used mainly for debugging functions
; takes:
;       Address to function, must be pushed to stack before calling
;       this function
; modifies:
;       rax - return value of called function, if modified by function
;       It resets other modification made by the function 
; returns:
;       rax - return value of called function, if modified by function

extern	calliso

%endif	; CALLISO_INC include guard
