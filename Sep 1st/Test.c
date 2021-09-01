#include <stdio.h>

int main(){

    char ch = 127;
    int sum = 200;
    ch += 1;
    sum += ch;
    //printf("%d\n", ch);
    printf("%d\n", sum);


    return 0;
}