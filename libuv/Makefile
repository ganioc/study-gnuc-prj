CC := gcc
CFLAGS := -std=c11 -g
LIBS := -luv
LDFLAGS := -lm
INCLUDES := -I./include -I./include/duktape
VPATH := ./src ./include ./src/duktape ./include/duktape 

.PHONY: clean 

all: hello idle spawn signal childprocess dukmain

dukmain: dukmain.o duktape.o
	$(CC) $(filter %.o,$^) -o $@ $(LIBS) $(LDFLAGS)

childprocess: childprocess.o
	$(CC) $(filter %.o,$^) -o $@ $(LIBS) $(LDFLAGS)

signal: signal.o
	$(CC) $(filter %.o,$^) -o $@ $(LIBS) $(LDFLAGS)

spawn: spawn.o
	$(CC) $(filter %.o,$^) -o $@ $(LIBS) $(LDFLAGS)
idle: idle.o
	$(CC) $(filter %.o,$^) -o $@ $(LIBS) $(LDFLAGS)
hello: main.o
	$(CC) $(filter %.o,$^) -o $@ $(LIBS) $(LDFLAGS)
%.o: %.c 
	$(CC) $(CFLAGS) $(INCLUDES) -c $<

clean:
	rm -f *.o
	rm hello idle dukmain
