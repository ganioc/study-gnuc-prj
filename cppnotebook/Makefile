# Makefile for cppnotebook project,

CC       := g++
LD       := g++
CFLAGS   := -std=c++17  -g -Wall
CPPFLAGS := 
INCLUDES := -I ./include/  
LIBS     :=
LDFLAGS  := -lstdc++  -lpthread 
# -lstdc++fs

VPATH := ./src/ \
		./include/  

BUILD_DIR:= build
SHARE_DIR:= share

MODULES := build/nbk

OBJS := main.o init.o study.o

.PHONY: clean

all: checkdirs build/nbk

checkdirs: $(BUILD_DIR) $(SHARE_DIR)

$(BUILD_DIR):
	mkdir -p $@
$(SHARE_DIR):
	mkdir -p $(BUILD_DIR)/$(SHARE_DIR)

build/nbk : $(OBJS)
	$(CC) $(filter %.o,$^) -o $@ $(LIBS) $(LDFLAGS)

%.o: %.cpp 
	$(CC) $(CFLAGS) $(INCLUDES) $(CPPFLAGS) -c $< 

clean:
	rm -f *.o *.exe *.out
	rm -f build/nbk
