#include <stdio.h>
#include "game.h"


void menu(){
    printf("***********************************************************\n");
    printf("*******************      1. Play    ***********************\n");
    printf("*******************      0. Exit    ***********************\n");
    printf("***********************************************************\n");
}

void Game(){
    //process
    char board[ROW][COL];
    char ret = 0;
    InitBoard(board, ROW, COL);

    //print the board
    DisplayBoard(board, ROW, COL);

    //play
    while(1)
    {
        PlayerMove(board, ROW, COL);
        DisplayBoard(board, ROW, COL);
        ret = isWin(board, ROW, COL);
        if(ret != 'C')
        {
            break;
        }
        ComputerMove(board, ROW, COL);
        DisplayBoard(board, ROW, COL);
        ret = isWin(board, ROW, COL);

        if(ret != 'C')
        {
            break;
        }
    }

    if(ret == '*')
    {
        printf("Player Win!\n");
    }
    else if(ret == '#')
    {
        printf("Computer Win!\n");
    }
    else
    {
        printf("Draw\n");
    }
    DisplayBoard(board, ROW, COL);


}



int main()
{
    int input = 0;
    srand((unsigned int) time (NULL));

    do
    {
        menu();
        printf("Please make a choice: ");
        scanf("%d", &input);

        switch (input)
        {
            case 1:
                printf("Tic Tac Toe Game!\n");
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