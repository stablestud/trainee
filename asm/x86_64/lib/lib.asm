section .text


; -[exit]-
; Terminates the program
; takes:
;       rdi - exit code of program
; edtis:
;       rax, rcx, r11
; returns:
;       nothing

global _exit

%define exit _exit

_exit:
        mov     eax, 60D
        syscall


; -[string_length]-
; Counts the length of a string till \0 sign
; takes:
;       rdi - address of string
; modifies:
;       rax
; returns:
;       rax - size of the string counted without \0 sign
; TODO: 
;	Improve speed by loading the string into reg

%define strlen string_length

string_length:
        xor     eax, eax
.loop:
        cmp     byte [rdi + rax], 0D
        jz      .ret
        inc     eax
        jmp     .loop
.ret:
        ret


; -[print_char]-
; Print a single character to stdout
; takes:
;       rdi - character to print
; modifies:
;       rax, rdx, rsi, rdi, rcx, r11
; returns:
;       nothing

%define putc print_char

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
;       rax, rdx, rsi, rdi, rcx, r11
; returns:
;       nothing

%define puts print_string

print_string:
        call    string_length
        lea     rsi, [rdi]
        mov     edi, 1D
        mov     rdx, rax 
        mov     eax, 1D
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

%define putln print_newline

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
.flush:
        or      r10, r9
        push    r10
        mov     rsi, 1D
        xor     r10, r10
        jmp     .loop
.fill:
        shl     byte sil, 1D
        jc     .print
        shl     r10, 8D
        jmp     .fill
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

%define getc read_char

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
;       rsi - number of characters to read from stdin        
; modifies:
;       rax, rdx, rdi, rsi, rcx, r11
; returns:
;       rax - returns buffer starting address
; TODO:
;	Change rsi holds the size of the buffer

%define gets read_string

read_string:
        mov     rdx, rsi
        lea     rsi, [rdi]
        xor     rax, rax
        xor     rdi, rdi
        syscall
        lea     rdi, [rsi + rax]
        mov     byte [rdi], 0D
        sub     rdi, 1D
        cmp     byte [rdi], 0x0A
        jnz      .ret
        mov     byte [rdi], 0D
.ret:
        lea     rax, [rsi]
        ret


; -[read_word]-
; Read a word of fixed size, stops reading at space, tab, newline character
; or term \0 sign, if the specified size is exceeded return 0
; takes:
;       rdi - buffer address to save the string to, requires one more space than
;             the size of the string for \0 sign
;       rsi - number of characters to read from stdin
; modifies:
;       rax, rdx, rdi, rsi, rcx, r8, r9, r10, r11
; returns:
;       rax - buffer starting address, or 0 if failed
; TODO: 
;	Improve speed by saving characters into qword reg and if full
;       then push to stack, change rsi holds the size of buffer

read_word:
        mov     r8, rdi
        mov     r9, rsi
.ignspace:
        call    read_char
        test    rax, rax
        jz      .ret_zero
        cmp     rax, 0x20
        jbe     .ignspace
        mov     rcx, r9
        xor     r10, r10
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
.ret:
        lea     rdx, [r8 + r10]
        mov     byte [rdx], 0D
        mov     rax, r8
        ret
.ret_zero:
        mov     rax, 0D
        ret


; -[string_to_uint]-
; parse a string containing a unsigned number to an unsigned integer
; takes:
;       rdi - string address to read from, must be terminated with \0
; modifies:
;       rax, rdx, rcx, rdi, rsi, r9, r10, r11
; returns:
;       rax - unsigned integer value
; TODO:
;	increase speed by reading qword into reg and evaluate rax from reg
;       instead from memory, make failsafe by checking if string
;       consists only out of digits abort if not,
;       do not get the string length instead check if character is valid

string_to_uint:
        call    string_length
	mov	rsi, rax
	test	rax, rax
	jz	.ret
        mov     rcx, rax
        xor     rax, rax
        xor     r9, r9
        mov     r10, 10D
.loop:
        mul     r10
        xor     r11, r11
        mov     r11b, [rdi]
        xor     r11, 0x30       ; how about and or xor?
        add     rax, r11
        lea     rdi, [rdi + 1]
        loop    .loop
.ret:
	mov	rdx, rsi
        ret


; -[string_to_int]-
; parse a string containing a signed number to an signed integer
; takes:
;       rdi - string address to read from, must be terminated with \0
; modifies:
;       rax, rcx, rdx, rsi, rdi, r8, r9, r10, r11
; returns:
;       rax - signed integer value

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
        jae     .flush
        shr     r8, 8D
        jmp     .loop
.flush:
        xor     r10, r10
        lea     rdi, [rdi + 8D]
        mov     qword r8, [rdi]
        jmp     .loop
.sav_neg:
        not     r9
        jmp     .pre_loop
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
.fetch:
	lea	rdi, [rdi + 8D]
	lea	rsi, [rsi + 8D]
	mov	r8, [rdi]
	mov	r9, [rsi]
	xor	rdx, rdx
	jmp	.loop
.ret_true:
	mov	rax, 1D
	ret
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
; 	rax, rcx, rsi, rdi, r9, r10, r8
; returns:
;	rax - buffers address if string can by copied, 0 otherwise

; rdi - address string
; rsi - address buffer
; rdx - max buffer length
; rax - string length
; r9  - temp storage of string
; r10 - temp storage of buffer
; r8  - temp temp buffer
; rcx - how many in current buffer, if equal of above 8 flush, else shr buffer 8D

string_copy:
	push	rbx
	mov	rbx, rsi

	mov	rax, 25D ;
	;call	string_length
        ;inc     rax
	;cmp	rax, rdx
	;ja	.ret_dnf
        mov     r9, [rdi]
	;cmp	rax, 8D
	;jb	.rest
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
.ret_dnf:
	xor	rax, rax
	pop	rbx
	ret


; -[calliso]-
; Call isolator, makes a call to the address pushed previously onto the stack
; takes:
;       Address to function, must be pushed to stack before calling
;       this function
; modifies:
;       rax - return value of called function, if modified by function
;       It resets other modification made by the function 
; returns:
;       rax - return value of called function, if modified by function

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
        push    rax
        mov     rax, rsp
        add     rax, 96D
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


global _start

msg0:	db	'This is a test string...', 0D

_start:
	mov	rcx, 0xFFFFFFF
	xor	rax, rax
	push	rax
	push	rax
	push	rax
	push	rsp
	mov	rdx, 32D
.loop:
	pop	rsi
	push	rsi
	mov	rdi, msg0
	push	rcx
	push	rdx
%ifdef OWN
	call	string_copy
%elifdef REF
	call	ref_string_copy
%else
	mod	rdi, 1D
	jmp	_exit
%endif
	pop	rdx
	pop	rcx
	loop	.loop

	mov	rdi, rax
	call	print_string
	xor	rdi, rdi
	jmp	_exit


; REFERENCE FUNCTIONS FOR PERFORMANCE TESTING

; ref_string_length
ref_string_length:
	xor rax, rax
.loop:
	cmp byte [rdi+rax], 0D
	je .end 
	inc rax
	jmp .loop 
.end:
	ret

; ref_string_copy
ref_string_copy:
	;push rdi
	;push rsi
	;push rdx
	;call string_length
	;pop rdx
	;pop rsi
	;pop rdi
	mov	rax, 25D ;

	;cmp rax, rdx
	;jae .too_long  ; we also need to store null-terminator

	push rsi 

	.loop: 
	mov dl, byte[rdi]
	mov byte[rsi], dl
	inc rdi
	inc rsi
	test dl, dl
	jnz .loop 

	pop rax 
	ret

	.too_long:
	xor rax, rax
	ret
