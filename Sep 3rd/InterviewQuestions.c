#include <stdio.h>

int main(){
    int a[] = { 1,2,3,4,5 };
    int * ptr = (int *) (&a + 1);
    printf(" %d  %d \n", *(a + 1), *(ptr - 1));

    //(int*) is to conver (&a + 1) to an integer type address

    //&a + 1 -> 1,2,3,4,5,_; "_" is *ptr pointers to and it is an integer type pointer
    //*(a + 1) -> a[1] -> 2
    //*(ptr - 1) -> move from "_" to 5
    //so result is 2 5


    return 0; 
}