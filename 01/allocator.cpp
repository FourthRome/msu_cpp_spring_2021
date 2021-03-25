#include "allocator.hpp"


Allocator::Allocator() {}


Allocator::~Allocator() {
    operator delete(buffer, buffer_size);
}


// Initialize internal buffer with a chunk of memory
void Allocator::makeAllocator(size_t maxSize) {
    operator delete(buffer, buffer_size);
    offset = 0;
    buffer = nullptr;
    buffer_size = 0;

    buffer = (char *) operator new(maxSize, std::nothrow);
    
    if (buffer != nullptr) {
        buffer_size = maxSize;
    } else {
        std::cerr << "Failed to allocate memory." << std::endl;
    }
}


// Get a portiion of buffer's memory
char* Allocator::alloc(size_t size) {
    if (buffer == nullptr || buffer_size - offset < size) {
        return nullptr;
    } else {
        char *result = buffer + offset;
        offset += size;
        return result;
    }
}


// Start allocating from buffer's beginning again
void Allocator::reset() {
    offset = 0;
}