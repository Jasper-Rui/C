#include <stdio.h>

int main () {
    int a[2][5] = { 1,2,3,4,5,6,7,8,9,10 };
    int * ptr1 = (int*)(&a + 1);
    //&a is the address of whole array
    //add 1 is add the same length of array
    //so ptr1 pointes what after 10
    int * ptr2 = (int*)(*(a + 1));
    //a + 1 here is a[0] + 1 -> a[1]
    //*a[1] -> a[1][0] -> 6
    

    printf("%d, %d", *(ptr1 - 1), *(ptr2 - 1));
    //result is 10, 5

    return 0;
}