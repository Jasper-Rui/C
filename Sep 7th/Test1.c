#include <stdio.h>

int main () {

    int a[3][2] = { (0,1) , (2, 3), (4,5) };
    int * p;
    p = a[0];
    //p is the address for a[0] -> {(0, 1);

    printf("%d\n", p[0]); // -> (0, 1) -> 1
    //or actually p[0] -> *(p + 0) -> *p -> (0, 1) -> 1

    return 0;
}