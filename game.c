#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"



void InitBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}

//void DisplayBoard(char board[ROW][COL], int row, int col)
//{
//	int i = 0;
//	for (i = 0; i < row; i++)
//	{
//		printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
//		if(i<row-1)//少打印最后一行
//			printf("---|---|---\n");
//	}
//}
//


void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)//确定打印行数
	{
		int j = 0;
		for (j = 0; j < col; j++)//打印数据列
		{
			printf(" %c ", board[i][j]);//打印一个空格
			if (j < col - 1)//加入if不打印最后一个|
				printf("|");//打印一个|最后一个|不打印
		}
		printf("\n");
		if (i < row - 1)//最后一行---|---|---不进行打印
		{
			int j = 0;
			for (j = 0; j < col; j++)//打印分割列
			{
				printf("---");
				if (j < col - 1)//加入if最后一个|不打印
					printf("|");
			}
			printf("\n"); 
		}
	}
}


void PlayerMove(char board[][COL], int row, int col)
{
	int x = 0;
	int y = 0;

	printf("玩家走:>\n");

	while (1)
	{
		printf("请输入下棋的坐标:>");
		scanf("%d %d", &x, &y);
		//判断坐标合法性
		if (x >= 1 && x <= row && y >= 1 && y <= col)//玩家对空位置进行下一个*，并判断是不是被占用
		{
			//下棋
			//坐标是否被占用
			if (board[x - 1][y - 1] == ' ')//对对应的数组判断是否空格，坐标是从0开始，这里-1
			{
				board[x - 1][y - 1] = '*';//空格就输入*到数组中
				break;//输入结果合理就退出
			}
			else
			{
				printf("坐标被占用, 请重新输入\n");
			}
		}
		else
		{
			printf("坐标非法, 请重新输入\n");
		}
	}
}

void ComputerMove(char board[ROW][COL], int row, int col)
{
	printf("电脑走:>\n");

	while (1)//循环去找一个空格
	{
		int x = rand() % row;
		int y = rand() % col;

		//判断占用
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}

//对于平局的判定
int IsFull(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;//棋盘没满
			}
		}
	}

	return 1;//棋盘满了
}
//对于谁输谁赢进行判断，人获胜返回*电脑获胜返回#
char IsWin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	//判断三行
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
		{
			return  board[i][1];//
		}
	}

	//判断三列
	for (i = 0; i < col; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ')
		{
			return board[1][i];
		}
	}

	//判断对角线
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
	{
		return board[1][1];
	}

	//判断平局
	//如果棋盘满了返回1， 不满返回0
	int ret = IsFull(board, row, col);
	if (ret == 1)
	{
		return 'Q';
	}

	//继续
	return 'C';
}