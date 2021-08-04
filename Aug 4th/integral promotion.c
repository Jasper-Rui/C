#include <stdio.h>

int main() {
    char a = 3;
    //char a, here a is 1 byte -> 8 bit
    //here a will be 00000011
    //3 -> 00000000 00000000 00000000 00000011
    char b = 127;

    //127 -> 00000000 00000000 00000000 00111111 -> 2^7 - 1
    //2^7 -> 00000000 00000000 00000000 01000000
    //b -> 00111111

    //both a and b are char -> 1 byte
    //so we need integral promotion


    char c = a + b;
    //a -> 00000011
    //a -> after promotion -> 00000000 00000000 00000000 00000011
    //        +
    //b -> 00111111
    //b -> after promotion -> 00000000 00000000 00000000 00111111

    // 00000000 00000000 00000000 00000011
    //        +
    // 00000000 00000000 00000000 00111111
    //result -> 00000000 00000000 00000000 10000010
    //c is 1 byte -> 10000010
    //c -> integral promotion
    //c -> 11111111 11111111 11111111 10000010 twos complement
    //c -> -1 -> 11111111 11111111 11111111 10000001
    //c -> turn -> 10000000 00000000 00000000 01111110

    printf("%d\n", c);


    printf("\n");
    char x = 0xb6; // char means we have sign bit here
    short y = 0xb600;
    int z = 0xb6000000; // z do not need integral promotion but x and y need, so x, y will change
    if(x == 0xb6)
        printf("a\n");
    if(y == 0xb600)
        printf("b\n");
    if(z == 0xb6000000)
        printf("c\n");
    //result here is only c
    //why?

    //explanation:
    //integral promotion
    //x -> 0xb6 is 16 -> 11010110
    //x -> 11111111 11111111 11111111 11010110
    //x -> after it goes back to Sign-Magnitude it will not be the same as 0xb6

    printf("\n");
    //example2:

    char o = 1;
    printf("%u\n", sizeof(o));//1
    printf("%u\n", sizeof(+o));//4  integral promotion
    printf("%u\n", sizeof(-o));//4  integral promotion


    printf("\n");
    int u = 4;
    float f = 4.5;
    float sum = u + f;
    printf("%lf\n", sum);//8.500000
    //it will change the u type from int to float and then do the calculation

    printf("\n");

    //some tricky problems
    //example1:
    //who will calculate first?
    //a*b + c*d + d*f
    // 1  4  2  5  3
    //       or
    //a*b + c*d + d*f
    // 1  3  2  5  4
    //what if a b c d e f are different expression but contain same variables then that will be a big trouble
    //the only thing here we can make sure is * will go first, but we cannot determine which one will go 1st


    //example 2
    int ccc = 2;
    int result = ccc + --ccc;
    printf("ccc is %d\n", ccc);
    printf("result is %d\n", result); // here result is 2 not 3
    //because --ccc is calculated first and then ccc -> 1;
    //so it becomes 1 + 1;


    return 0;
}
