#include <asm/unistd_64.h>

#define	O_RDONLY	0
#define O_TRUNC		800
#define O_CREAT		80
#define	PROT_READ	0x1
#define	MAP_PRIVATE	0x2
#define	MAP_FAILED	-1

.data
filnm:	.asciz	"text.txt"
fail:	.asciz	"open()  failed\n"
	.asciz	"mmap()  failed\n"
	.asciz	"close() failed\n"

.text
.globl _start

_start:
	call	open
	pushq	%rax			# Placeholder for mmap address
	pushq	%rax			# File descriptor
	call	mmap
	movq	%rax,		8(%rsp)
	movq	8(%rsp),	%rsi
	call	write
	movq	(%rsp),		%rdi
	call	close
	xorq	%rdi,		%rdi
	call	_end


.align	16
/* open() syscall */
open:
	movq	$__NR_open,	%rax	# syscall numbr
	movq	$filnm,		%rdi	# file path
	movq	$O_RDONLY,	%rsi	# open flags
	movq	$0,		%rdx	# O_CREAT mode
	syscall
	cmpl	$0,		%eax	# check return value if it failed
	jl	.Lopen_fail
	ret
.align	8
.Lopen_fail:
	movq	$fail,		%rsi	# what string to print
	call	write
	movq	$1,		%rdi
	call	_end


.align	16
/* mmap() syscall */
mmap:
	movq	$__NR_mmap,	%rax	# syscall numbr
	movq	$0,		%rdi	# address
	movq	$4096,		%rsi	# region length in bytes, in this case a single page (number can be less for the same result)
	movq	$PROT_READ,	%rdx	# Protection flags (read, write, execute...)
	movq	$MAP_PRIVATE,	%r10	# Utility flags (shared or private, anonymous pages, etc.)
	movq	8(%rsp),	%r8	# file descriptor
	movq	$0,		%r9	# offset in file
	syscall
	cmpl	$MAP_FAILED,	%eax	# check if it failed
	je	.Lmmap_fail
	ret
.align	8
.Lmmap_fail:
	movq	$fail,		%rax
	leaq	16(%rax),	%rsi	# what string to print
	call	write
	movq	$1,		%rdi
	call	_end


.align	16
/* close() syscall */
close:
	movq	$__NR_close,	%rax	# syscall numbr
	syscall
	cmpl	$0,		%eax	# check if it failed
	jl	.Lclose_fail
	ret
.align	8
.Lclose_fail:
	movq	$fail,		%rax
	leaq	32(%rax),	%rsi	# what string to print
	call	write
	movq	$1,		%rdi
	call	_end


.align	16
/* write() syscall */
write:
	movq	$__NR_write,	%rax	# syscall numbr
	movq	$1,		%rdi	# file descriptor (stdout)
	movq	$13,		%rdx	# characters to print
	syscall
	cmpl	$0,		%eax	# check if it failed
	jl	.Lwrite_fail
	ret
.align	8
.Lwrite_fail:
	movq	$1,		%rdi
	call	_end


.align	16
/* exit() syscall */
_end:
	movq	$__NR_exit,	%rax	# syscall numbr
	syscall
