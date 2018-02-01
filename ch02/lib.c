/* : LIB.C -- Implementation of 
	 example C library */
/* Declare structure and functions: */
#include "../1/lib.h"
/* Error testing macros: */
#include <assert.h>
/* Dynamic memory allocation function */
#include <stdlib.h>
#include <string.h> /* memcpy() */
#include <stdio.h>

void initialize(Stash* S, int Size){
	S->size = Size;
	S->quantity = 0;
	S->storage = 0;
	S->next = 0;
}

void cleanup(Stash* S){
	if(S->storage){
		puts("freeing storage");
		free(S->storage);
	}
}

int add(Stash* S, void* element){
	/* enough space left? */
	if(S->next >= S->quantity)
		inflate(S, 100);
	/* Copy element into storage,
	starting at next empty space: */
	memcpy(&(S->storage[S->next * S->size]),
		element, S->size);
	S->next++;
	return (S->next - 1); /* Index number*/
}

void* fetch(Stash* S, int index){
	if(index >= S->next || index < 0)
		return 0; /* Not out of bounds? */
	/* Produce pointer to desired element: */
	return &(S->storage[index * S->size]);
}

int count(Stash* S){
	/* Number of elements in stash*/
	return S->next;
}

void inflate(Stash* S, int increase){
	void* V =
		realloc(S->storage,
				(S->quantity + increase)
				 * S->size);
	/* Was it successful? */
	assert(V);
	S->storage = V;
	S->quantity += increase;
}		
