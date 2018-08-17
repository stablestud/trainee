all:	uint int
uint:	lib.inc
	nasm -felf64 -o lib.o lib.inc -DPRINT_UINT
	ld -o print_uint lib.o

int:	lib.inc
	nasm -felf64 -o lib.o lib.inc -DPRINT_INT
	ld -o print_int lib.o
