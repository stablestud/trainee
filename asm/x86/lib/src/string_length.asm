
; -[string_length]-
; Counts the length of a string till \0 sign
; takes:
;       rdi - address of string
; modifies:
;       rax, r8, r9, r10, r11
; returns:
;       rax - size of the string counted excluding \0 sign

global	string_length

align 16
string_length:
	mov	rax, rdi
	mov	r10, 0x80_80_80_80__80_80_80_80
	mov	r11, 0xFE_FE_FE_FE__FE_FE_FE_FF
.loop_align:
	test	al, 7D
	jz	.cmp
	cmp	byte [rax], 0D
	je	.ret_align
	add	rax, 1D
	jmp	.loop_align
align 16
.loop:
	lea	rax, [rax + 8D]
.cmp:
	mov	r9, [rax]
	lea	r8, [r9 + r11]
	not	r9
	and	r9, r8
	and	r9, r10
	jz	.loop
	sub	rax, rdi
	test	byte r9b, r9b
	jnz	.R0
	shr	r9, 8D
	test	byte r9b, r9b
	jnz	.R1
	shr	r9, 8D
	test	byte r9b, r9b
	jnz	.R2
	shr	r9, 8D
	test	byte r9b, r9b
	jnz	.R3
	shr	r9, 8D
	test	byte r9b, r9b
	jnz	.R4
	shr	r9, 8D
	test	byte r9b, r9b
	jnz	.R5
	shr	r9, 8D
	test	byte r9b, r9b
	jnz	.R6
	add	rax, 7D
.R0:
	ret
.R1:
	add	rax, 1D
	ret
.R2:
	add	rax, 2D
	ret
.R3:
	add	rax, 3D
	ret
.R4:
	add	rax, 4D
	ret
.R5:
	add	rax, 5D
	ret
.R6:
	add	rax, 6D
	ret
.ret_align:
	sub	rax, rdi
	ret
