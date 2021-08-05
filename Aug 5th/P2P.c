#include <stdio.h>

int main() {

    int a = 10; // assign 4 byte to store a
    int* p = &a; // assign 4 byte to store p

    int** pp = &p; // int* * pp = &p;

    int*** ppp = &pp; // int** * ppp = &pp;

    //if we want find a by pp
    //we can do
    //(*pp)-> p;
    //*(*pp) -> a
    **pp = 20;

    printf("%d \n", a);
    printf("\n");

    int arr[10]; //Integer array {int, int, int, int, int, int, int, int, int, int}

    char ch[5]; //char array {char, char, char, char, char}

    int* parr[5]; //Integer pointers array  {int* ,int* ,int* ,int* ,int*}

    char* chr[5]; //char pointers array {char* ,char* ,char* ,char* ,char*}
    printf("\n");
    int x = 10;
    int y = 11;
    int z = 12;
    int* arrr[3] = {&x, &y, &z};
    int i = 0;
    for(i = 0; i < 3; i++){
        printf("%d \n", *arrr[i]); //the value it points to
        printf("%p \n", arrr[i]); //the address
    }



    printf("\n");
    return 0;
}
