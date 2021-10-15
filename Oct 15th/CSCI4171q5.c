#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printbinchar(char character){
    char output[9];
    itoa(character, output, 2);
    printf("%s\n", output);
}

int main(){
    //looks like itoa in not a standard library function in c
    printbinchar('a');
}