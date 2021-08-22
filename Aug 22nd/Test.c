#include <stdio.h>

void test(int* a){

}

void test1(int ** p){

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


    int c = 100;
    int * d = &c;
    int ** f = &d;

    test1(f);
    //or
    test1(&d);



    return 0;

}