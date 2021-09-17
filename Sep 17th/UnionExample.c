#include <stdio.h>

union UnionExample
{
    /* data */
    char c1;
    int i1;
};

int main () {
    union UnionExample u = {0};
    printf("%d\n", sizeof(u));
    //why this is 4 ?

    printf("%p\n", &u); //0x16fc875d8
    printf("%p\n", &(u.c1)); //0x16fc875d8
    printf("%p\n", &(u.i1)); //0x16fc875d8
    //they have the same address
    //why
    





    return 0;
}