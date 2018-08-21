section .text


; -[exit]-
; Terminates the program
; takes:
;       rdi - exit code of program
; edtis:
;       rax, rcx, r11
; returns:
;       nothing

%define exit _exit
global _exit

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
; TODO: Improve speed by loading the string into reg

string_length:
        xor     rax, rax
.loop:
        cmp     byte [rdi + rax], 0D
        jz      .ret
        inc     rax
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
; TODO: Change rsi holds the size of the buffer

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
; TODO: Improve speed by saving characters into qword reg and if full
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
; TODO: increase speed by reading qword into reg and evaluate rax from reg
;       instead from memory, make failsafe by checking if string
;       consists only out of digits abort if not,
;       do not get the string length instead check if character is valid

string_to_uint:
        call    string_length
        mov     rcx, rax
        xor     rax, rax
        xor     r9, r9
        mov     r10, 10D
.loop:
        lea     rsi, [rdi + r9] ; lea rsi, [rsi + 1] is better
        mul     r10
        xor     r11, r11
        mov     r11b, [rsi]
        sub     r11, 0x30       ; how about and or xor?
        add     rax, r11
        inc     r9
        loop    .loop
        ret


; -[string_to_int]-
; parse a string containing a signed number to an signed integer
; takes:
;       rdi - string address to read from, must be terminated with \0
; modifies:
;       rax
; returns:
;       rax - signed integer value

string_to_int:
        xor     r9, r9
        xor     rax, rax
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
.loop:
        cmp     r8b, 0x30                       ; check whether character is valid
        jb      .app_neg
        cmp     r8b, 0x39
        ja      .app_neg
        mul     r11
        xor     byte r8b, 0x30
        mov     byte sil, r8b
        add     rax, rsi
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
        ret
.abort:
        mov     rax, -1D
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
; 	rax
; returns:
;	rax - buffers address if string can by copied, 0 otherwise

string_copy:
	; Determine length of the string, evaluate if it can be copied
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

msg1:	db 'Password', 0D
msg2:	db 'Password', 0D

_start:
	mov	rdi, msg1
	mov	rsi, msg2
	call	string_equals
	mov	rdi, rax
	call	print_uint
	xor	rdi, rdi
	call	exit
