#include <stdio.h>
//#include <windows.h>


int main () {

    register int a = 100;
    a = 200;
    printf("%d\n", a);
    //printf("%d\n", &a); -> error, rigister do not have address

    return 0;
}