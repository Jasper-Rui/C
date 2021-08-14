#include <stdio.h>
#include <math.h>

int main(){

    int input;
    scanf("%d",&input);

    int arr[5];
    int sum = input;
    //suppose input = 2
    //i = 0 -> input -> 2
    //i = 1 -> input * (10 ^ i) + arr[i - 1] -> 22
    //i = 2 -> input * (10 ^ i) + arr[i - 1] -> 222
    arr[0] = input;
    for(int i = 1; i < 5; i++){
        arr[i] = input * pow(10,i) + arr[i - 1];
        printf("%d \n", arr[i]);
        sum += arr[i];
    }

    printf("Sum is %d \n", sum);
    return 0;
}