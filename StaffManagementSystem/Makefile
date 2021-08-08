CC = g++

.SUFFIXES: .cpp
.cpp.o:
	$(CC) -c $< -o $@ -std=c++11
	
all: test.exe

test.exe: test.o Worker.o Staff.o
	$(CC) -o $@ $? -std=c++11