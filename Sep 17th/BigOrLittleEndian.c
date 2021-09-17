#include <stdio.h>


int main () {
    int a = 1; // 00 00 00 01
    //low ------------------------- high
    //   01 00 00 00
    //little endian
    //   00 00 00 01
    //big endian

    char  * pc = (char*) &a;
    if(*pc == 1){
        printf("little endian");
    }
    else {
        printf("Big endian");
    }
    return 0;
}