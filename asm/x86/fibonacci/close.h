#ifndef CLOSE_H
#define CLOSE_H

#include <asm/unistd_64.h> /* For syscalls macros */


/* close syscall

	%rdi - file descriptor to close

	Success: returns  0
	Fail:    returns -1
*/

.extern open

#endif /* CLOSE_H */
