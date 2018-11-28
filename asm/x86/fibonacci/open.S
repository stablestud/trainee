#include "open.h"

/* Open syscall

	%rdi - zero terminated string containing the path to the file to be opened
	%rsi - open flags (defined in <fcntl.h>
	%rdx - extended use of flags

	Success: returns file descriptor of opened file
	Fail:    returns -1
*/

open:
	movl	$__NR_open,	%eax
	syscall
	ret
