CC=g++
FLAGS=-std=c++17 -O2 -Wall -Werror -pedantic -Wextra -Wunused-variable -fsanitize=address
EXEC_FILE=program.out

all: $(EXEC_FILE)

$(EXEC_FILE): program.o test.o
	$(CC) $(FLAGS) $^ -o $@

program.o: program.cpp program.hpp
	$(CC) $(FLAGS) -c program.cpp

test.o: test.cpp program.hpp
	$(CC) $(FLAGS) -c test.cpp

clean:
	rm -f *.o $(EXEC_FILE)

test: $(EXEC_FILE)
	./test