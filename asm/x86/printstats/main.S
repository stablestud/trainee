#include <asm/unistd_64.h>

#include "stat.def"

.data
file:	.asciz	"file.txt"
op_f:	.asciz	"open()	failed ("
st_f:	.asciz	"stat()	failed ("
cl_f:	.asciz	"close() failed ("
mm_f:	.asciz	"mmap() failed ("
bracl:	.asciz	")\n"
semnl:	.asciz	":\n"
sdev:	.asciz	"Device:\t"
sino:	.asciz	"\nInode:\t"
snlink:	.asciz	"\nLinks:\t"
smode:	.asciz	"\nmode:\t"
suid:	.asciz	"\nuid:\t"
sgid:	.asciz	"\ngid:\t"
srdev:	.asciz	"\nrdev:\t"
ssize:	.asciz	"\nsize:\t"
sblksize:	.asciz	"\nblock size:\t"
sblocks:	.asciz	"\nblocks:\t"
satime:	.asciz	"\nAccess time in sec. since epoch:\t"
satime_nsec:	.asciz	"\nAccess time: nanoseconds:\t\t"
smtime:	.asciz	"\nModify time in sec. since epoch:\t"
smtime_nsec:	.asciz	"\nModify time: nanoseconds:\t\t"
sctime:	.asciz	"\nCreate time in sec. since epoch:\t"
sctime_nsec:	.asciz	"\nCreate time: nanoseconds:\t\t"
cont_m:	.asciz	"\nContent of file:\n"



.text
.globl	_start
_start:
	movq	%rsp,		%rbp
	lea	STAT(%rsp),	%rsp
	movq	$file,		%rdi
	movq	%rbp,		%rsi
	call	print_stat
	testq	%rax,		%rax
	jz	.Lend
	movq	%rax,		%rdi
	call	print_cont
.Lend:
	xorq	%rdi,		%rdi
	jmp	_exit
	
/*	Print file contents with open(), mmap() and close()
	rdi - file size retrieved from stat()
	rsi - pointer to file name	*/
print_cont:
	pushq	%rdi	/* File size */
	pushq	%rdi	/* File size */
	call	open
	push	%rax	/* File desc. */
	movq	$cont_m,	%rdi
	call	print_string
	pop	%r8	/* File desc. */
	pop	%rsi	/* File size */
	call	mmap
	movq	%rax,		%rsi    /* Address of string */
	movq	$1,		%rdi    /* File desciptor (stdout */
	movq	$__NR_write,	%rax    /* Syscall number */
	pop	%rdx	/* File size */
	syscall
	ret

mmap:
	movq	$__NR_mmap,	%rax    /* Syscall number */
	movq	$0,		%rdi    /* Address to map to */
	movq	$PROT_READ,	%rdx    /* Protection flags */
	movq	$MAP_PRIVATE,	%r10    /* Map flags */
        movq    $0,             %r9
	syscall
	cmpq	$0,		%rax
	jle	.Lmmap_fail
.Lmmap_ret:
	ret
.Lmmap_fail:
	cmpq	$-2,		%rax
	jl	.Lmmap_ret
	pushq	%rax
	movq	$mm_f,		%rdi
	call	print_string
	pop	%rdi
	call	print_int
	movq	$bracl,		%rdi
	call	print_string
	movq	$1,		%rdi
	jmp	_exit

open:
	movq	$__NR_open,	%rax
	movq	$file,		%rdi
	movq	$O_RDONLY,	%rsi
	syscall
	cmpq	$-1,		%rax
	jle	.Lopen_fail
	ret
.Lopen_fail:
	pushq	%rax
	movq	$op_f,		%rdi
	call	print_string
	pop	%rdi
	call	print_int
	movq	$bracl,		%rdi
	call	print_string
	movq	$1,		%rdi
	jmp	_exit

/*	Print file statistic with stat()
	rdi - pointer to struct
	rsi - pointer to file name	*/
print_stat:
	call	stat
	call	print_string
	movq	$semnl,		%rdi
	call	print_string
/*	print dev	64 bit	*/
.Lpstat_dev:
	movq	$sdev,		%rdi
	call	print_string
	movq	(%rbp),		%rdi
	call	print_uint
/*	print ino	64 bit	*/
.Lpstat_ino:
	movq	$sino,		%rdi
	call	print_string
	movq	8(%rbp),	%rdi
	call	print_uint
/*	print mode	32 bit	*/
.Lpstat_nlink:
	movq	$snlink,	%rdi
	call	print_string
	movl	16(%rbp),	%edi
	call	print_uint
/*	padding 32 bit __USE_LARGEFILE64 <bits/stat.h>	*/
/*	print link	32 bit	*/
.Lpstat_mode:
	movq	$smode,		%rdi
	call	print_string
	movl	24(%rbp),	%edi
	call	print_uint
/*	print uid	32 bit	*/
.Lpstat_uid:
	movq	$suid,		%rdi
	call	print_string
	movl	28(%rbp),	%edi
	call	print_uint
/*	print gid	32 bit	*/
.Lpstat_gid:
	movq	$sgid,		%rdi
	call	print_string
	movl	32(%rbp),	%edi
	call	print_uint
/*	print rdev	64 bit	*/
.Lpstat_rdev:
	movq	$srdev,		%rdi
	call	print_string
	movq	40(%rbp),	%rdi
	call	print_uint
/*	print size	64 bit	*/
.Lpstat_size:
	movq	$ssize,		%rdi
	call	print_string
	movq	48(%rbp),	%rdi
	movq	%rdi,		%r15
	call	print_uint
/*	print block size 64 bit	*/
.Lpstat_blksize:
	movq	$sblksize,	%rdi
	call	print_string
	movq	56(%rbp),	%rdi
	call	print_uint
/*	print block count 64 bit	*/
.Lpstat_blocks:
	movq	$sblocks,	%rdi
	call	print_string
	movq	64(%rbp),	%rdi
	call	print_uint
/*	print atime 64 bit	*/
.Lpstat_atime:
	movq	$satime,	%rdi
	call	print_string
	movq	72(%rbp),	%rdi
	call	print_uint
/*	print atime_nsec 64 bit */
.Lpstat_atime_nsec:
	movq	$satime_nsec,	%rdi
	call	print_string
	movq	80(%rbp),	%rdi
	call	print_uint
/*	print mtime 64 bit	*/
.Lpstat_mtime:
	movq	$smtime,	%rdi
	call	print_string
	movq	88(%rbp),	%rdi
	call	print_uint
/*	print mtime_nsec 64 bit */
.Lpstat_mtime_nsec:
	movq	$smtime_nsec,	%rdi
	call	print_string
	movq	96(%rbp),	%rdi
	call	print_uint
/*	print ctime 64 bit	*/
.Lpstat_ctime:
	movq	$sctime,	%rdi
	call	print_string
	movq	104(%rbp),	%rdi
	call	print_uint
/*	print ctime_nsec 64 bit */
.Lpstat_ctime_nsec:
	movq	$sctime_nsec,	%rdi
	call	print_string
	movq	112(%rbp),	%rdi
	call	print_uint
.Lpstat_end:
	call	print_newline
	movq	%r15,		%rax
	ret

stat:
	movq	$__NR_stat,	%rax
	syscall
	cmpl	$-1,		%eax
	jle	.Lstat_f
	ret
.Lstat_f:
	pushq	%rax
	movq	$st_f,		%rdi
	call	print_string
	pop	%rdi
	call	print_int
	movq	$bracl,		%rdi
	call	print_string
	movq	$1,		%rdi
	jmp	_exit
