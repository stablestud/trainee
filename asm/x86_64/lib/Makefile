all:	uint int
uint:	lib.asm
	nasm -felf64 -o lib.o lib.asm -DSTRING_TO_UINT
	ld -o string_to_uint lib.o

int:	lib.asm
	nasm -felf64 -o lib.o lib.asm -DSTRING_TO_INT
	ld -o string_to_int lib.o
