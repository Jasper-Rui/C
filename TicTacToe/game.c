#include "game.h"


void InitBoard(char board[ROW][COL], int row, int col)
{
    int i = 0;
    for(i = 0; i < row; i++)
    {
        int j = 0;
        for (j = 0; j < col; j++)
        {
            board[i][j] = ' ';
        }
    }
}


void DisplayBoard(char board[ROW][COL], int row, int col)
{
    int i = 0;
    for(i = 0; i < row; i++)
    {
        int j = 0;
        for (j = 0; j < col; j++)
        {
            printf(" %c ", board[i][j]);
            if(j < col - 1)
            {
                printf("|");
            }
        }
        printf("\n");

        if(i < row - 1)
        {
            for (j = 0; j < col; j++)
            {
                printf("---");
                if(j < col - 1)
                {
                    printf("|");
                }                
            }            
        }
        printf("\n");
    }
}



void PlayerMove(char board[ROW][COL], int row, int col)
{
    printf("Player move:\n");

    int x = 0;
    int y = 0;
    
    while(1)
    {
        printf("Please enter a movement:");
        scanf("%d%d", &x, &y);
        if(x >= 1 && x <= row && y >= 1 && y <= col)
        {
            if(board[x - 1][y - 1] == ' ')
            {
                board[x - 1][y - 1] == '*';
                break;
            }
            else
            {
                printf("There is already a tic, please try again.\n");
            }
        }
        else
        {
            printf("Invalid cordinate, please enter again.\n");
        }       
    }
}


void ComputerMove(char board[ROW][COL], int row, int col)
{
    int x = 0;
    int y = 0;
    printf("Computer move\n");

    while(1)
    {
        x = rand()%row; //anything % 3 is less than 3
        y = rand()%col;
        if(board[x][y] == ' ')
        {
            board[x][y] == '#';
            break;
        }
    }
}


//5 different situations
//1 player win
//2 computer win
//3 draw
//4 out of board
char isWin(char board[ROW][COL], int row, int col)
{
    // 1. win or not
    // 2. draw
    // 3. continue

}