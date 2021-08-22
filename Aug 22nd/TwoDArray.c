#include <stdio.h>

//1st way to recieve a 2d array
/*void test(int arr[3][5]){

}
//this is wrong
void test1(int arr[][]){

}

//this is correct, we can ignore the row, but we cannot ignore col
void test2(int arr[][5]){

}

void test3 (int (*p)[5]){

}*/

void print(int * arr, int sz){
    int i = 0; 
    for(i = 0; i < sz; i++){
        printf("%d ", *(arr + i));
    }
}

int main(){

    int arr[3][5] = {0};
    //for 2d array
    //the address pass to a function is the 1st row
    //which is 5 times 4 byte -> 20 byte address
    //it contains all the elements in arr[0][]
    //normally a 1d array is the address of 1st element which is 4 byte
    /*test(arr);
    test1(arr);
    test2(arr);
    test3(arr);*/

    int arrr[10] = {1,2,3,4,5,6,7,8,9,10};
    int sz = sizeof(arrr) / sizeof(arrr[0]);
    print(arrr, sz);
    return 0;
}