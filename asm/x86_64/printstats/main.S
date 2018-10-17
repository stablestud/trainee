#include <asm/unistd_64.h>

#include "stat.def"

.data
file:	.asciz	"file.txt"
op_f:	.asciz	"open()	failed ("
st_f:	.asciz	"stat()	failed ("
cl_f:	.asciz	"close() failed ("
bracl:	.asciz	")\n"
semnl:	.asciz	":\n"
sdev:	.asciz	"dev: "
sino:	.asciz	"\nino: "
snlink:	.asciz	"\nnlink: "
smode:	.asciz	"\nmode: "
suid:	.asciz	"\nuid: "
sgid:	.asciz	"\ngid: "
srdev:	.asciz	"\nrdev: "
ssize:	.asciz	"\nsize: "
sblksize:	.asciz	"\nblksize: "
sblocks:	.asciz	"\nblocks: "
satime:	.asciz	"\natime: "
satime_nsec:	.asciz	"\natime_nsec: "
smtime:	.asciz	"\nmtime: "
smtime_nsec:	.asciz	"\nmtime_nsec: "
sctime:	.asciz	"\nctime: "
sctime_nsec:	.asciz	"\nctime_nsec: "



.text
.globl	_start
_start:
	movq	%rsp,		%rbp
	lea	STAT(%rsp),	%rsp
	movq	$file,		%rdi
	movq	%rbp,		%rsi
	call	print_stat
	xorq	%rdi,		%rdi
	jmp	_exit
	
/*	Print file statistic with stat()
	rdi - pointer to struct
	rsi - pointer to file name	*/
print_stat:
	call	stat
	call	print_string
	movq	$semnl,		%rdi
	call	print_string
.Lpstat_dev:
	movq	$sdev,		%rdi
	call	print_string
	movq	(%rbp),		%rdi
	call	print_uint
.Lpstat_ino:
	movq	$sino,		%rdi
	call	print_string
	movq	64(%rbp),	%rdi
	call	print_uint
.Lpstat_nlink:
	movq	$snlink,	%rdi
	call	print_string
	movq	128(%rbp),	%rdi
	call	print_uint
.Lpstat_mode:
	movq	$smode,		%rdi
	call	print_string
	movq	150(%rbp),	%rdi
	shr	$32,		%rdi
	call	print_uint
.Lpstat_end:
	call	print_newline
	ret

stat:
	movq	$__NR_stat,	%rax
	syscall
	cmpq	$-1,		%rax
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
	movq	$-1,		%rdi
	jmp	_exit
