#include <stdio.h>

void menu () {
    printf("****************************************");
    printf("********1. add       2. sub  ***********");
    printf("********3. mul       4. div  ***********");
    printf("********0. Exit              ***********");
}

int main () {
    int input = 0;
    do{
        menu();
        printf("Please make a choice >: ");
        scanf("%d", &input);

        switch (input)
        {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        default:
            break;
        }
    } while (input);

    
    return 0;
}