#include <asm/unistd_64.h> /* For syscalls macros */

#include "close.h"

/* close syscall

	%rdi - file descriptor to close

	Success: returns  0
	Fail:    returns -1
*/
.globl	close

close:
	movl	$__NR_close,	%eax
	syscall
	ret
