
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

global calliso

align 16
calliso:
        push    rbx
        push    rcx
        push    rdx
        push    rdi
        push    rsi
        push    rbp
        push    r8
        push    r9
        push    r10
        push    r11
	push	r12
	push	r13
	push	r14
	push	r15
        push    rax
        mov     rax, rsp
        add     rax, 128D
        push    rax
        call    [rax]
        pop     rdx
        cmp     rax, rdx
        jnz     .a1      
        pop     rax
        jmp     .a2
.a1:
        pop     rdx
.a2:
	pop	r15
	pop	r14
	pop	r13
	pop	r12
        pop     r11
        pop     r10
        pop     r9
        pop     r8
        pop     rbp
        pop     rsi
        pop     rdi
        pop     rdx
        pop     rcx
        pop     rbx
        ret	
