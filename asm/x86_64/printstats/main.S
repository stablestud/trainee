#include <asm/unistd_64.h>

.data
file:	.asciz	"file.txt"

#define STAT	-64 - 64 - 64 - 32 - 32 - 32 - 32 - 64 - 64 - 64 - 64 - 64 - 64 - 64 - 64 - 64 - 64

.text
.globl	_start
_start:
	movq	STAT(%rsp),		%rsp
	

/* stat() syscall */
/* int stat(char *pathname, struct stat *statbuf)
	struct stat
		dev   - 64bit
		ino   - 64bit
		nlink - 64bit
		mode  - 32bit
		uid   - 32but
		gid   - 32bit		
		pad  - 32bit
		rdev  - 64bit
		size  - 64bit
		blksize - 64 bit
		blocks - 64bit - Number of 512-byte blocks allocated
		atime - 64bit
		atime_nsec - 64bit
		mtime - 64bit
		mtime_nsec - 64bit
		ctime - 64bit
		ctime_nsec - 64bit
 */
stat:
	movq	$__NR_stat,	%rax
