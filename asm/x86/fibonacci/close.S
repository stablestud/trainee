#include <asm/unistd_64.h> /* For syscalls macros */

#include "close.h"

.text

/* close syscall

	%rdi - file descriptor to close

	Success: returns  0
	Fail:    returns -1 (32 bit)
*/
.globl	close

close:
	movl	$__NR_close,	%eax
	syscall
	cmpl	$-4096,		%eax
	ja	.Lclfailed
	ret
.Lclfailed:
	movl	$-1,		%eax
	ret
