#include <stdio.h>

int main()
{
    int line = 0;
    scanf("%d", &line);
    int i = 0;
    //above 7 line
    for(i = 0; i < line; i++){
        
        int j = 0;
        for(j = 0; j < line - i - 1; j++){
            printf(" ");
        }
        for(j = 0; j < 2*i + 1; j++){
            printf("*");
        }
        printf("\n");
    }
    
    //below 6 line
    for(i = 0; i < line - 1; i++){
        int j = 0;
        for(j = 0; j <= i; j++){
            printf(" ");
        }
        for(j = 0; j < (line - i - 1)*2 - 1; j++){
            printf("*");
        }
        printf("\n");
    }
    return 0;
}