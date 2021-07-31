#include <stdio.h>



int main()
{


    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    printf("%p \n", arr);
    printf("%p \n", &arr[0]);
    printf("%p \n", &arr);

    printf("%p \n", arr + 1);
    printf("%p \n", &arr[0] + 1);
    printf("%p \n", &arr + 1);

    /*
    result is 
    0000005d32dff870 address of the array
    0000005d32dff870 address of the 1st element
    0000005d32dff870 address of the array

    0000005d32dff874 address of the array + 1
    0000005d32dff874 address of the 1st element + 1
    0000005d32dff898 28 here is 16, so it's 2*(16^1) + 8*(16^1) = 40

    40 means the bytes of the array
    10 elements = 4 * 10 = 40

    */

    return 0;

}