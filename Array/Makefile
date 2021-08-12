CC = g++
objects = main.o Person.o Array.hpp

.SUFFIXES: .cpp
.cpp.o:
	$(CC) -c $< -o $@ -std=c++11
	
all: main.exe
main.exe: $(objects)
	$(CC) -o $@ $(objects) -std=c++11