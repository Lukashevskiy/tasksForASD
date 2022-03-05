CXX = g++
CFLAGS =-Wall -c --std=c++11
OUTPUT = output.txt
N = 10
generate.o: genAngels.cpp
	$(CXX) $(CFLAGS) genAngels.cpp -o generate.o
read.o: readAngles.cpp
	$(CXX) $(CFLAGS) readAngels.cpp -o read.o
generate: generate.o
	$(CXX) generate.o -o generate
read: read.o
	$(CXX) read.o -o read

all: generate read
clean:
	rm *.o rm *gch $(OUTPUT)
run: all
	./generate $(N) > $(OUTPUT)
	./read < $(OUTPUT)
	
