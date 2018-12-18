#include <asm/unistd_64.h> /* For syscalls macros */

#include "mmap.h"
#include "mmap.def"

.text

/* mmap syscall

	%rdi - starting address from where len memory should be mapped (0 to let system decide)
	%rsi - amount of bytes which should be mapped (aligned to 4096 boundary (2^12))
	%rdx - page's protection flag(s) (defined in <sys/mman.h>
	%r10 - how page's content should be handled (defined in <sys/mman.h>
	%r9  - file descriptor acquired previously from open()
	%r8  - offset in bytes in the file

	Success: returns beginning address of mapped memory
	Fail:    returns MAP_FAILED (defined in <sys/mman.h>) (32 bit)
*/
.globl	mmap

mmap:
	movl	$__NR_mmap,	%eax	/* Syscall number */
	syscall
	cmpl	$-4096,		%eax
	ja	.Lmmfailed
	ret
.Lmmfailed:
	movl	$MAP_FAILED,	%eax
	ret


/* munmap syscall

	%rdi - address which should be unmapped, unmaps only complete pages
	%rsi - amount of bytes from starting address which should be unmapped

	Success: returns 0
	Failure: returns -1
*/
.globl munmap

munmap:
	movl	$__NR_munmap,	%eax	/* Syscall number */
	syscall
	testl	%eax,		%eax
	jnz	.Lumfailed
	ret
.Lumfailed:
	movl	$-1,		%eax
	ret
