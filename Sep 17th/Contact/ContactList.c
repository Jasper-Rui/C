#include <stdio.h>

enum OPTION {
    exit,
    add,
    del,
    search,
    modify,
    show,
    sort,
};

void menu () {
    printf("****************************************\n");
    printf("********1. add      2. del    **********\n");
    printf("********3. search   4. modify **********\n");
    printf("********5. show     6. sort   **********\n");
    printf("********0. exit               **********\n");
}

int main () {
    int input = 0;
    do{
        menu();
        printf("Please make a choice >: ");
        scanf("%d", &input);

        switch (input)
        {
        case add:
            break;
        case del:
            break;
        case search:
            break;
        case modify:
            break;
        case show:
            break;
        case sort:
            break;
        case exit:
            printf("Exit \n");
            break;
        default :
            break;
        }
    } while (input);

    
    return 0;
}