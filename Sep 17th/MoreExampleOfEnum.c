#include <stdio.h>

enum OPTION {
    Exit,
    Add,
    Sub,
    Mul,
    Div
};

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
        case Add:
            break;
        case Sub:
            break;
        case Mul:
            break;
        case Div:
            break;
        default Exit:
            break;
        }
    } while (input);

    
    return 0;
}