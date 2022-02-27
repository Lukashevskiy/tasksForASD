CXX=g++
CFLAGS= -c -Wall --std=c++11
ifeq ($(OS), Windows_NT)
	RM := del
	TESTCPP := testcpp.exe
else
	RM := rm
	TESTCPP := ./testcpp

endif

all: testcpp testPython.py graphics.py

testcpp: testCpp.o 
	$(CXX) $(DEBUG) testCpp.o -o testcpp
testCpp.o: testCpp.cpp
	$(CXX) $(CFLAGS) -c testCpp.cpp
clean:
	$(RM) *.o *.gcd *.txt $(TESTCPP)

run: all 
	$(TESTCPP) > outCpp.txt
	python3 testPython.py > outPy.txt
	python3 graphics.py

