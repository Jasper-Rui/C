#include <stdio.h>


int main () {
    char * a[] = {"work", "at", "Google"};
    char ** pa = a; // here a is the address for "work"
    pa++; // pa + 1 -> "at"

    printf("%s\n", *pa);

    return 0;
}