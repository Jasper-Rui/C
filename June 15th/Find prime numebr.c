#include <stdio.h>

int IsPrime(int number) {
    int i;
    for (i=2; i<number; i++) {
        if (number % i == 0 && i != number){
            return 0;
        }
    }
    return 1;
}

int main()
{
    int n = 100;
    for(n = 100; n <= 200; n++){
        if(IsPrime(n) ==  1){
            printf("%d ", n);
        }
    }
    return 0;
}

    