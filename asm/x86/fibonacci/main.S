
#include <asm/unistd_64.h> /* For syscall macros */

#include "mmap.h"
#include "mmap.def"
#include "open.h"
#include "close.h"
#include "../lib/lib.h"

.data

amf:	.asciz	"Couldn't allocate heap.\n"
rpf:	.asciz	"Couldn't read path.\n"
opf:	.asciz	"Couldn't open file.\n"
mmf:	.asciz	"Couldn't mmap file.\n"
rif:	.asciz	"Couldn't read integer from file.\n"

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
	jne	.Lrdflpath
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
.Lrifailed:
	leaq	(rif),		%rdi
	jmp	.Lperror
.Lperror:
	call	print_string
	movl	$-1,		%edi
	call	_exit

.Lrdflpath:
	pushq	%rax				// PUSH #1 starting address of heap (8B)
	/* read file path from stdin */
	movq	%rax,		%rdi
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

// unload mapping if not needed with munmap

	/* do something with integer */
call _exit
