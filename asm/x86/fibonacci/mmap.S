#include <asm/unistd_64.h> /* For syscalls macros */

#include "mmap.h"

.text

/* mmap syscall

	%rdi - starting address from where len memory should be mapped (0 to let system decide)
	%rsi - amount of bytes which should be mapped (aligned to 4096 boundary (2^12))
	%rdx - page's protection flag(s) (defined in <sys/mman.h>
	%r10 - how page's content should be handled (defined in <sys/mman.h>
	%r9  - file descriptor acquired previously from open()
	%r8  - offset in bytes in the file

	Success: returns beginning address of mapped memory
	Fail:    returns MAP_FAILED (defined in <sys/mman.h>)
*/
.globl	mmap

mmap:
	movl	$__NR_mmap,	%eax	/* Syscall number */
	syscall
	ret
