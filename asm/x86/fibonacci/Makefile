all: mkdir file open mmap close main
	ld bin/*.o -o bin/fibonacci
mkdir:
	mkdir -p bin/
file:	file.S file.h open.h open.def close.h mmap.h mmap.def mkdir
	gcc -c file.S -o bin/file.o
mmap:	mmap.S mmap.h
	gcc -c mmap.S -o bin/mmap.o
close:	close.S close.h
	gcc -c close.S -o bin/close.o
open:	open.S open.h
	gcc -c open.S -o bin/open.o
main:	main.S
	gcc -c main.S -o bin/main.o
