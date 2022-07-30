#ifndef CLOSE_H
#define CLOSE_H

/* close syscall

	%rdi - file descriptor to close

	Success: returns  0
	Fail:    returns -1 (32 bit)
*/
.extern open

#endif /* CLOSE_H */
