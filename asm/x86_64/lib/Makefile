all:	setup lib c 
setup:
	mkdir -p bin/
lib:	setup lib.asm
	nasm -felf64 -o lib.o lib.asm
	ld -o bin/own_string_copy *.o
c:	setup strncpy.c
	gcc -O3 -o bin/strncpy strncpy.c
