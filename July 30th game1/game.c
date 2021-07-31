//
// Created by Jasper on 2021/7/30.
//
#include "game.h"



void InitBoard(char board[ROWS][COLS], int rows, int cols, char set){
    int i = 0;
    for(i = 0; i < rows; i++){
        int j = 0;
        for (j = 0; j < cols; j++) {
            board[i][j] = set;
        }
    }
}



void DisplayBoard(char board[ROWS][COLS], int row, int col){
    int i = 0;
    printf("------------------------\n");
    for(i = 0; i <= 9; i++){
        printf("%d ", i);
    }
    printf("\n");



    for(i = 1; i <= row; i++){
        int j = 0;
        printf("%d ", i);
        for (j = 1; j <= col; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("------------------------\n");
}


void SetMine(char board[ROWS][COLS], int row, int col){
    int count = EASY_COUNT;

    while (count){

        //generate random coordinate
        int x = rand() % row + 1;
        int y = rand() % col + 1;

        //set up boom
        if(board[x][y] != '1'){
            board[x][y] = '1';
            count--;
        }

    }
}



void DetectMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col) {
    printf("Please enter the coordinate you want check: \n");
    int win = 0;
    int x = 0, y = 0;
    while (win < row * col - EASY_COUNT) {
        scanf("%d %d", &x, &y);
        if (x >= 1 && x <= row && y >= 1 && y <= col) {
            if(mine[x][y] == '1'){
                printf("Sorry, you are dead!\n");
                DisplayBoard(mine, ROW, COL);
                break;
            }
            else{
                int count = GetMineCount(mine, x, y);
                show[x][y] = count + '0';
                //here count is number
                //in ASCII
                //'3' - '0' = 3
                // if we want '3' => '0' + 3
                DisplayBoard(show, row, col);
                win++;
            }
        }
        else {
            printf("Wrong coordinate, please enter it again.\n");
        }
    }
    if(win == row * col - EASY_COUNT){
        printf("You Win! \n");
        DisplayBoard(mine, row, col);
    }
}

int GetMineCount(char mine[ROWS][COLS], int x, int y){
    // 2 ways
    int count = 0;
    for (int i = x - 1; i <= x + 1; i++){
        for (int j = y - 1; j <= y + 1; j++){
            count += mine[i][j] - '0';
        }
    }
    //return count;
    return mine[x-1][y] + mine[x-1][y-1] + mine[x][y-1] + mine[x+1][y-1] +
            mine[x+1][y] + mine[x+1][y+1] + mine[x][y+1] + mine[x-1][y+1] - 8*'0';

}















