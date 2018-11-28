#include "close.h"

/* close syscall

	%rdi - file descriptor to close

	Success: returns  0
	Fail:    returns -1
*/

close:
	movl	$__NR_close,	%eax
	syscall
	ret
