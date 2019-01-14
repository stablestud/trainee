
; -[string_to_uint]-
; parse a string containing a unsigned number to an unsigned integer
; takes:
;       rdi - string address to read from, string must be terminated with \0
; modifies:
;       rax, rdx, rcx, rdi, r9, r10, r11
; returns:
;       rax - unsigned integer value, -1 on failure
;	rdx - number of characters processed

global	string_to_uint

align 16
string_to_uint:
        xor     rax, rax
	xor	r9, r9
	mov	r8, [rdi]
        cmp     byte r8b, 0x30                  ; check whether character is valid
        jb      .abort
        cmp     byte r8b, 0x39
        ja      .abort
        xor     r8b, 0x30
	add	al, r8b
	add	r9, 1D				; counter of how many characters read
        mov     r10, 10D
	mov	r11, 1D
	shr	r8, 8D
	jmp	.loop
align 16
.fetch:
	xor	r11, r11
	lea	rdi, [rdi + 8D]
	mov	r8, [rdi]
.loop:
        cmp     byte r8b, 0x30                  ; check whether character is valid
        jb      .ret
        cmp     byte r8b, 0x39
        ja      .ret
        mul     r10
        xor     r8b, 0x30
	add	al, r8b
	add	r9, 1D
	add	r11, 1D
	cmp	r11, 8D
	jae	.fetch
	shr	r8, 8D
        loop    .loop
.ret:
	mov	rdx, r9
        ret
align 16
.abort:
        mov     rax, -1D
	mov	rdx, r9
        ret
