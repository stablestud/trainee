section .text

; -[exit]-
; Terminates the program
; takes:
;       rdi - exit code of program
; edtis:
;       rax, rcx, r11
; returns:
;       nothing

global	_exit
%define exit	_exit

align 16
_exit:
        mov     eax, 60D
        syscall


; -[string_length]-
; Counts the length of a string till \0 sign
; takes:
;       rdi - address of string
; modifies:
;       rax, r8, r9, r10, r11
; returns:
;       rax - size of the string counted excluding \0 sign

global	string_length
%define	strlen	string_length

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


; -[print_char]-
; Print a single character to stdout
; takes:
;       rdi - character to print
; modifies:
;       rax, rdx, rsi, rdi, rcx, r11
; returns:
;       nothing

global	print_char
%define putc print_char
%define printc print_char

align 16
print_char:
        mov     eax, 1D
        push    rdi
        lea     rsi, [rsp]
        mov     edi, 1D
        mov     edx, 1D
        syscall
        pop     rdi
        ret


; -[print_string]-
; Print a sequence of character to stdout
; takes:
;       rdi - address of string
; modifies:
;       rax, rcx, rdx, rdi, rsi, r8, r9, r10, r11
; returns:
;       nothing

global	print_string
%define puts	print_string
%define prints	print_string

align 16
print_string:
        call    string_length
        lea     rsi, [rdi]
        mov     edi, 1D
        mov     rdx, rax 
        mov     rax, 1D
        syscall
        ret


; -[print_newline]-
; Print the newline (0x0A / \n ) character to stdout
; takes:
;       nothing
; modifies:
;       rax, rdx, rdi, rsi, rcx, r11
; returns:
;       nothing

global	print_newline
%define putln	print_newline
%define println	print_newline

align 16
print_newline:
        mov     eax, 1D
        mov     edx, 1D
        mov     edi, 1D
        push    0x0A
        lea     rsi, [rsp]
        syscall
        pop     rdi
        ret


; -[print_uint]-
; Print unsigned integer in decimal base to stdout
; takes:
;       rdi - unsigned integer to be printed
; modifies:
;       rax, rdx, rcx, rsi, rdi, r9, r10, r11
; returns:
;       nothing

global	print_uint
%define printu	print_uint
%define printui	print_uint

align 16
print_uint:
        push    rbx
        mov     rbx, rsp
        mov     rax, rdi                        ; load quadword value to convert
        mov     rsi, 1D                         ; count char stored in r10
        xor     rcx, rcx                        ; count characters to print
        mov     r9,  0x30_30_30_30__30_30_30_30 ; converting bytes to ASCII
        xor     r10, r10                        ; temp storage for 8 characters
        mov     r11, 10D                        ; division
.loop:
        shl     r10, 8D
        xor     rdx, rdx
        div     r11
        or      byte r10b, dl
        inc     rcx
        test    rax, rax
        jz      .fill
        shl     byte sil, 1D
        jc      .flush
        jmp     .loop
align 16
.flush:
        or      r10, r9
        push    r10
        mov     rsi, 1D
        xor     r10, r10
        jmp     .loop
align 16
.fill:
        shl     byte sil, 1D
        jc      .print
        shl     r10, 8D
        jmp     .fill
align 16
.print:
        or      r10, r9
        push    r10
        mov     rax, 1D
        mov     rdx, rcx
        mov     rdi, 1D
        lea     rsi, [rbx]
        sub     rsi, rdx
        syscall
        lea     rsp, [rbx]
        pop     rbx
        ret
        

; -[print_int]-
; Print signed integer in decimal base to stdout
; takes:
;       rdi - signed integer to be printed
; modifies:
;       rax, rdx, rcx, rsi, rdi, r9, r11
; returns:
;       nothing

global	print_int
%define printi print_int

align 16
print_int:
        push    rbx
        mov     rbx, rsp
        mov     rax, rdi                        ; load quadword value to convert
        mov     r11, 10D                        ; division
        test    rax, rax
        jns     .loop
        neg     rax
.loop:
        xor     rdx, rdx
        idiv    r11
        or      dl, 0x30
        dec     rbx
        mov     byte [rbx], dl
        test    rax, rax
        jnz     .loop
.sign:
        test    rdi, rdi
        jns     .print
        dec     rbx
        mov     byte [rbx], 0x2D
.print:
        mov     rax, rsp
        sub     rax, rbx
        mov     rdx, rax
        mov     rax, 1D
        mov     rdi, 1D
        lea     rsi, [rbx]
        syscall
        pop     rbx
        ret
        

; -[read_char]-
; Read one character from stdin
; takes:
;       nothing
; modifies:
;       rax, rdx, rsi, rdi, rcx, r11
; returns:
;       rax - character read from stdin

global	read_char
%define getc read_char

align 16
read_char:
        xor     rax, rax
        xor     rdi, rdi
        mov     rdx, 1D
        push    rax
        mov     rsi, rsp
        syscall
        pop     rax
        ret


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
%define gets read_string

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
%define getw read_word

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
%define parse_uint string_to_uint

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


; -[string_to_int]-
; parse a string containing a signed number to an signed integer
; takes:
;       rdi - string address to read from, string must be terminated with \0
; modifies:
;       rax, rcx, rdx, rsi, rdi, r8, r9, r10, r11
; returns:
;       rax - signed integer value, -1 on failure
;	rdx - number of characters processed

global	string_to_int
%define parse_int string_to_int

align 16
string_to_int:
        xor     r9, r9
        xor     rax, rax
	xor	rcx, rcx
        mov     qword r8, [rdi]
        cmp     byte r8b, 0x2D                  ; is negative (-)?
        jz      .sav_neg
        cmp     byte r8b, 0x30                  ; check whether character is valid
        jb      .abort
        cmp     byte r8b, 0x39
        ja      .abort
        xor     byte r8b, 0x30
        add     byte al, r8b
.pre_loop:
        mov     r10, 1D
        mov     r11, 10D
        xor     rsi, rsi
        shr     r8, 8D
	inc	rcx
.loop:
        cmp     r8b, 0x30                       ; check whether character is valid
        jb      .app_neg
        cmp     r8b, 0x39
        ja      .app_neg
        mul     r11
        xor     byte r8b, 0x30
        mov     byte sil, r8b
        add     rax, rsi
	inc	rcx
        inc     r10
        cmp     r10, 8D
        jae     .fetch
        shr     r8, 8D
        jmp     .loop
align 16
.fetch:
        xor     r10, r10
        lea     rdi, [rdi + 8D]
        mov     qword r8, [rdi]
        jmp     .loop
align 16
.sav_neg:
        not     r9
        jmp     .pre_loop
align 16
.app_neg:
        test    r9, r9
        jns     .ret
        neg     rax
        js      .ret
        jz      .ret
        dec     rax
.ret:
	mov	rdx, rcx
        ret
align 16
.abort:
        mov     rax, -1D
	mov	rdx, rcx
        ret
        

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
%define strcmp string_equals

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


; -[string_copy]-
; Copies string to destination
; takes:
;	rdi - address of string
;	rsi - address of buffer (destination)
;	rdx - length of buffer
; modifies:
; 	rax, rcx, rsi, rdi, r8, r9, r10, r11
; returns:
;	rax - buffers address if string can by copied, 0 otherwise

global	string_copy
%define strncpy string_copy

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
