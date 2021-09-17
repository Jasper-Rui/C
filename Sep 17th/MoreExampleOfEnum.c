#include <stdio.h>

enum OPTION {
    Exit,
    Add,
    Sub,
    Mul,
    Div
};

void menu () {
    printf("****************************************\n");
    printf("********1. add       2. sub  ***********\n");
    printf("********3. mul       4. div  ***********\n");
    printf("********0. Exit              ***********\n");
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
        case Exit:
            break;
        default :
            break;
        }
    } while (input);

    
    return 0;
}