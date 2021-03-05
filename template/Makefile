CC=g++
FLAGS=-std=c++17 -O2 -Wall -Werror -pedantic -Wextra -Wno-unused-variable

all: program

program: program.o test.o
	$(CC) $(FLAGS) -o test program.o test.o

program.o: program.cpp program.hpp
	$(CC) $(FLAGS) -c program.cpp

test.o: test.cpp program.hpp
	$(CC) $(FLAGS) -c test.cpp

clean:
	rm -rf *.o test

test: program
	./test