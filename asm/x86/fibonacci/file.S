/* Handle file opening, mapping and closing */

#include "open.h"
#include "open.def"
#include "mmap.h"
#include "mmap.def"
#include "close.h"

.text

/* Opens file specified, map it in memory

	%rdi - address of null terminated string containing file path 

	Success: return starting address of mapped file
	Fail:	 prints error message on screen and returns -1 (64 bit)
*/
.globl	fload

fload:
	/* open syscall */
	/* %rdi alreay set by function invocation */
	movl	$O_RDONLY,	%esi
	call	open
	cmpl	$-1,		%eax
	jle	.Lfailo
	/* mmap syscall */
	movq	%rax,		%r9
	xorl	%edi,		%edi
	movl	$1,		%esi
	movl	$PROT_READ,	%edx
	movq	$MAP_PRIVATE,	%r10
	xorq	%r8,		%r8
	call	mmap
	cmpl	$MAP_FAILED,	%eax
	je	.Lfailm
	ret
/* open failed */	
.Lfailo:
/* mmap failed */
.Lfailm:

