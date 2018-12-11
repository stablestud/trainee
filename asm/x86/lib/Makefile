all:	setup obj
setup:
	mkdir -p bin/
lib:	lib.asm setup
	nasm -felf64 -o lib.o lib.asm
	ld -o bin/lib lib.o
obj:	lib.asm setup
	nasm -felf64 -o bin/lib.o lib.asm
