#include <stdio.h>

void print(int* arr, int sz){
    for(int i = 0; i < sz; i++){
        printf("%d ", arr[i]);
    }
}

void move(int* arr, int sz){
    int left = 0;
    int right = sz - 1;
    while (left < right)
    {
        //get the first odd
        while((left < right) && (arr[left] % 2 == 1)){
            left++;
        }
        //get the first even
        while((left < right) && (arr[right] % 2 != 1)){
            right--;
        }
        //swap then
        if(left < right){
            int tmp = arr[left];
            arr[left] = arr[right];
            arr[right] = tmp;
        }
    }
}





int main(){

    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    int sz = sizeof(arr) / sizeof(arr[0]);
    //what if arr is all odd / even?

    move(arr ,sz);
    print(arr, sz);


    return 0;
}