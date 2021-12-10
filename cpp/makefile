CC       := g++
# LD       := g++
CFLAGS   := -std=c++11  -g
CPPFLAGS := 
INCLUDES := -I ./include  
INCLUDES += -I ./include/cpplang/ 
INCLUDES += -I ../boost/
LIBS     :=
LDFLAGS  := -lstdc++  -lpthread

VPATH := ./src/ \
 		./src/cpplang  \
		./include/  \
		./include/cpplang 

MODULES  := cpplang
BUILD_DIR:= build


.PHONY: clean

all: checkdirs main.exe testcpp.exe testfan.exe testCLI.exe testboost.exe testlib.exe test-leetcode.exe build/cpplang

checkdirs: $(BUILD_DIR)
	

$(BUILD_DIR):
	mkdir -p $@

build/cpplang: cpplang.o ZeroEvenOdd.o
	$(CC) $(filter %.o,$^) -o $@ $(LIBS) $(LDFLAGS)

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
	rm -f *.o *.exe *.out
	rm -f main testcpp testfan testCLI testboost testlib test-leetcode cpplang 
