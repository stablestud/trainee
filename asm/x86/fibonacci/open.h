#ifndef OPEN_H
#define OPEN_H

/* open syscall

	%rdi - address of zero terminated string containing the path to the file to be opened
	%rsi - open flags (defined in <fcntl.h>
	%rdx - extended use of flags

	Success: returns file descriptor of opened file
	Fail:    returns -1 (32 bit)
*/
.extern open

#endif /* OPEN_H */
