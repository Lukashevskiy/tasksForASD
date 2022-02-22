CXX=g++
CFLAGS= -Wall --std=c++11
DEBUG= 

all: testcpp testPython.py graphics.py

testcpp: testCpp.o 
	$(CXX) $(DEBUG) testCpp.o -o testcpp
testCpp.o: testCpp.cpp
	$(CXX) $(CFLAGS) -c testCpp.cpp
clean:
	rm *.o *.gcd *.txt testcpp

run: all
	./testcpp > outCpp.txt
	python3 testPython.py > outPy.txt
	python3 graphics.py
