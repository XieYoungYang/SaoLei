#define _CRT_SECURE_NO_WARNINGS
#include "game.h"

void game()
{
	char mine[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };
	InitBoard(mine, '0');
	InitBoard(show, '*');
	DisplayBoard(show);
	SetMine(mine);
	DisplayBoard(mine);
	FineMine(mine,show);
}

void menu()
{
	printf("***************************************\n");
	printf("***************1.play 0.exit***********\n");
	printf("***************************************\n");
}

void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏!\n");
			break;
		default:
			printf("选择错误!请重新选择!\n");
		}
	} while (input);
}

int main()
{
	test();
	return 0;
}