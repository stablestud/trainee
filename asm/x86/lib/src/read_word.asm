
; -[read_word]-
; Read a word of fixed size, stops reading at space, tab, newline character
; or term \0 sign, if the specified size is exceeded return 0
; takes:
;       rdi - buffer address to save the string to, requires one more space than
;             the size of the string for \0 sign
;       rsi - size of buffer
; modifies:
;       rax, rdx, rdi, rsi, rcx, r8, r9, r10, r11
; returns:
;       rax - buffer starting address, or 0 if failed

global	read_word

align 16
read_word:
	sub	rsi, 1D
        mov     r8, rdi
        mov     r9, rsi
        xor     r10, r10
.ignspace:
        call    read_char
        test    rax, rax
        jz      .ret_zero
        cmp     rax, 0x20
        jbe     .ignspace
.loop:
        lea     rdx, [r8 + r10]
        mov     byte [rdx], al
        call    read_char
        inc     r10
        cmp     rax, 0x20
        jbe     .ret
        cmp     r10, r9
        jnz     .loop
        jmp     .ret_zero
align 16
.ret:
        lea     rdx, [r8 + r10]
        mov     byte [rdx], 0D
        mov     rax, r8
	mov	rdx, r10
	inc	r9
	mov	byte [r8 + r9], 0D
        ret
align 16
.ret_zero:
        mov     rax, 0D
	mov	rdx, r10
        ret
