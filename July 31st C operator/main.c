#include <stdio.h>

int main() {
    //C operator
    //+ - * / %
    //<< >>
    //&  | ^
    //= ==  -=  += ^=
    //sizeof ! ++ --
    // > >= < <=
    //&& ||
    // ?:
    //,
    // [] () {} ->
    //

    int ret = 9 / 2;
    double ret1 = 9 / 2;
    double ret2 = 9.0 / 2;
    double ret3 = 9 / 2.0;

    int ret4 = 9 % 2;

    printf("'\\' operator\n");
    printf("%d \n", ret);
    printf("%f \n", ret1);
    printf("%f \n", ret2);
    printf("%f \n", ret3);
    printf("\n");

    printf("%% operator\n");
    printf("%d \n", ret4);

    printf("\n");
    printf("<< and >> operator\n");

    // >> right shift operator
    // << left shift operator


    //for positive int
    //Sign-Magnitude: from int to binary
    //ones' Complement:
    //two's Complement: one's complement + 1

    int a = 5; //4 bytes = 32 bits =
    //below is a
    //5 => 00000000 00000000 00000000 00000101
    //ones' Complement: 00000000 00000000 00000000 00000101
    //two's Complement: 00000000 00000000 00000000 00000101
    // left shift, in binary
    int b = a << 1;
    //idea: abandon left, fill right with 0
    //below is b
    //5 => 00000000 00000000 00000000 00001010 => 2^1 + 2^3 = 10
    //ones' Complement: 00000000 00000000 00000000 00000101
    //two's Complement: 00000000 00000000 00000000 00000101
    printf("%d \n", b);

    //for int, what stores in memory is two's Complement
    int c = -1;
    //-1 => 10000000 00000000 00000000 00000001
    //ones' Complement: 11111111 11111111 11111111 11111110
    //two's Complement: 11111111 11111111 11111111 11111111
    int d = c << 1;
    //-1 => 10000000 00000000 00000000 00000001
    //ones' Complement: 11111111 11111111 11111111 11111110
    //two's Complement: 11111111 11111111 11111111 11111111 this is what store in memory

    //after it << 1
    //two's Complement: delete the first 1 1111111 11111111 11111111 111111110 and fill with one 0

    //but what print is Sign-Magnitude
    //So here, in order to make the two's Complement to Sign-Magnitude
    //do two's Complement - 1
    //two's Complement: 11111111 11111111 11111111 111111110 then -1
    //so it becomes: 11111111 11111111 11111111 111111101
    //第一位不变 其余变化
    //signed number representations stay same others turn around
    //then it goes to 10000000 00000000 00000000 00000010

    printf("%d \n", d);//what print here is the Sign-Magnitude



    int e = 5;
    int f = e >> 1;
    //here a is
    //00000000 00000000 00000000 00000101
    //after shift
    // 00000000 00000000 00000000 00000101

    //there are 2 different right shift
    //Logical shift right -> abandon right, fill left with 0

    //Arithmetic shift right -> abandon right, fill left with signed number representations


    printf("\n");
    printf("%d\n", f);

    int g = -1;
    int h = g >> 1;
    printf("\n");
    printf("%d\n", h);

    //most of the IDE are using Arithmetic shift right



    return 0;
}
