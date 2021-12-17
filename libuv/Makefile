CC := gcc
CFLAGS := -std=c11 -g
LIBS := -luv
LDFLAGS := 
INCLUDES := -I ./include
VPATH := ./src ./include

.PHONY: clean 

all: hello idle spawn signal childprocess


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
	rm hello idle
