#include <stdio.h> 

//the size of union, normally is the ladgest data type
//or it will need be the n times of ladgest data type

union U1 {
    char c[5]; //5 1
    int i; // 4 4
};
//8 byte



union U2 {
    short c[7]; // 14 2
    int i; // 4 4
};
//16 byte


int main () {
    printf("%d\n", sizeof(union U1));
    printf("%d\n", sizeof(union U2));
    return 0;
}