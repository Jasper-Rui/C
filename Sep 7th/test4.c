#include <stdio.h>


int main () {
    char * a[] = {"work", "at", "Google"};
    char ** pa = a; // here a is the address for "work"
    pa++; // pa is char**, so it will jump 1 byte -> "a"

    printf("%s\n", *pa);

    return 0;
}