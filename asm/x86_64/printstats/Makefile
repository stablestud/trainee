all:	main.S
	mkdir -p bin/
	gcc -c -o bin/printstats.o *.S
	ld -o bin/printstats bin/printstats.o
