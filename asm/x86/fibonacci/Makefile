all: mkdir file open mmap close main factorial prime digits lib
	ld bin/*.o -o bin/fibonacci
mkdir:
	mkdir -p bin/
file:	file.S file.h open.h open.def close.h mmap.h mmap.def mkdir
	gcc -c file.S -o bin/file.o
mmap:	mmap.S mmap.h mkdir
	gcc -c mmap.S -o bin/mmap.o
close:	close.S close.h mkdir
	gcc -c close.S -o bin/close.o
open:	open.S open.h mkdir
	gcc -c open.S -o bin/open.o
main:	main.S mkdir
	gcc -c main.S -o bin/main.o
factorial:	factorial.S factorial.h mkdir
	gcc -c factorial.S -o bin/factorial.o
prime:	prime.S prime.h mkdir
	gcc -c prime.S -o bin/prime.o
digits:	digits.S digits.h mkdir
	gcc -c digits.S -o bin/digits.o
lib:	../lib mkdir
	make -C ../lib obj
	cp ../lib/bin/lib.o bin/lib.o
