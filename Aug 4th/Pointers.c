#include <stdio.h>

int main() {


    //Pointers
    //for a x32 computer
    //we can have up to 2^32 memory address to control
    // -> 0.5 Gb

    //in binary it's 1 0000000 0000000 0000000 0000000 -> 2 ^ 32
    //Hex -> 4,294,967,296 bit
    //    -> 4 Gb

    char ccccc; //1 byte -> 8 bit
    int aaaa;  //4 byte -> 32 bit
    //using bit to memory address is too small

    //normally
    //32-bit platform -> 4 byte for pointers
    //64-bit platform -> 8 byte for pointers

    printf("\n");

//    int a = 10;
//    int* pa = &a;
//    char c = 'w';
//    char* pc = &c;

    int a = 10;
    int* pa = &a;
    char* pc = &a;
    printf("%p \n", pa);
    printf("%p \n", pc);

    printf("%p \n", pa + 1);
    printf("%p \n", pc + 1);
    //result here is

    //0061FEC4
    //0061FEC4
    //0061FEC8
    //0061FEC5
    //this means the type of pointers will define the meaning of  +1
    //for char* + 1, it will move 8 bit
    //for int* + 1, it will move 32 bit
    printf("\n");

    int arr[10] = {0};
    int* p = &arr;
    int i  = 0;
    for(i = 0; i < 10; i++){
        *(p + i) = 1;
    }
    for(i = 0; i < 10; i++){
        printf("%d \n",*(p + i));
    }
    //do not ever do things like
    //int* neverdothis;
    //cuz u will never know where it points to

    //or

    for(i = 0; i <= 10; i++){
        //*(p + i) = 1;
        //here the arr only has 10 elements but the loop will go trought 11 times
        //which means it will target arr[11], the address of arr[11] is 'Out of boundary'
    }



    printf("\n");
    return 0;
}
