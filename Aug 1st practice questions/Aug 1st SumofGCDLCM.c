#include <stdio.h>
int main(){

    long input1, input2, gcd, lcm;
    scanf("%d%d", &input1, &input2);

    long small,large;
    if(input1 > input2){
        small = input2;
        large = input1;
    }
    else{
        small = input1;
        large = input2;
    }

    for(int i = 1; i <= small; i++){
        if(input1 % i == 0 && input2 % i == 0){
            gcd = i;
        }
    }

    if(gcd != 1){
        lcm = (large / gcd) *small;
    }
    else{
        gcd = input1 * input2;
    }
    
    long result = gcd + lcm;
    printf("%ld", result);
    return 0;
}