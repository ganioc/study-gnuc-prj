CC       := g++
CFLAGS   := -std=gnu++11  -g
CPPFLAGS := 
INCLUDES := -I ./include ../boost/
LIBS     :=
LDFLAGS  := -lstdc++ 

VPATH := ./src ./include

.PHONY: clean

all: main.exe testcpp.exe testfan.exe testCLI.exe testboost.exe testlib.exe test-leetcode.exe

test-leetcode.exe: test-leetcode.o
	$(CC) $(filter %.o,$^) -o $@ $(LIBS) $(LDFLAGS) 

testlib.exe: testlib.o
	$(CC) $(filter %.o,$^) -o $@ $(LIBS) $(LDFLAGS) 

testboost.exe: testboost.o
	$(CC)  $(filter %.o,$^) -o $@ $(LIBS) $(LDFLAGS) 

testCLI.exe: testCLI.o 
	$(CC)  $(filter %.o,$^) -o $@ $(LIBS) $(LDFLAGS) 

testfan.exe: testfan.o CMessage.o Folder.o
	$(CC)  $(filter %.o,$^) -o $@ $(LIBS) $(LDFLAGS) 

testcpp.exe: testcpp.o
	$(CC)  $(filter %.o,$^) -o $@ $(LIBS) $(LDFLAGS) 

main.exe: main.o NameDataSet.o
	$(CC)  $(filter %.o,$^) -o $@ $(LIBS) $(LDFLAGS) 

%.o: %.cc
	$(CC) $(CFLAGS) $(INCLUDES) $(CPPFLAGS) -c $< 

clean:
	rm -f *.o
	rm -f main testcpp testfan testCLI testboost testlib test-leetcode
