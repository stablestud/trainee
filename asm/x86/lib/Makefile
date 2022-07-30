all:	setup obj
setup:
	mkdir -p bin/
lib:	src/lib.asm setup
	nasm -felf64 -o bin/lib.o src/lib.asm
	ld -o bin/lib bin/lib.o
obj:	src/lib.asm setup
	nasm -felf64 -o bin/lib.o src/lib.asm
