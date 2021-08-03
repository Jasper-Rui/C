#include <stdio.h>

int main() {



    int arr[] = {1, 2, 3, 4, 5};
    int i = 0;
    for(i = 0; i < 5; i++){
        printf("%p --------- %p\n", &arr[i], &arr + i);
    }
    //here result is
    //    0061FEB8 --------- 0061FEB8
    //    0061FEBC --------- 0061FECC
    //    0061FEC0 --------- 0061FEE0
    //    0061FEC4 --------- 0061FEF4
    //    0061FEC8 --------- 0061FF08
    //so &(arr + i) is address for arr[i]
    //arr[4]:  *(arr + 4)
    printf("\n");

    printf("%d \n", arr[4]);
    printf("%d \n", *(arr + 4));
    //they are same here

    //now let try some new format
    //[ ] is operator here
    printf("%d \n", *(4 + arr));
    printf("%d \n", 4[arr]); // but normally do not suggest is this way
    


    return 0;
}
