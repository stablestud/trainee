#include "factorial.h"

.text 

/* calculate the factorial of a number

	%rdi - integer from which the factorial should be calculated, number must be >= 0

	Success: returns result of factorization
	Failure: I don't think it can fail
*/
.globl factorial

factorial:
	xorl	%eax,		%eax
	xorl	%ecx,		%ecx
	movl	$1,		%esi
	test	%rdi,		%rdi
	jz	.Lend
	movl	$1,		%eax
.Loop:
	cmpq	%rdi,		%rsi
	ja	.Lend
	mulq	%rsi
	incq	%rsi
	jmp	.Loop
.Lend:
	ret
