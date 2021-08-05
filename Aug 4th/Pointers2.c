#include <stdio.h>
//another example of Unauthorized access
int* test() {
    //step2: we creat a variable a and return the address of a
    int a = 10;
    return &a;
    //step3: after return, the a will be released
    //that means the memory of a here is freed

}



int main() {
    //step 1: we go into the function test
    int* p = test();
    //step4: even tho the address is returned, the value is gone
    //stack
    //___________
    //|         |
    //|         |
    //|         |
    //|         |
    //|         |
    //___________  // here is the stack for test()
    //|         |
    //|         |
    //___________
    //|         |  // here is the main part in stack
    //|         |
    //|         |   // here is the highest position of stack and where the p is stored




    //printf("haha \n");
    //printf("%p \n", p);

    //printf("%d \n", *p);

    printf("\n");
    //stack is used from high to low

    int a = 10;
    int b = 20;
    printf("%p\n", &a);  //0061FEC8
    printf("%p\n", &b);  //0061FEC4

    //key idea1: pointers must be initialized

    //example
    int c = 10;
    int* pc = &c;
    //or
    int* pcc = NULL;

    //key idea2: after using pointers, pointers must be freed or change to NULL
    printf("\n");
    int* ppp = 10;
    printf("%d\n", *ppp);





    return 0;
}
