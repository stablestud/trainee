all:	setup lib
setup:
	mkdir -p bin/
lib:	setup lib.asm
	nasm -felf64 -o lib.o lib.asm
	ld -o bin/lib lib.o
