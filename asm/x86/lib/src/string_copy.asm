
; -[string_copy]-
; Copies string to destination
; takes:
;	rdi - address of string
;	rsi - address of buffer (destination)
;	rdx - length of buffer
; modifies:
; 	rax, rcx, rsi, rdi, r9, r10, r8
; returns:
;	rax - buffers address if string was by copied, 0 otherwise

global	string_copy

align 16
string_copy:
	push	rbx
	mov	rbx, rsi
	call	string_length
        inc     rax
	cmp	rax, rdx
	ja	.ret_dnf
        mov     r9, [rdi]
	cmp	rax, 8D
	jb	.rest
.loop:
        test    rax, rax
        jz      .ret
	cmp	rax, 8D
	jb	.rest
	mov	[rsi], r9
	lea	rdi, [rdi + 8D]
	lea	rsi, [rsi + 8D]
	sub	rax, 8D
        mov     r9, [rdi]
	jmp	.loop
align 16
.rest:
	xor	r10, r10
	mov	r10b, r9b
        mov     rcx, 8D
	test	r9b, r9b
	jz	.ret_rest
.loop_rest:
	shr	r9, 8D
        xor     r8, r8
	mov	r8b, r9b
        shl     r8, cl
        or      r10, r8
        add     rcx, 8D
	test	r9b, r9b
	jz	.ret_rest
	jmp	.loop_rest
align 16
.ret_rest:
        mov     rax, -1D
        shl     rax, cl
        and     rax, [rsi]
        or      r10, rax
	mov	[rsi], r10
.ret:
	mov	rax, rbx
	pop	rbx
	ret
align 16
.ret_dnf:
	xor	rax, rax
	pop	rbx
	ret
