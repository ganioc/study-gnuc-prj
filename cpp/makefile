CC       := g++
CFLAGS   := -std=gnu++11
CPPFLAGS := 
INCLUDES := -I ./include
LIBS     :=
LDFLAGS  := -lstdc++

VPATH := ./src

.PHONY: clean

all: main

main: main.o NameDataSet.o
	$(CC)  $(filter %.o,$^) -o $@ $(LIBS) $(LDFLAGS) 

%.o: %.cc 
	$(CC) $(CFLAGS) $(INCLUDES) $(CPPFLAGS) -c $< 

clean:
	rm -f *.o
	rm -f main
