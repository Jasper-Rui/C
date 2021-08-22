#include <stdio.h>


int add(int a, int b){ // int * (int, int)
    return a + b;
}

int sub(int a, int b){ // int * (int, int)
    return a - b;
}

int mul(int a, int b){
    return a * b;
}

int div(int a, int b){
    return a / b;
}


int main(){

    int * arr[10];//array of 10 pointers

    int (*padd)(int, int) = add;
    int (*psub)(int, int) = sub;
    int (*pmul)(int, int) = mul;
    int (*pdiv)(int, int) = div;

    int (*parr[4])(int, int) = {add, sub, mul, div};
    return 0;
}