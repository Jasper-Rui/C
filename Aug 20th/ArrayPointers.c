#include <stdio.h>


void print1(int arr[], int sz){
    int i = 0;
    for(i = 0; i < sz; i++){
        printf("%d ", arr[i]);
    }
}

void print2(int* arr, int sz){
    int i = 0;
    for(i = 0; i < sz; i++){
        printf("%d ", *(arr + i));
    }
}


void print3(int (*parr)[10], int sz){
    int i = 0;
    for(i = 0; i < sz; i++){
        printf("%d ", *((*parr) + i));
    }
}



int main(){


    //int* arr[10];
    //int* (*p)[10] = &arr;
    //they are equivalent

    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int sz = sizeof(arr) / sizeof(arr[0]);
    print1(arr ,sz);//print each element of arr
    printf("\n");
    print2(arr ,sz);//print each element of arr
    printf("\n");
    print3(&arr, sz);










    return 0;
}