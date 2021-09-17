#include <stdio.h>

void check_sys (){
    union U
    {
    /* data */
    char c;
    int i;
    }u;

    u.i = 1;
    //return 1 -> little endian
    //return 0 -> big endian
    if(u.c == 1){
       printf("little endian");
    }
    else {
        printf("Big endian");
    }
}


int main () {

    check_sys();

    return 0;
}