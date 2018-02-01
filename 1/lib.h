/*: LIB.H -- Header file: example C library */
/* Array-like entity created at run-time */

typedef struct STASHtag {
	int size; /*Size of each space */
	int quantity; /* Number of storage spaces */
	int next; /* Next empty space */
	/* Dynamically allocated array of bytes: */
	unsigned char* storage;
}Stash;

void initialize(Stash* S, int Size);
void cleanup(Stash* S);
int add(Stash* S, void* element);
void* fetch(Stash* S ,int index);
int count(Stash* S);
void inflate(Stash* S, int increase);
