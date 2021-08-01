#include <stdio.h>
#include <string.h>

int main() {


    int a = 10;
    int x = 0;
    int y = 20;

    //a = x = y + 1;

    //1st: y + 1 = 21
    //2nd: x = y = 21
    //3rd: a = x = 21

    x = y + 1;
    a = x;
    //this is better than line 10

    printf("%d\n", x);
    printf("%d\n", a);


    // >>= operator

    int e = 10;
    e = e >> 1;
    e >>= 1;

    int f = 10;
    f = f + 10;
    f += 10;


    //Unary operator
    // ！ Logical inverse operator
    printf("\n");

    int z = 5;
    int c = !z ;
    printf("%d\n", c);

    if(z){// if z is true
        printf("Hi!\n");
    }
    if(!z){// if not z or if z is false
        printf("Bye!\n");
    }

    printf("\n");
    // - operator
    int aa = 10;
    aa = -aa;
    printf("%d\n", aa);
    aa = -aa;
    printf("%d\n", aa);
    //the address is the first byte of aa in memory

    printf("\n");
    // & operator
    int bb = 10;
    int* bbb = &bb;
    printf("%d\n", bb);
    printf("%p\n", &bb);
    printf("%d\n", *bbb);
    printf("%p\n", bbb);

    *bbb = 20;
    printf("%d\n", bb);
    printf("%p\n", &bb);
    printf("%d\n", *bbb);
    printf("%p\n", bbb);

    int arr[10] = {0};
    printf("%p\n", arr); // the address of the 1st element in arr
    printf("%p\n", &arr[0]); // the address of the 1st element in arr
    printf("%p\n", &arr[9]); // the address of the 10th element in arr
    printf("%p\n", &arr); // the address of the arr


    printf("\n");
    //sizeof is not a function, it's actually an operator
    //sizeof is to calculate the size of the variable

    char arrr[10] = "abc";
    printf("size of arrr is with sizeof%d\n", sizeof(arrr));//the size of arrr -> 10
    printf("size of arrr is with strlen%d\n", strlen(arrr));//the length before \0 -> 3
    printf("\n");
    int o = 10;
    printf("size of %d is %d\n", o, sizeof(o));
    printf("size of int is %d\n", o, sizeof(int));
    printf("size of o is %d\n", o, sizeof o);
    printf("\n");

    int m = 5;
    short n = 10;
    printf("n = m + 2 is %d\n", n = m + 2);
    printf("size of sizeof(m = n + 2) is %d\n", sizeof(m = n + 2)); // -> 4
    printf("size of sizeof(n = m + 2) is %d\n", sizeof(n = m + 2)); // -> 2
    printf("size of n is %d\n", n); // -> 10
    //explanation:
    //m is 4 byte
    //n is 2 byte
    //there is no way put 4 byte into 2 byte
    //so m + 2 cannot been put into n
    //n stay same here

    //why line 99 is ->2
    //cuz sizeof will calculate the size of the type not the value
    //what's insiede sizeof() will not be calculated
    //inside is a short so it's 2

    printf("\n");
    int yy = 0;
    //yy -> 00000000 00000000 00000000 00000000
    int zz = ~yy;
    printf("yy is %d\n", yy);
    //zz -> 11111111 11111111 11111111 11111111 ones
    //zz -> 11111111 11111111 11111111 11111110 -1
    //zz -> 10000000 00000000 00000000 00000001 sign bit stay others turn
    //zz -> -1
    printf("zz after ~yy is %d\n", zz);
    printf("\n");

    int example = 13;
    printf("example is initialized with %d\n", example);
    //example -> 00000000 00000000 00000000 00001101
    //how to get -> 00000000 00000000 00000000 00001111 1 << 1;
    //use |
    //if we have -> 00000000 00000000 00000000 00001111
    example |= (1 << 1);
    printf("example now is %d\n", example);
    //if we have -> 00000000 00000000 00000000 00001111
    //how to get -> 00000000 00000000 00000000 00001101


    //we can use   -> 11111111 11111111 11111111 11111101
    //compare with -> 00000000 00000000 00000000 00001111
    //use &
    //if we 1 << 1 and then ~
    //we will get -> 00000000 00000000 00000000 00001101

    example &= (~(1 << 1));
    printf("example now is %d\n", example);

    printf("\n");
    // ++ and --

    int cc = 10;
    printf("cc now is %d\n", cc);
    int dd = cc++; // cc first and then cc + 1
    int ddd = ++cc; // cc + 1 first

    printf("dd now is %d\n", dd);
    printf("ddd now is %d\n", ddd);
    printf("\n");

    int ee = 10;
    printf("ee now is %d\n", ee);
    int ff = ee--;
    printf("ee now is %d\n", ee);
    printf("ff now is %d\n", ff);
    int fff = --ee;
    printf("ee now is %d\n", ee);
    printf("fff now is %d\n", fff);

    // -- or ++ is after, then -- after using
    // -- or ++ is ahead, then -- before using

    return 0;
}
