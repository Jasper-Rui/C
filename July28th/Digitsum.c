#include <stdio.h>
#include <assert.h>


int DigitSum(int input){
    int sum = 0;

    if(input > 9){
        return input%10 + DigitSum(input/10); 
    }
    else{
        return input;
        }

}

int main(){

    int input = 1234;
    int input1 = 1729;
    printf("Result is: %d \n", DigitSum(input));
    printf("Result is: %d \n", DigitSum(input1));
    return 0;
}