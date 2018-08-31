all:	setup reg hyb tree
setup:
	mkdir -p bin/
reg:	setup lib.asm
	nasm -felf64 -o lib.o lib.asm -DREG
	ld -o bin/reg_string_length *.o
hyb:	setup lib.asm
	nasm -felf64 -o lib.o lib.asm -DHYB
	ld -o bin/hyb_string_length *.o
tree:	setup lib.asm
	nasm -felf64 -o lib.o lib.asm -DTREE
	ld -o bin/tree_string_length *.o

own:	setup lib.asm
	nasm -felf64 -o lib.o lib.asm -DOWN
	ld -o bin/own_string_copy *.o
ref:	setup lib.asm
	nasm -felf64 -o lib.o lib.asm -DREF
	ld -o bin/ref_string_copy *.o
c:	setup strncpy.c
	gcc -O3 -o bin/strncpy strncpy.c
