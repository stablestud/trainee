all: mkdir mmap close open
	ld bin/*.o -o bin/fibonacci
mkdir:
	mkdir -p bin/
mmap:	mmap.S mmap.h
	gcc -c mmap.S -o bin/mmap.o
close:	close.S close.h
	gcc -c close.S -o bin/close.o
open:	open.S open.h
	gcc -c open.S -o bin/open.o
