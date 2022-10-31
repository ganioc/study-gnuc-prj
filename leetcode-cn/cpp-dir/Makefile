CC       := g++
LD       := g++
CFLAGS   := -std=c++11  -g -Wall

CPPFLAGS := 
INCLUDES := -I ./include/
LIBS     :=
LDFLAGS  := -lstdc++ -lpthread

VPATH    := ./src/ \
			./include/ 

BUILD_DIR := build

.PHONY : clean

all : checkdirs build/main

checkdirs: $(BUILD_DIR)

$(BUILD_DIR):
	mkdir -p $@

build/main: main.o
	$(CC) $(filter %.o,$^) -o $@ $(LIBS) $(LDFLAGS)

%.o: %.cpp 
	$(CC) $(CFLAGS) $(INCLUDES) $(CPPFLAGS) -c $< 

clean:
	rm -f *.o *.exe *.out
	rm -f build/main 
