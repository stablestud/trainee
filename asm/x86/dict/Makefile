AS = nasm
ASFLAGS = -f elf64

LD = ld
LDFLAGS = 

OBJ = bin

all: $(OBJ)/program

$(OBJ)/program: $(OBJ)/main.o $(OBJ)/dict.o $(OBJ)/lib.o
	$(LD) $(LDFLAGS) -o $@ $^

$(OBJ):
	mkdir $(OBJ) -p

$(OBJ)/lib.o: ../lib/
	make -C ../lib/ obj
	cp ../lib/bin/lib.o $(OBJ)/lib.o

$(OBJ)/%.o: %.asm $(OBJ)
	$(AS) $(ASFLAGS) -o $@ $<

clean:
	rm -r $(OBJ)/ *.o

.PHONY: clean bin/
