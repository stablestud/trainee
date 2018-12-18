
#include <asm/unistd_64.h> /* For syscall macros */

#include "mmap.h"
#include "mmap.def"
#include "open.h"
#include "close.h"
#include "../lib/lib.h"

.data

pmf:	.asciz	"Enter file to open: "
pmc:	.asciz	"Factorial of number "
pmcc:	.asciz  " is "

amf:	.asciz	"Couldn't allocate heap.\n"
rpf:	.asciz	"Couldn't read path.\n"
opf:	.asciz	"Couldn't open file.\n"
mmf:	.asciz	"Couldn't mmap file.\n"
rif:	.asciz	"Couldn't read integer from file.\n"

um1:	.asciz	"Failed to unload heap memory.\n"
um2:	.ascii	"Failed to unload file from memory.\n"
clf:	.asciz	"Couldn't close file.\n"

.text

/* Fibonacci
	One number will be read from a file
	which goes through multiple expressions
	- x! (factorial, x! = 1 * 2 .... (x - 1) * x), it is guaranteed that x >= 0
	X output 0 if the input number is prime, 1 otherwise
	X sum of all number's digits
	X x-th fibonacci number
	X check if x is a fibonacci number
*/

.globl _start
_start:
	movq	%rsp,		%rbp
	/* Allocate memory to read file path into */
	xorl	%edi,		%edi
	movl	$1,		%esi
	movl	$PROT_WRITE | PROT_READ,	%edx
	movl	$MAP_ANON | MAP_PRIVATE,	%r10d
	xorl	%r8d,		%r8d
	xorl	%r9d,		%r9d
	call	mmap
	cmpl	$-1,		%eax
	jne	.Lpmf

	leaq	(amf),		%rdi
	jmp	.Lperror
.Lrpfailed:	/* Read file path failed */
	leaq	(rpf),		%rdi
	jmp	.Lperror
.Lflofailed:	/* Couldn't open file */
	leaq	(opf),		%rdi
	jmp	.Lperror
.Lflmfailed:	/* To map specified file failed */
	leaq	(mmf),		%rdi
	jmp	.Lperror
.Lrifailed:	/* To read an integer out of the memory failed */ 
	leaq	(rif),		%rdi
	jmp	.Lperror
.Lperror:
	call	print_string
	movl	$-1,		%edi
	call	_exit

.Lum1failed:
	leaq	(um1),		%rdi
	leaq	(.Lum1cont),	%rax
	jmp	.Lumperror
.Lum2failed:
	leaq	(um2),		%rdi
	leaq	(.Lum2cont),	%rax
	jmp	.Lumperror
.Lclfailed:
	leaq	(clf),		%rdi
	leaq	(.Lum2cont),	%rax
.Lumperror:
	push	%rax
	call	print_string
	pop	%rax
	jmp	*%rax


.Lpmf:
	pushq	%rax				// PUSH #1 starting address of heap (8B)
	/* Print message to user */
	leaq	(pmf),		%rdi
	call	print_string
	movq	(%rsp),		%rdi

.Lrdflpath:
	/* read file path from stdin */
	movq	$4095,		%rsi
	call	read_string
	testq	%rax,		%rax
	jz	.Lrpfailed

	/* open and map file to memory */
	xorl	%ecx,		%ecx
	pushq	%rcx				// PUSH #2 file descriptor of file (8B)
	movq	%rax,		%rdi
	call	fload
	cmpq	$-1,		%rax
	je	.Lflofailed
	cmpq	$-2,		%rax
	je	.Lflmfailed


	/* Convert string in file to integer */
	movq	%rax,		%rdi
	call	string_to_uint
	cmpq	$-1,		%rax
	je	.Lrifailed
	pushq	%rax				// PUSH #3 integer read from file (8B)

	/* Unload first mapping */
	movq	16(%rsp),	%rdi
	movq	$1,		%rsi
	call	munmap
	testl	%eax,		%eax
	jnz	.Lum1failed

	/* Unload file */
.Lum1cont:
	movq	16(%rsp),	%rdi
	movq	8(%rsp),	%rsi
	call	funload
	cmpq	$-1,		%rax
	je	.Lum2failed
	cmpq	$-2,		%rax
	je	.Lclfailed

	/* Calculate and print factorial result */
.Lum2cont:
	leaq	(pmc),		%rdi
	call	print_string
	movq	(%rsp),		%rdi
	call	print_uint
	leaq	(pmcc),		%rdi
	call	print_string
	movq	(%rsp),		%rdi
	call	factorial
	movq	%rax,		%rdi
	call	print_uint
	call	print_newline


	/* do something with integer */
call _exit
