CC       := gcc
CFLAGS   := 
CPPFLAGS := -std=gnu99
INCLUDES := 
LIBS     :=
LDFLAGS  :=


all: main

main: main.o main.h
	$(CC)  $(filter %.o,$^) -o $@ $(LIBS) $(LDFLAGS) 

%.o: %.c 
	$(CC) $(CFLAGS) $(INCLUDES) $(CPPFLAGS) -c $< 