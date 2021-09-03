#include <stdio.h>


struct test
{
    /* data */
    int num;
    char* pcName;
    short sDate;
    char cha[2];
    short sBa[4];

}*p;

//assume p is 0x100000
//assume test is a 20 byte struct

int main () {

    p = (struct test*) 0X00100000;
    //p is a struct pointer here
    printf("%p\n", p + 0x1);//since p is a pointer, type is struct, we add 0x1 -> add 1 -> add one size of struct
    //which is add 20 byte -> in hex 14 -> 1*16^(1) +  4 *(16^0) 
    //result is -> 0x00100014
    printf("%p\n", (unsigned long)p + 0X1);
    //here we convert p to long type
    //it's simply like 1 + 1 = 2
    //by adding 1
    //result is 0x00100001
    printf("%p\n", (unsigned int*)p + 0X1);
    //here we convert it to an integet type pointer, so it an address with 4 byte
    //-> 0x00100004
    return 0;
}