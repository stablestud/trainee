
#include <asm/unistd_64.h> /* For syscall macros */

#include "mmap.h"
#include "open.h"
#include "close.h"

.data

rpf:	.asciz	"Couldn't read path.\n"
opf:	.asciz	"Couldn't open file.\n"
mmf:	.asciz	"Couldn't mmap file.\n"

.text

/*	fibonacci
	One number will be read from a file
	which goes through multiple equations
	- x^y factorial
	- 
	- sum of all numbers digits
	-
	- check if x is a fibonacci number
*/

.globl _start
_start:
	/* read file path */
	movq	80(%rsp),	%rsp
	movq	%rsp,		%rdi
	movq	$80,		%rsi
	call	read_string
	testq	%rax,		%rax
	jz	.Lrpfailed

	/* open and map file to memory */
	movq	%rax,		%rdi
	call	fload
	cmpq	$-1,		%rax
	je	.Lflofailed
	cmpq	$-2,		%rax
	je	.Lflmfailed
call	_exit
.Lrpfailed:	/* Read file path failed */
	leaq	(rpf),		%rdi
	jmp	.Lperror
.Lflofailed:	/* Couldn't open file */
	leaq	(opf),		%rdi
	jmp	.Lperror
.Lflmfailed:	/* To map specified file failed */
	leaq	(mmf),		%rdi
	jmp	.Lperror
.Lperror:
	call	print_string
	movl	$-1,		%edi
	call	_exit
