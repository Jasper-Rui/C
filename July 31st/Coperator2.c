#include <stdio.h>



void CheckHowManyOne(int input){
    int count = 0;
    for(int i = 0; i < 32; i++){
        //idea here is to compare each index of a int in binary
        //if the last index of a int is 1
        //then the number compare with 1 in input & 1 will result 1
        //loop it 32 times and each we move the int will input >> 1
        //if there is 1, then count++
        //result will be the number of 1's of a int in binary
        if((input & 1) == 1){
            count++;
        }
        input = input >> 1;

        //example
        //if input = 5， int binary\
        //5: 00000000 00000000 00000000 00000101
        //2^0*1 + 2^2*1 = 1 + 4 = 5
        //5 & 1
        //5: 00000000 00000000 00000000 00000101
        //1: 00000000 00000000 00000000 00000001
        // : 00000000 00000000 00000000 00000001
        //here we get 1 as a result

        //then we do right shift with 1
        //5: 00000000 00000000 00000000 00000101 -> goes to
        //?: 00000000 00000000 00000000 00000010
        //2: 00000000 00000000 00000000 00000010
    }
    printf("There are %d 1's in input\n", count);

}
int main() {

    //&
    //|
    //^
    int a = 3;
    int b = -2;
    int c = a & b;

    //a: 00000000 00000000 00000000 00000011
    //b: 11111111 11111111 11111111 11111110
    //c: 00000000 00000000 00000000 00000010

    //b: 10000000 00000000 00000000 00000010
    // : 11111111 11111111 11111111 11111101
    // : 11111111 11111111 11111111 11111110
    //based on Sign-Magnitude, ones' Complement, twos' Complement

    printf("%d\n", c);
    // %d here, we what pint c with its + or -
    // %u do not need the symbol
    printf("\n");

    //Sign-Magnitude -> turn around ->  ones' Complement -> +1 -> twos' Complement
    int d = a | b;
    //a: 00000000 00000000 00000000 00000011
    //b: 11111111 11111111 11111111 11111110
    //d: 11111111 11111111 11111111 11111111
    printf("%d\n", d);
    //d: 11111111 11111111 11111111 11111111 twos' Complement -1 and turn around
    //sign bit stay same
    //d: 10000000 00000000 00000000 00000001


    printf("\n");
    int e = a ^ b;
    //^: both 1 or 0 -> 0, others -> 1
    //a: 00000000 00000000 00000000 00000011
    //b: 11111111 11111111 11111111 11111110
    //d: 11111111 11111111 11111111 11111101 -> twos' Complement -1 and turn around

    //sign bit stay same
    //d: 11111111 11111111 11111111 11111100 after -1
    //d: 10000000 00000000 00000000 00000011 after -1

    printf("%d\n", e);

    printf("\n");

    int f = 15;
    // f & 1
    //f: 00000000 00000000 00000000 00001111
    //   00000000 00000000 00000000 00000001

    //   00000000 00000000 00000000 00000000

    printf("%d\n", f & 1);
    printf("%d\n", f | 1);

    printf("%d\n", f ^ 1); // 14
    // f >> 1 = 14
    //printf("%d\n", 1 << 1);

    //what stores in memory is ones complement

    int aa = 3;
    int bb = 5;

    printf("aa = %d bb = %d\n", aa, bb);
    int tmp = 0;
    tmp = aa;
    aa = bb;
    bb = tmp;
    printf("aa = %d bb = %d\n", aa, bb);

    // second way
/*    aa = aa + bb; //3 + 5 = 8 -> aa
    bb = aa - bb; //8 - 5 = 3 -> bb
    aa = aa - bb; //8 - 3 = 5 -> aa*/

    //but what if the sum of aa and bb are over the limit of int (overflow)
    //we need another way
    //use ' ^ '
    aa = aa ^ bb;
    //aa: 011
    //bb: 101
    //aa: 110
    //aa: 6

    // ^ in englist is XOR
    bb = aa ^ bb;
    //aa: 110
    //bb: 101
    //bb: 011
    //bb: 3

    aa = aa ^ bb;
    //aa: 110
    //bb: 011
    //aa: 101
    //aa: 5

    //now aa = 5
    //now bb = 3


    //a ^ a = 0
    //0 ^ a = a
    //a ^ a ^ b = b
    //a ^ b ^ a = b

    CheckHowManyOne(5);
    //it should return 2;
    CheckHowManyOne(-1);
    //it should be 32

    return 0;
}
