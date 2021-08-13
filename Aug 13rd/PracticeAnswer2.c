#include <stdio.h>
#include <ctype.h>

int main(){



    char input;
    while(scanf(" %c", &input) != EOF){
        if(tolower(input) != 'o' && tolower(input) != 'a' && tolower(input) != 'i' && tolower(input) != 'e' && tolower(input) != 'u'){
            printf("Consonant\n");
        }
        else{
            printf("Vowel\n");
        }
    }
    /*
    while(scanf(" %c", &input) != EOF){
            if(tolower(input) == 'o' || tolower(input) == 'a' || tolower(input) == 'i' || tolower(input) == 'e' || tolower(input) == 'u'){
                printf("Vowel\n");
            }
            else{
                printf("Consonant\n");
            }
        }*/

    return 0;
}