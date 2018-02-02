//: LIBCPP.CPP -- C library converted to C++
// Declare structure and functions:
#include "../1/libcpp.h"
#include <assert.h> // Error testing macros
#include <stdlib.h> // Dynamic memory
#include <string.h> // memcpy()
#include <stdio.h>

void stash::initialize(int Size){
    size = Size;
    quantity = 0;
    storage = 0;
    next = 0;
}

void stash::cleanup(){
    if(storage){
	puts("freeing storage");
	free(storage);
    }
}

int stash::add(void *element){
    if(next >= quantity)// Enough space left?
	inflate(100);
    // Copy element into storage,
    // starting at next empty space:
    memcpy(&(storage[next * size]), element, size);
    next++;
    return (next - 1); //Index number
}

void *stash::fetch(int index){
    if(index >= next || index < 0)
	return 0; // Not out of bounds?
    // Produce pointer to desired element:
    return &(storage[index * size]);
}

int stash::count(){
    return next; // Number of elements in stash
}

void stash::inflate(int increase) {
    void *V = 
	realloc(storage, (quantity + increase) * size);
    assert(V); // Was it successful?
    storage = (unsigned char*)V;
    quantity += increase;
}
