#ifndef FILE_H
#define FILE_H

/* Opens file specified, map it in memory

	%rdi - address of null terminated string containing file path 

	Success: return starting address of mapped file
	Failure: prints error message on screen and returns -1 (64 bit)
*/
.extern fload

/* Unmaps file and close file decriptor
	
	%rdi - address to mapped memory
	%rsi - file descriptor to close

	Success: return zero
	Failure: prints error message and return -1 or -2 (64bit)
*/
.extern funload

#endif /* FILE_H */
