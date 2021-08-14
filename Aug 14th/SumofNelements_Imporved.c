#include <stdio.h>
#include <math.h>

int main(){

    int input1, input2;
    scanf("%d%d", &input1, &input2);

    int arr[input1];
    int sum = input2;
    //suppose input = 2
    //i = 0 -> input -> 2
    //i = 1 -> input * (10 ^ i) + arr[i - 1] -> 22
    //i = 2 -> input * (10 ^ i) + arr[i - 1] -> 222
    arr[0] = input2;
    printf("%d \n", arr[0]);
    for(int i = 1; i < input1; i++){
        arr[i] = input2 * pow(10,i) + arr[i - 1];
        printf("%d \n", arr[i]);
        sum += arr[i];
    }

    printf("Sum is %d \n", sum);
    return 0;
}