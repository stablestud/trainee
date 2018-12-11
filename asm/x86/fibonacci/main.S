/*	LOW-LEVEL-PROGRAMMING Chapter 4
	One number will be read from a file
	which goes through multiple equations
	- x^y factorial
	- 
	- sum of all numbers digits
	-
	- check if x is a fibonacci number
*/

#include <asm/unistd_64.h> /* For syscalls macros */

#include "mmap.h"
#include "open.h"
#include "close.h"

.data

f:	.asciz	"file.txt"


.text

.globl _start
_start:
	leaq	(f),		%rdi
	xorl	%esi,		%esi
	xorl	%edx,		%edx
	call	open

	movl	%eax,		%edi
	movl	$__NR_exit,	%eax		
	syscall
