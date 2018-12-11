#include <asm/unistd_64.h> /* For syscall macros */

#include "open.h"

.text

/* Open syscall

	%rdi - address of zero terminated string containing the path to the file to be opened
	%rsi - open flags (defined in <fcntl.h>
	%rdx - extended use of flags

	Success: returns file descriptor of opened file
	Fail:    returns -1 (32 bit)
*/
.globl	open

open:
	movl	$__NR_open,	%eax
	syscall
	cmpl	$-4096,		%eax
	ja	.Lopfailed
	ret
.Lopfailed:
	movl	$-1,		%eax
	ret
