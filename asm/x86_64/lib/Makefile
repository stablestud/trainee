all:	setup own ref c
setup:
	mkdir -p bin/
own:	lib.asm
	nasm -felf64 -o lib.o lib.asm -DOWN
	ld -o bin/own_string_copy lib.o

ref:	lib.asm
	nasm -felf64 -o lib.o lib.asm -DREF
	ld -o bin/ref_string_copy lib.o
c:	strncpy.c
	gcc -O3 -o bin/strncpy strncpy.c
