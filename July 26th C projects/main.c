#include <stdio.h>
#include <assert.h>
#include <limits.h>

//program1

//input: a integer
//expected output: each number of the integer
//example: input 123 -> output 1 2 3

//this is a normal way
int print_number(int input){
    assert(input < INT_MAX);
    int arr[] = {};
    int i = 0;

    while (input > 9 || input < -9){
        arr[i] = input % 10;
        input = input / 10;
    }

    int Length  = sizeof(arr)/sizeof(int);

    for (int j = Length; j >= 0 ; j--) {
        printf("%d ", arr[j]);
    }

    printf("%d ", input);
}
//above is the wrong answer


//using recursion
void print(unsigned int n)
{
    if(n>9)
        print(n/10);
    printf("%d ", n%10);
}

int main() {

    int input;
    printf("Please enter a valid integer: ");
    scanf("%d", &input);
    assert(&input != NULL);
    print(input);

    return 0;
}
