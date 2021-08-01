#include <stdio.h>


//if the input is 100000000000000000 then the old BF is too slow
long long int gcd (long long int small, long long int large);


long long int gcd (long long int small, long long int large){

    //here we have 8 and 100
    //if 100 % 8 = 4
    //     8 % 4 = 0
    //then 4 is the gcd
    long long int remaining = large % small;
    
    return remaining;
}





int main(){

    long long int input1, input2;
    scanf("%ld%ld", &input1, &input2);
    long long int  small = input1 > input2 ? input2 : input1;
    long long int  large = input1 > input2 ? input1 : input2;

    printf("Testing: %d\n", gcd(small,large));

    //here we assign the samller value to small
    //here we assign the larger value to large

    return 0;
}
