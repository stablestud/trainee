all:	own ref c
own:	lib.asm
	nasm -felf64 -o lib.o lib.asm -DOWN
	ld -o own_string_copy lib.o

ref:	lib.asm
	nasm -felf64 -o lib.o lib.asm -DREF
	ld -o ref_string_copy lib.o
c:	strncpy.c
	gcc -O3 -o strncpy strncpy.c
