all:	uint int
uint:	lib.inc
	nasm -felf64 -o lib.o lib.inc -DSTRING_TO_UINT
	ld -o string_to_uint lib.o

int:	lib.inc
	nasm -felf64 -o lib.o lib.inc -DSTRING_TO_INT
	ld -o string_to_int lib.o
