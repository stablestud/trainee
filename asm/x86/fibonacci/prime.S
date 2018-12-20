#include "prime.h"

.text

/*	Calculate if %rdi contains a prime or not

	%rdi - number

	Success: 0 if number is prime, 1 if not
	Failure: can it fail?
*/
.globl prime

prime:
	cmpq	$3,		%rdi	// %rdi - contains number
	jbe	.Lisprime
	movl	$1,		%eax
	and	%rdi,		%rax
	jz	.Lisnprime
	movq	%rdi,		%rax
	movl	$2,		%ecx
	xorl	%edx,		%edx
	divq	%rcx
	movq	%rax,		%rsi	// %rsi - holds max divisor
	movl	$3,		%ecx	// %rcx - holds current divisor
.Lloop:
	movq	%rdi,		%rax
	xorl	%edx,		%edx
	divq	%rcx
	testq	%rdx,		%rdx
	jz	.Lisnprime
	addq	$2,		%rcx
	cmpq	%rcx,		%rsi
	jae	.Lloop
	jmp	.Lisprime
.Lisprime:
	xorl	%eax,		%eax
	ret
.Lisnprime:
	movl	$1,		%eax
	ret
