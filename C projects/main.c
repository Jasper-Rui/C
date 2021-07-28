#include <stdio.h>

int main() {


    int ch = 0;
    while((ch = getchar() != EOF)){
        putchar(ch);
    }
    //return type for getchar is int
    //why
    //1. getchar will return the ASCII number(because it's integers)
    //2. if the input is invalid, it will return EOF, which representative end of file -> -1
    //   so it's int
    //printf("Hello, World!\n");
    return 0;
}
