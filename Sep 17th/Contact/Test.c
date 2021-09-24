#include "Contact.h"

enum OPTION {
    Exit,
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

    //initialize a contact list
    struct Contact con;
    InitContact(&con);

    int input = 0;
    do{
        menu();
        printf("Please make a choice >: ");
        scanf("%d", &input);

        switch (input)
        {
        case add:
            AddContact(&con);
            break;
        case del:
            DelContact(&con):
            break;
        case search:
            break;
        case modify:
            break;
        case show:
            ShowContact(&con);
            break;
        case sort:
            break;
        case Exit:
            printf("Exit \n");
            break;
        default :
            printf("Wrong Input \n");
            break;
        }
    } while (input);

    
    return 0;
}