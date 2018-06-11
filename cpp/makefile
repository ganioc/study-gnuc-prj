CC       := gcc
CFLAGS   := -std=gnu++11
CPPFLAGS := 
INCLUDES := -I ./include
LIBS     :=
LDFLAGS  := -lstdc++

all: main

main: main.o
	$(CC)  $(filter %.o,$^) -o $@ $(LIBS) $(LDFLAGS) 

%.o: %.cc 
	$(CC) $(CFLAGS) $(INCLUDES) $(CPPFLAGS) -c $< 

