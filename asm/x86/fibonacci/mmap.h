#ifndef MMAP_H
#define MMAP_H

/* mmap syscall

	%rdi - starting address from where len memory should be mapped (0 to let system decide)
	%rsi - amount of bytes which should be mapped (aligned to 4096 boundary (2^12))
	%rdx - page's protection flag(s) (defined in <sys/mman.h>
	%r10 - how page's content should be handled (defined in <sys/mman.h>
	%r9  - file descriptor acquired previously from open()
	%r8  - offset in bytes in the file

	Success: returns beginning address of mapped memory
	Fail:    returns MAP_FAILED (def in <sys/mman.h>)
*/

.extern mmap

#endif /* MMAP_H */
