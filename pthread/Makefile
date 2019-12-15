src = $(wildcard *.c)
obj  = $(src:.c=.o)

FLAGS =  -g -Wall
LDFLAGS = -lm -lpthread

.PHONY: all

all: exam1 joining stack mutexes cond

cond: cond.o
	gcc $< $(LDFLAGS) -o $@


mutexes: mutexes.o
	gcc $< $(LDFLAGS) -o $@
stack: stack.o
	gcc $< $(LDFLAGS) -o $@

exam1: exam1.o
	gcc $< $(LDFLAGS) -o $@ 

joining: joining.o
	gcc $< $(LDFLAGS) -o $@

%.o: %.c
	gcc ${FLAGS} -o $@ -c $<


.PHONY: clean
clean:
	rm -f $(obj) exam1 joining  stack mutexes cond
	
	# make -C ./c  clean





