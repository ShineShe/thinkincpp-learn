//: LIBTEST.CPP -- Test of C++ library
#include "../1/libcpp.h"
#include <stdio.h>
#include <assert.h>
#define BUFSIZE 80

int main(){
    stash intStash, stringStash;
    int i;
    FILE* file;
    char buf[BUFSIZE];
    char *cp;
    // ....
    intStash.initialize(sizeof(int));
    for(i = 0; i < 100; i++)
	intStash.add(&i);
    // Holds 80-character strings;
    stringStash.initialize(sizeof(char) * BUFSIZE);
    file = fopen("libtest.cpp", "r");
    assert(file);
    while(fgets(buf, BUFSIZE, file))
	stringStash.add(buf);
    fclose(file);

    for(i = 0; i < intStash.count(); i++)
	printf("intStash.fetch(%d) = %d\n", i,
		*(int*)intStash.fetch(i));
    i = 0;
    while((cp = (char*)stringStash.fetch(i++))!=0)
	printf("stringStash.fetch(%d) = %s", i - 1, cp);
    putchar('\n');
    intStash.cleanup();
    stringStash.cleanup();
}
