%include "colon.inc"
%include "words.inc"

%macro callf 1-4 0, 0, 0
	push	rdi
	push	rsi
	push	rdx
	mov	rdi,	%2
	mov	rsi,	%3
	mov	rdx,	%4
	call	%1
	pop	rdx
	pop	rsi
	pop	rdi
%endmacro

; from lib.asm
extern print_string
extern read_string
extern _exit

; from dict.asm
extern find_word

section .data
key:	db	"test",	0

section .bss
buffer:	resb 255

section .text

global _start
_start:
	callf	read_string,	buffer,	255
	callf	find_word,	buffer,	tost
	callf	_exit
