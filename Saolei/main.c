#include <stdio.h>
#include "game.h"


void menu(){
    printf("***********************************************************\n");
    printf("*******************      1. Play    ***********************\n");
    printf("*******************      0. Exit    ***********************\n");
    printf("***********************************************************\n");
}

void Game(){

    char mine[ROWS][COLS] = { 0 }; // boom info
    char show[ROWS][COLS] = { 0 }; //boom detected

    //initialize the board
    InitBoard(mine, ROWS, COLS, '0');
    InitBoard(show, ROWS, COLS, '*');

/*    DisplayBoard(mine, ROW, COL);
    printf("\n");
    DisplayBoard(show, ROW, COL);
    printf("\n");*/


    SetMine(mine, ROW, COL);
    DisplayBoard(mine, ROW, COL);
    DisplayBoard(show, ROW, COL);
    printf("\n");

    DetectMine(mine, show, ROW, COL);

}

int main() {
    int input = 0;
    srand((unsigned int) time (NULL));

    do {
        menu();
        printf("Please make a choice:");
        scanf("%d", &input);
        switch (input) {
            case 1:
                printf("Saolei\n");
                Game();
                break;
            case 0:
                printf("Thank you for playing\n");
                break;
            default:
                printf("Invalid choice\n");
                break;
            }
        } while (input);

    return 0;
}
