src = $(wildcard *.asm)
obj  = $(src:.asm=.o)

FLAGS = -f elf64 -g -Wall

.PHONY: all

all: hello toupper cdir print_rax maintest

cdir:
	make -C ./c

hello: hello.o 
	ld -o $@ $^ 

toupper: toupper.o
	ld -o $@ $^

print_rax: print_rax.o
	ld -o $@ $^

maintest: maintest.o
	ld -o $@ $^

%.o: %.asm
	nasm ${FLAGS} -o $@  $<


.PHONY: clean
clean:
	rm -f $(obj) hello toupper *~ print_rax maintest
	make -C ./c  clean





