#include <stdio.h>
#include <ctype.h>

int main(){
    char input;
    while(scanf(" %c", &input) != EOF){
        switch(input){
            case 'A':
            case 'a':
            case 'E':
            case 'e':
            case 'I':
            case 'i':           
            case 'O':
            case 'o':
            case 'U':
            case 'u':
                printf("Vowel\n");
                break;
            default:
                printf("Consonant\n");
        }
    }
    return 0;
}