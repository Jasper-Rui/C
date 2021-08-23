#include <stdio.h>

int add(int x, int y){
    return x + y;
}

int main(){
    int arrr[10];
    int (*parr)[10] = &arrr; //(*parr) is a pointer points to an array of 10 integers


    int *arr[10];
    int (*p)[10] = &arr;//p is an pointer, points to an array of 10 pointers

    int (*padd)(int, int) = add;
    int (*parr[5])(int, int); //parr[5] is an array of function pointers
    int (* (*parrr[5]) )(int, int) = &parr; // parrr here is an pointer, points to an array of function pointers


    


    return 0;
}