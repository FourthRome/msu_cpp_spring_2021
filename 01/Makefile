CC=g++
FLAGS=-std=c++17 -O2 -Wall -Werror -pedantic -Wextra -Wunused-variable -fsanitize=address
EXEC_FILE=test_allocator.out

all: $(EXEC_FILE)

$(EXEC_FILE): allocator.o test.o
	$(CC) $(FLAGS) $^ -o $@ 

allocator.o: allocator.cpp allocator.hpp
	$(CC) $(FLAGS) -c allocator.cpp

test.o: test.cpp allocator.hpp
	$(CC) $(FLAGS) -c test.cpp

clean:
	rm -f *.o $(EXEC_FILE)

test: $(EXEC_FILE)
	ASAN_OPTIONS=allocator_may_return_null=1 ./$(EXEC_FILE)
