
; -[read_string]-
; Read a string of fixed maximum size from stdin, removes \n from the end
; takes:
;       rdi - buffer address to save the string to plus space for \0 sign
;       rsi - size of the buffer
; modifies:
;       rax, rdx, rdi, rsi, rcx, r11
; returns:
;       rax - returns buffer starting address

global	read_string

align 16
read_string:
        mov     rdx, rsi
	push	rdi
        lea     rsi, [rdi]
        xor     rax, rax
        xor     rdi, rdi
        syscall
        lea     rdi, [rsi + rax]
        mov     byte [rdi], 0D
        sub     rdi, 1D
        cmp     byte [rdi], 0x0A
        jnz     .ret
        mov     byte [rdi], 0D
.ret:
	pop	rdi
	mov	byte [rdi + rdx], 0D
        lea     rax, [rsi]
        ret
