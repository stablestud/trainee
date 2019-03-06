
; -[string_equals]-
; Compares two strings, if equal return 1, if not 0
; takes:
;	rdi - address to first string
;	rsi - address to second string
; modifies:
;	rax, rdx, rdi, rsi, r8, r9
; returns:
;	rax - 1 if strings are equal, 0 if not

global	string_equals

string_equals:
	xor	rdx, rdx
	mov	r8, [rdi]
	mov	r9, [rsi]
.loop:
	cmp	r8b, r9b
	jne	.ret_false
	cmp	r8b, 0D
	je	.ret_true
	inc	rdx
	cmp	rdx, 8D
	jae	.fetch
	shr	r8, 8D
	shr	r9, 8D
	jmp	.loop
align 16
.fetch:
	lea	rdi, [rdi + 8D]
	lea	rsi, [rsi + 8D]
	mov	r8, [rdi]
	mov	r9, [rsi]
	xor	rdx, rdx
	jmp	.loop
align 16
.ret_true:
	mov	rax, 1D
	ret
align 16
.ret_false:
	xor	rax, rax
	ret
