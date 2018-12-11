#ifndef FILE_H
#define FILE_H

/* Opens file specified, map it in memory

	%rdi - address of null terminated string containing file path 

	Success: return starting address of mapped file
	Fail:	 prints error message on screen and returns -1 (64 bit)
*/

.extern fload

#endif /* FILE_H */
