#To use this make file, navigate to the directory containing the makefile and type "make"
#		https://www.cs.bu.edu/teaching/cpp/writing-makefiles/

all: test

test: test.o rect.o
	g++ test.o rect.o -o test.exe -w -lSDL2

test.o: test.cpp rect.h
	g++ -c test.cpp -w -lSDL2

rect.o: rect.cpp
	g++ -c rect.cpp -w -lSDL2
	
clean:
	rm *.o *.exe
