#define _CRT_SECURE_NO_WARNINGS

#include "game.h"

void InitBoard(char board[ROWS][COLS], char set)
{
	int x = 0;
	for (x = 0; x < ROWS; x++)
	{
		int y = 0;
		for (y = 0; y < COLS; y++)
		{
			board[x][y] = set;
		}
	}
}

void DisplayBoard(char board[ROWS][COLS])
{
	int i = 0;
	int j = 0;
	for (j = 0; j <= COL; j++)
	{
		printf("%d ", j);
	}
	printf("\n");
	for (i = 1; i <= ROW; i++)
	{
		printf("%d ", i);
		for (j = 1; j <= COL; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}

void SetMine(char board[ROWS][COLS])
{
	int count = EASY_COUNT;
	while (count)
	{
		int x = rand() % ROW + 1;//1-9
		int y = rand() % COL + 1;//1-9
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}
	}
}

int get_mine_count(char mine[ROWS][COLS], int x, int y)
{
		return mine[x - 1][y] +
		mine[x - 1][y - 1] +
		mine[x][y - 1] +
		mine[x + 1][y - 1] +
		mine[x + 1][y] +
		mine[x + 1][y + 1] +
		mine[x][y + 1] +
		mine[x - 1][y + 1] - 8 * '0';

}
void FineMine(char mine[ROWS][COLS], char show[ROWS][COLS])
{
	int x = 0;
	int y = 0;
	int win = 0;
	while(win<ROW*COL-EASY_COUNT)
	{
		printf("请输入排查雷的坐标:>");
		scanf("%d%d", &x, &y);
		if ((x >= 1 && x <= ROW && (y >= 1 && y <= COL)))
		{
			if (mine[x][y] == '1')
			{
				printf("踩雷了,你没得了\n");
				DisplayBoard(mine);
				break;
			}
			else
			{
				int count = get_mine_count(mine, x, y);
				show[x][y] = count + '0';
				DisplayBoard(show);
				win++;
			}
		}
		else
		{
			printf("坐标非法,请重新输入!\n");
		}
	}
	if (win == ROW * COL - EASY_COUNT)
	{
		printf("恭喜恭喜,通关了\n");
		DisplayBoard(mine);
	}
}