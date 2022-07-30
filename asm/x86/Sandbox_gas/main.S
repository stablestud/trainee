/* GAS - AT&T Syntax */

#include <asm/unistd_64.h> /* For syscall macros */

.data

f:	.asciz	"file.txt"

.text

.globl _start
_start:
	xorq	%rax,		%rax
	xorq	%rdi,		%rdi
	xorq	%rcx,		%rcx
	xorq	%rsi,		%rsi
	xorq	%rdx,		%rdx
	xorq	%rbx,		%rbx
	xorq	%rbp,		%rbp
	xorq	%r8,		%r8
	xorq	%r9,		%r9
	xorq	%r10,		%r10
	xorq	%r11,		%r11
	xorq	%r12,		%r12
	xorq	%r13,		%r13
	xorq	%r14,		%r14
	xorq	%r15,		%r15

	leaq	(f),		%rdi
	//movq	$f,		%rdi

	/* open */
	movl	$__NR_open,	%eax
	syscall
	
	movq	%rax,		%rdi

	/* exit */
	movl	$__NR_exit,	%eax
	syscall
