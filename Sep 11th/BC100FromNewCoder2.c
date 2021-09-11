#include <stdio.h>
#include <assert.h>
//1. combine two array and sort them after combination
//2. combine them as well as sorting them
int* sort(int* des, int* arr1, int* arr2, int size1, int size2){
    assert(des);
    assert(arr1);
    assert(arr2);
    assert(size1);
    assert(size2);
    int* res = des;
    
    while(size1 + size2 - 1){
        if(*arr1 < *arr2 && size1 != 0){
            *des = *arr1;
            *des++;
            *arr1++;
            size1--;
        }
        else if(*arr1 > *arr2 && size2 != 0) {
            *des = *arr2;
            *des++;
            *arr2++;
            size2--;
        }
    }
    return res;
}

int main () {
    
    int size1 = 0;
    int size2 = 0;
    scanf("%d %d", &size1, &size2);
    int arr1[size1];
    int arr2[size2];
    
    int i = 0;
    for(i = 0; i < size1; i++){
        scanf("%d ", &arr1[i]);
    }
    
    for(i = 0; i < size2; i++){
        scanf("%d ", &arr2[i]);
    }
    
    int result[size1 + size2];
    int* res = sort(result, arr1, arr2, size1, size2);
    for(i = 0; i < size1 + size2; i++){
        printf("%d ", *res++);
    }
    return 0;
}