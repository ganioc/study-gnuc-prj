
CC:=gcc
CFLAGS:=-I/usr/src/linux-headers-5.0.0-32-generic/include


PROGS = helloworld

all: $(PROGS)
	echo "helloworld"

%: %.c
	$(CC) $(CFLAGS) $@.c -o $@ $(LDFLAGS)


