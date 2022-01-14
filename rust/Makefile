CC       := rustc
VPATH    := ./hello  ./src 
BUILD_DIR:= build


.PHONY: clean

all: checkdirs build/hello build/main

checkdirs: $(BUILD_DIR)

$(BUILD_DIR):
	mkdir -p $@

build/hello: hello.rs
	$(CC) $^ -o $@

build/main: main.rs
	$(CC) $^ -g -o $@

clean:
	rm -f ./build/hello
	rm -f ./build/main

