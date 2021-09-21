#include <stdio.h>
#include <string.h>

void* my_memcpy (void * des, const void * src, size_t sz){
    void* temp = des;
    while (sz--)
    {
        *(char*)des = *(char*)src;
        src = (char*)src + 1;
        des = (char*)des + 1;
    }
    return temp;
}

void * my_memmove (void * des, const void * src, size_t sz){
    void* temp = des;
    while(sz--){
        char temp = *(char*)src;
    }
    return temp;
}


int main () {
    int arr1[10] = {1,2,3,4,5,6,7,8,9,0};
    int arr2[20] = {0};
    my_memcpy(arr2, arr1, 10 * sizeof(int));
    //memcpy(arr2, arr1, 10 * sizeof(int));

    for(int i = 0; i < 20; i++){
        printf("%d ", arr2[i]);
    }

    //or we can do
    printf("\n");
    int arr3[] = {1,2,3,4,5,6,7,8,9,20};
    my_memcpy(arr3 + 2, arr3, 16);

    for(int i = 0; i < 10; i++){
        printf("%d ", arr3[i]);
    }
    //it actually becomes 1 2 1 2 1 2 7 8 9 20
    //so we can use memory move here
    int arr4[] = {1,2,3,4,5,6,7,8,9,20};
    memmove(arr4 + 2, arr4, 16);
    printf("\n");
    for(int i = 0; i < 10; i++){
        printf("%d ", arr4[i]);
    }
    //then it will becomes 1 2 1 2 3 4 7 8 9 20
    return 0;
}