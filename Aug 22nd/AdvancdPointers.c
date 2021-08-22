#include <stdio.h>

void test(int arr[]){

}
void test1(int arr[10]){

}
void test2(int* arr){

}
void test3(int* arr[]){

}
void test4(int** arr){

}


int main(){

    char ch = 'c';
    char* p = &ch;
    *p = 'b';

    const char* str = "abcdefg";
    int arrr[10];
    int* arr[10];
    test(arr);
    test1(arr);
    test2(arr);
    test3(arr);
    test4(arrr);

    return 0;
}