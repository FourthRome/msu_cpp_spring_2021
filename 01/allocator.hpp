#pragma once

#include <cstddef>
#include <stdlib.h>
#include <new>
#include <iostream>


class Allocator
{
public:
    Allocator();
    virtual ~Allocator();
    void makeAllocator(size_t maxSize); // Initialize internal buffer with a chunk of memory
    char* alloc(size_t size); // Get a portiion of buffer's memory
    void reset(); // Start allocating from buffer's beginning again

private:
    char *buffer = nullptr;
    size_t buffer_size = 0; 
    size_t offset = 0;

};
