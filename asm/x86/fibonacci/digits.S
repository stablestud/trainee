#include "digits.h"

/* Calculate the sum of all digits
	
	%rdi - unsigned number to be considered

	Success: sum of numbers digits
	Failure: can if fail?
 */
.globl digits

digits:
	xorl	%ecx,		%ecx
	testq	%rdi,		%rdi
	jz	.Lresult
	movl	$10,		%esi
	movq	%rdi,		%rax
.Lloop:
	xorl	%edx,		%edx
	divq	%rsi
	addq	%rdx,		%rcx
	test	%rax,		%rax
	jz	.Lresult
	jmp	.Lloop
.Lresult:
	movq	%rcx,		%rax
	ret
