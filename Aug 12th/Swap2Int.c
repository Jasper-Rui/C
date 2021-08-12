#include <stdio.h>

void swap_one(int a, int b){
    printf("Before swap, the result goes to %d %d\n", a, b);
    //a = 3  b = 5;
    a = a + b; // a = 3 + 5 = 8 a = 8 b = 5
    b = a - b; // b = 8 - 5 = 3 a = 8 b = 3 
    a = a - b; // a = 8 - 3 = 5 a = 5 b = 3
    printf("After swap, the result goes to %d %d\n", a, b);

}

void swap_two(int a, int b){
    printf("Before swap, the result goes to %d %d\n", a, b);
    //a = 3  b = 5;
    a = a * b; // a = 3 + 5 = 8
    b = a / b; // b = 8 - 5 = 3
    a = a / b; // a = 8 - 3 = 5

    printf("After swap, the result goes to %d %d\n", a, b);

}

void swap_three(int a, int b){
    printf("Before swap, the result goes to %d %d\n", a, b);
    //a = 3  b = 5;
    a = a ^ b; // a = 3 + 5 = 8
    b = a ^ b; // b = 8 - 5 = 3
    a = a ^ b; // a = 8 - 3 = 5

    printf("After swap, the result goes to %d %d\n", a, b);

}


int main(){

    int a;
    int b;
    scanf("%d%d", &a, &b);
    printf("With swap_one\n");
    swap_one(a, b);
    printf("With swap_two\n");
    swap_two(a, b);
    printf("With swap_three\n");
    swap_three(a, b);


    return 0;
}