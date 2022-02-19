CC       := rustc
VPATH    := ./hello  ./src 
BUILD_DIR:= build
CFLAGS   := -g

.PHONY: clean

all: checkdirs build/hello build/main

checkdirs: $(BUILD_DIR)

$(BUILD_DIR):
	mkdir -p $@

build/hello: hello.rs
	$(CC) $^ $(CFLAGS) -o $@

build/main: main.rs
	$(CC) $^  $(CFLAGS) -o $@

clean:
	rm -f ./build/hello
	rm -f ./build/main

