CC = g++

.SUFFIXES: .cpp
.cpp.o:
	$(CC) -c $< -o $@ -std=c++11
	
all: main.exe

main.exe: main.o Worker.o Staff.o Manager.o Boss.o ManagementSystem.o
	$(CC) -o $@ $? -std=c++11