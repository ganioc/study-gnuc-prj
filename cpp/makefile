CC       := g++
CFLAGS   := -std=gnu++11  -g
CPPFLAGS := 
INCLUDES := -I ./include
LIBS     :=
LDFLAGS  := -lstdc++ -p

VPATH := ./src ./include

.PHONY: clean

all: main testcpp testfan testCLI

testCLI: testCLI.o 
	$(CC)  $(filter %.o,$^) -o $@ $(LIBS) $(LDFLAGS) 

testfan: testfan.o
	$(CC)  $(filter %.o,$^) -o $@ $(LIBS) $(LDFLAGS) 

testcpp: testcpp.o
	$(CC)  $(filter %.o,$^) -o $@ $(LIBS) $(LDFLAGS) 

main: main.o NameDataSet.o
	$(CC)  $(filter %.o,$^) -o $@ $(LIBS) $(LDFLAGS) 

%.o: %.cc
	$(CC) $(CFLAGS) $(INCLUDES) $(CPPFLAGS) -c $< 

clean:
	rm -f *.o
	rm -f main testcpp testfan testCLI
