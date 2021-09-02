#include <stdio.h>
int main (){


    int arr[] = {1,2,3,4};
    printf("%d\n", sizeof(arr));//16, arr here is the whole array, each of the element is 4 byte, we have 4
    printf("%d\n", sizeof(arr + 0));//here is the element at index 0, so it will be 4 or 8
    printf("%d\n", sizeof(*arr));//4
    printf("%d\n", sizeof(arr + 1));
    printf("%d\n", sizeof(arr[1]));//4



    return 0;
}