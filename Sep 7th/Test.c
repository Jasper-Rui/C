#include <stdio.h>

int main () {
    int a[4] = { 1,2,3,4 };
    int *ptr1 = (int*)(&a + 1); 
    //(&a + 1 ) -> 4 + 4
    // 1 2 3 4 _ 
    //          -> ptr1 points to _

    int *ptr2 = (int*)((int) a + 1); 
    //convert address of array 'a' to integer and add 1


    printf("%x %x\n", ptr1[-1], *ptr2);
    //%x is to print numbers into hex
    //result is 0x04
    //ptr[-1]
    // 1 2 3 4 _ 
    //       -> ptr1 points to 4
    //result is 0x04 -> 16 ^ (0) * 4 -> 4 for ptr1[-1]
    //*ptr2 is 
    //assume a address is 0x0012ff40
    //convert to int -> 1,244,992 
    //then add 1 -> 1,244,993
    //convert to int* -> address -> 0x0012ff41
    

    return 0;
}