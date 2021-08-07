CC = g++

.SUFFIXES: .cpp
.cpp.o:
	$(CC) -c $<

all: main.exe

main.exe: main.o addressbook.o person.o
	$(CC) -o main.exe $?

.PHONY: clean

clean:
	rm -f *.o *.exe