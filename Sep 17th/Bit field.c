#include <stdio.h>

struct BitField
{
    int _a: 2; //2bits
    int _b: 6; //6bits
    int _c: 10; //10bits
    int _d: 20; //20bits
};

struct s
{
    /* data */
    char a : 3;
    char b : 4;
    char c : 5;
    char d : 6;
};


int main () {

    printf("%d\n", sizeof(struct BitField));
    //result is 8

    printf("%d\n", sizeof(struct s));
    


    return 0;
}