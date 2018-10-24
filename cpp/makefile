CC       := g++
CFLAGS   := -std=gnu++11  -g
CPPFLAGS := 
INCLUDES := -I ./include
LIBS     :=
LDFLAGS  := -lstdc++ 

VPATH := ./src ./include

.PHONY: clean

all: main testcpp testfan testCLI testboost testlib

testlib: testlib.o
	$(CC) $(filter %.o,$^) -o $@ $(LIBS) $(LDFLAGS) 

testboost: testboost.o
	$(CC)  $(filter %.o,$^) -o $@ $(LIBS) $(LDFLAGS) 

testCLI: testCLI.o 
	$(CC)  $(filter %.o,$^) -o $@ $(LIBS) $(LDFLAGS) 

testfan: testfan.o CMessage.o Folder.o
	$(CC)  $(filter %.o,$^) -o $@ $(LIBS) $(LDFLAGS) 

testcpp: testcpp.o
	$(CC)  $(filter %.o,$^) -o $@ $(LIBS) $(LDFLAGS) 

main: main.o NameDataSet.o
	$(CC)  $(filter %.o,$^) -o $@ $(LIBS) $(LDFLAGS) 

%.o: %.cc
	$(CC) $(CFLAGS) $(INCLUDES) $(CPPFLAGS) -c $< 

clean:
	rm -f *.o
	rm -f main testcpp testfan testCLI testboost
