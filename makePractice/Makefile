CXX = g++
CFLAGS =-Wall -c --std=c++11
OUTPUT = output.txt

N = 10
generate.o: genAngles.cpp
	$(CXX) $(CFLAGS) genAngeles.cpp -o generate.o
read.o: readAngles.cpp
	$(CXX) $(CFLAGS) readAngles.cpp -o read.o
generate: generate.o
	$(CXX) generate.o -o /bin/generate
read: read.o
	$(CXX) read.o -o /bin/read

all: generate read
clean:
	rm *.o *.gch $(OUTPUT) generate read
run: all
	generate $(N) > $(OUTPUT)
	read < $(OUTPUT)
	
