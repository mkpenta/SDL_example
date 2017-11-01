#To use this make file, navigate to the directory containing the makefile and type "make"
#		https://www.cs.bu.edu/teaching/cpp/writing-makefiles/

all: main

main: main.o SDLManager.o
	g++ -std=c++11 main.o SDLManager.o -o main.exe -w -lSDL2

main.o: main.cpp SDLManager.h
	g++ -std=c++11 -c main.cpp -w -lSDL2

SDLManager.o: SDLManager.cpp SDLManager.h
	g++ -std=c++11 -c SDLManager.cpp -w -lSDL2
	
clean:
	rm *.o *.exe
