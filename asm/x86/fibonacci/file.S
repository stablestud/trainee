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
	Fail:	 prints error message on screen and returns -1 or -2 (64 bit)
*/
.globl	fload

fload:
	/* open syscall */
	/* %rdi alreay set by function invocation */
	movl	$O_RDONLY,	%esi
	call	open
	cmpl	$-1,		%eax
	je	.Lopfailed

	/* mmap syscall */
	movq	%rax,		16(%rsp)	/* Save file descriptor to stack */
	movq	%rax,		%r8
	xorl	%edi,		%edi
	movl	$4096,		%esi
	movl	$PROT_READ,	%edx
	movq	$MAP_PRIVATE,	%r10
	xorq	%r9,		%r9
	call	mmap
	cmpl	$MAP_FAILED,	%eax
	je	.Lmmfailed
	ret

	/* open failed (-1) */	
.Lopfailed:
	movq	$-1,		%rax
	ret

	/* mmap failed (-2) */
.Lmmfailed:
	movq	$-2,		%rax
	ret
