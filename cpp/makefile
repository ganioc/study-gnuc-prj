CC       := g++
LD       := g++
CFLAGS   := -std=c++11  -g -Wall
# -Wall -Wc++11-extensions
CPPFLAGS := 
INCLUDES := -I ./include/  
INCLUDES += -I ./include/cpplang/ 
INCLUDES += -I ../boost/
INCLUDES += -I ./include/concurrency/
LIBS     :=
LDFLAGS  := -lstdc++  -lpthread

VPATH := ./src/ \
 		./src/cpplang/  \
		./src/concurrency/ \
		./include/  \
		./include/cpplang/  \
		./include/concurrency 

MODULES  := cpplang
BUILD_DIR:= build


.PHONY: clean

all: checkdirs main.exe testcpp.exe testfan.exe testCLI.exe testboost.exe testlib.exe test-leetcode.exe build/cpplang build/calculator build/concurr build/test

checkdirs: $(BUILD_DIR)
	

$(BUILD_DIR):
	mkdir -p $@

build/test: test.o
	$(CC) $(filter %.o,$^) -o $@ $(LIBS) $(LDFLAGS)

build/concurr : concurr.o
	$(CC) $(filter %.o,$^) -o $@ $(LIBS) $(LDFLAGS)

build/calculator: calculator.o TokenStream.o
	$(CC) $(filter %.o,$^) -o $@ $(LIBS) $(LDFLAGS)

build/cpplang: cpplang.o ZeroEvenOdd.o Vector.o CVector.o SimpleVector.o Shape.o Xref.o
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

%.o: %.cpp 
	$(CC) $(CFLAGS) $(INCLUDES) $(CPPFLAGS) -c $< 

clean:
	rm -f *.o *.exe *.out
	rm -f main testcpp testfan testCLI testboost testlib test-leetcode cpplang 


