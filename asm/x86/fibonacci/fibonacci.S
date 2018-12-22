#include "fibonacci.h"

/* fibo_xth, calculate the x-th fibonacci number

	%rdi - number

	Success: result of calculation
	Failure: can it fail?
*/
.globl fibo_xth

fibo_xth:
	xorl	%eax,		%eax
	movl	$1,		%esi
	testq	%rdi,		%rdi
	jz	.Llend
	cmpq	$1,		%rdi
	cmoveq	%rsi,		%rax
	je	.Llend
	movq	%rdi,		%rcx
.Lloop:
	movq	%rax,		%rdi
	addq	%rsi,		%rax
	movq	%rdi,		%rsi
	loop	.Lloop
.Llend:
	ret


/* fibo_check, check if %rdi is a fibonacci number

	%rdi - number which should be checked

	Success: 1 if fibonacci, 0 otherwise
	Failure: can it fail?
*/
.globl fibo_check

fibo_check:
	xorl	%eax,		%eax
	movl	$1,		%esi
	testq	%rdi,		%rdi
	jz	.Lyes
	cmpq	$1,		%rdi
	je	.Lyes
	movq	%rdi,		%rcx
.Lloop2:
	movq	%rax,		%rcx
	addq	%rsi,		%rax
	movq	%rcx,		%rsi
	cmpq	%rax,		%rdi
	ja	.Lloop2
	je	.Lyes
.Lno:
	xorl	%eax,		%eax
	ret
.Lyes:
	movl	$1,		%eax
	ret
