#include <stdio.h>

void test(int* a){

}

int main(){
    //what can we pass to test(int*) ?

    int a = 10;
    int* b = &a;
    int arr[10];
    test(b);
    test(&a);
    test(arr);
    test(NULL);//NOT SUGGESTED


    return 0;

}