#include <stdio.h>



int main () {

    union U
    {
    /* data */
    char c;
    int i;
    }u;

    u.i = 1;

    if(u.c == 1){
       printf("little endian");
    }
    else {
        printf("Big endian");
    }

    return 0;
}