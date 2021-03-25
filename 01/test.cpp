#include <cassert>
#include <cstring>
#include "allocator.hpp"


// Check if it can allocate some memory
void AllocateTest() {
    Allocator allocator = Allocator();
    allocator.makeAllocator(100);
    std::cout << "AllocateTest passed;" << std::endl;
}


// Check if it reset() works as expected
void ResetTest() {
    Allocator allocator = Allocator();
    allocator.makeAllocator(100);
    char *first = allocator.alloc(15);
    strncpy(first, "Hello, World!", 15);
    allocator.reset();
    char *second = allocator.alloc(15);
    assert(std::string(first) == std::string(second));
    std::cout << "ResetTest passed;" << std::endl;
}


// Check if it does not allocate anything not fitting into buffer
void OverflowTest() {
    Allocator allocator = Allocator();
    allocator.makeAllocator(100);
    allocator.alloc(10);
    allocator.alloc(30);
    assert(allocator.alloc(70) == nullptr);
    std::cout << "OverflowTest passed;" << std::endl;
}


// Check if it gracefully fails to allocate a huge chunk of memory
void OutOfMemoryTest() {
    Allocator allocator = Allocator();
    allocator.makeAllocator(10000000000);
    assert(allocator.alloc(1) == nullptr);
    std::cout << "OutOfMemoryTest passed;" << std::endl;
}


// Check if we can reinitialize the same Allocator object without memory leaks (-fsanitize=address)
void RemakeAllocatorTest() {
    Allocator allocator = Allocator();
    allocator.makeAllocator(100);
    allocator.alloc(50);
    allocator.makeAllocator(1000);
    assert(allocator.alloc(500) != nullptr);
    std::cout << "RemakeAllocatorTest passed;" << std::endl;
}


// Check if destructor does it's job properly (this test makes sense only with -fsanitize=address flag)
void DestructorTest() {
    Allocator *allocator = new Allocator();
    allocator->makeAllocator(100);
    allocator->alloc(50);
    delete allocator;
    std::cout << "DestructorTest passed;" << std::endl;
}


// Check that we can get all the memory from buffer
void FullUtilizeTest() {
    Allocator allocator = Allocator();
    allocator.makeAllocator(100);
    allocator.alloc(50);
    assert(allocator.alloc(50) != nullptr);
    allocator.makeAllocator(1000);
    allocator.alloc(500);
    assert(allocator.alloc(500) != nullptr);
    std::cout << "FullUtilizeTest passed;" << std::endl;
}


int main() {
    AllocateTest();
    ResetTest();
    OverflowTest();
    OutOfMemoryTest();
    RemakeAllocatorTest();
    DestructorTest();
    FullUtilizeTest();
    std::cout << "Tests passed successfully." << std::endl;
    return 0;
}
