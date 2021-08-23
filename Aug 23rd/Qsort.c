#include <stdio.h>
#include <stdlib.h>


int main(){
    //qsort
    void qsort (void* base, //input type to be sorted
                size_t num, //amout of elemets in array
                size_t size,//sizeof each element in array
                int (*compar)(const void*,const void*));//function that used to sort the arrayower of Hanoi
    int arr[] = { 9,8,7,6,5,4,3,2,1,0 };
    int sz = sizeof(arr) / sizeof(arr[0]);
    qsort(arr, sz, sizeof(arr[0]), );


    return 0;
}