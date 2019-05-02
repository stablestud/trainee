#include <asm/unistd_64.h> /* For syscall macros */

#include "../lib/src/lib.S"
#include "file.h"
#include "mmap.h"
#include "mmap.def"
#include "prime.h"
#include "digits.h"
#include "factorial.h"
#include "fibonacci.h"

.data

pmf:	.asciz	"Enter file to open: "
pmc:	.asciz	"Factorial of number "
pmcc:	.asciz  " is "
pmp:	.asciz	"a prime number\n"
pmnp:	.asciz	"not "
pms:	.asciz	"Sum of all digits is "
pmx1:	.asciz	"The "
pmx2:	.asciz	"th fibonacci number is "
pmcf:	.asciz	"a fibonacci number\n"

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
	- output 0 if the input number is prime, 1 otherwise
	- sum of all number's digits
	- x-th fibonacci number
	- check if x is a fibonacci number
*/

.globl _start
_start:
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


	/* Print message to user */
.Lpmf:
	pushq	%rax				// PUSH #1 starting address of heap (8b)
	leaq	(pmf),		%rdi
	call	print_string
	movq	(%rsp),		%rdi

	/* Read file path from stdin */
.Lrdflpath:
	movq	$4095,		%rsi
	call	read_string
	testq	%rax,		%rax
	jz	.Lrpfailed

	/* Open and map file to memory */
	xorl	%ecx,		%ecx
	pushq	%rcx				// PUSH #2 file descriptor of file (8b)
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
	pushq	%rax				// PUSH #3 integer read from file (8b)

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

	/* Calculate and print if number is a prime number */
	movq	(%rsp),		%rdi
	call	print_uint
	leaq	(pmcc),		%rdi
	call	print_string
	movq	(%rsp),		%rdi
	call	prime
	testl	%eax,		%eax
	jz	.Lpprime
	leaq	(pmnp),		%rdi
	call	print_string
.Lpprime:
	leaq	(pmp),		%rdi
	call	print_string

	/* Calculate the sum of numbers digits */
	leaq	(pms),		%rdi
	call	print_string
	movq	(%rsp),		%rdi
	call	digits
	movq	%rax,		%rdi
	call	print_uint
	call	print_newline

	/* Calculate x-th fibonacci number */
	leaq	(pmx1),		%rdi
	call	print_string
	movq	(%rsp),		%rdi
	call	print_uint
	leaq	(pmx2),		%rdi
	call	print_string
	movq	(%rsp),		%rdi
	call	fibo_xth
	movq	%rax,		%rdi
	call	print_uint
	call	print_newline

	/* Check if number is a fibonacci number */
	movq	(%rsp),		%rdi
	call	print_uint
	leaq	(pmcc),		%rdi
	call	print_string
	movq	(%rsp),		%rdi
	call	fibo_check
	testl	%eax,		%eax
	jnz	.Lpfibo
	leaq	(pmnp),		%rdi
	call	print_string
.Lpfibo:
	leaq	(pmcf),		%rdi
	call	print_string
	
	/* Terminate program */
	xorl	%edi,		%edi
	call _exit
