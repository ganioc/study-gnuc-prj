CC := gcc
CFLAGS := -std=c11 -g
LIBS := -luv
<<<<<<< HEAD
LDFLAGS := 
INCLUDES := -I ./include
VPATH := ./src ./include

.PHONY: clean 

all: hello idle spawn
=======
LDFLAGS := -lm
INCLUDES := -I./include -I./include/duktape
VPATH := ./src ./include ./src/duktape ./src/multi-echo-server ./include/duktape 

.PHONY: clean 

all: hello idle spawn signal childprocess dukmain uvcat echo_main echo_worker


echo_worker: echo_worker.o
	$(CC) $(filter %.o,$^) -o $@ $(LIBS) $(LDFLAGS)

echo_main: echo_main.o
	$(CC) $(filter %.o,$^) -o $@ $(LIBS) $(LDFLAGS)

uvcat: uvcat.o
	$(CC) $(filter %.o,$^) -o $@ $(LIBS) $(LDFLAGS)

dukmain: dukmain.o duktape.o
	$(CC) $(filter %.o,$^) -o $@ $(LIBS) $(LDFLAGS)

childprocess: childprocess.o
	$(CC) $(filter %.o,$^) -o $@ $(LIBS) $(LDFLAGS)

signal: signal.o
	$(CC) $(filter %.o,$^) -o $@ $(LIBS) $(LDFLAGS)
>>>>>>> master

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
<<<<<<< HEAD
	rm hello idle
=======
	rm hello idle dukmain
>>>>>>> master
