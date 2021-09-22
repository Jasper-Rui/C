#include <stdio.h>
#include <string.h>


int main () {

    int arr1[] = {1,2,55,4,5};
    int arr2[] = {1,2,3,4,6,6};


    int ret = memcmp(arr1, arr2, 5 * sizeof(int));
    printf("%d\n", ret);

    memset(arr1, 0, 8);

    for(int i = 0; i < 5; i++){
        printf("%d ", arr1[i]);
    }

    return 0;   
}