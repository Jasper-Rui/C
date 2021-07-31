//
// Created by Jasper on 2021/7/30.
//

#ifndef SAOLEI_GAME_H
#define SAOLEI_GAME_H
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#define EASY_COUNT 80



void InitBoard(char board[ROWS][COLS], int rows, int cols, char set);

void DisplayBoard(char board[ROWS][COLS], int row, int col);

void SetMine(char board[ROWS][COLS], int row, int col);

void DetectMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);

int GetMineCount(char mine[ROWS][COLS], int row, int col);

#endif //SAOLEI_GAME_H
