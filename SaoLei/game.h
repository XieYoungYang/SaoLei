#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 3
#define COL 3
#define ROWS ROW+2
#define COLS COL+2
#define EASY_COUNT 8

void InitBoard(char board[ROWS][COLS], char set);
void DisplayBoard(char board[ROWS][COLS]);
void SetMine(char board[ROWS][COLS]);
void FineMine(char mine[ROWS][COLS], char show[ROWS][COLS]);

