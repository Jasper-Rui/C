#include <stdio.h>
#include <math.h>

int is_Prime(int input){

    for(int i = 2; i <= sqrt(input); i++) {
        if (input % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    for (int i = 100; i <= 200; ++i) {
        if(is_Prime(i) == 1)
            printf("%d ", i);
    }
    return 0;
}
