#ifndef __GAME_HEADER
#define __GAME_HEADER

#define ROW 3
#define COL 3
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Initialize board
void InitBoard(char board[ROW][COL], int row, int col);

void DisplayBoard(char board[ROW][COL], int row, int col);

void PlayerMove(char board[ROW][COL], int row, int col);

void ComputerMove(char board[ROW][COL], int row, int col);

char isWin(char board[ROW][COL], int row, int col);

#endif