CC       := gcc
OPTFLAGS := -fprofile-arcs -ftest-coverage
CFLAGS   := 
CPPFLAGS := -std=gnu99
INCLUDES := 
LIBS     :=
LDFLAGS  :=
.PHONY: clean

all: main

main: main.o main.h
	$(CC)  $(filter %.o,$^) -o $@ $(LIBS) $(LDFLAGS) $(OPTFLAGS)

%.o: %.c 
	$(CC) $(CFLAGS) $(INCLUDES) $(CPPFLAGS) $(OPTFLAGS) -c $< 
clean:
	rm -f *.o
	rm -f main
	rm -f *.gcno
	rm -f *.gcda
	