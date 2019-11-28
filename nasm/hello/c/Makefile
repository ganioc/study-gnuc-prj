csrc = $(wildcard *.c)

cobj  = $(csrc:.c=.o)

FLAGS = 
CLDFLAGS = 

.PHONY: all

all: main

main: $(cobj)
	gcc $(CLDFLAGS) -o $@ $^

%.o: %.c
	gcc -o $@ -c $<
	gcc -s $<

.PHONY: clean
clean:
	rm -f main $(cobj) *~





