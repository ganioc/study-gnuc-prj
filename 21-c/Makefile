CC := gcc
CFLAGS := -std=c11 -g
LIBS :=
LDFLAGS := 
INCLUDES := -I ./include
VPATH := ./src ./include

.PHONY: clean hello

all: first unsingvoid chapfun algri

unsingvoid: unsingvoid.o
	$(CC) $(filter %.o,$^) -o $@ $(LIBS) $(LDFLAGS)

first: first.o
	$(CC) $(filter %.o,$^) -o $@ $(LIBS) $(LDFLAGS)

chapfun: chapfun.o
	$(CC) $(filter %.o,$^) -o $@ $(LIBS) $(LDFLAGS)

algri: algri.o
	$(CC) $(filter %.o,$^) -o $@ $(LIBS) $(LDFLAGS)

%.o: %.c 
	$(CC) $(CFLAGS) $(INCLUDES) -c $<

clean:
	rm -f *.o
	rm first unsingvoid algri

hello:
	echo -e "hello world"
