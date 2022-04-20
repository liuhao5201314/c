#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void InitBoard(char board[ROWS][COLS], int rows, int cols,char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}

void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	//打印列号，每一列打印一个数字
	for (i = 0; i <= col; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)//0不打印ROWS不打印
	{
		printf("%d ", i);//在每一行开头打印一个数字
		for(j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}

//布置雷的过程
void SetMind(char board[ROWS][COLS], int row, int col)
{
	int count = EASY_COUNT;
	while (count)//布置一个雷减一个
	{
		int x = rand() % row+1;//取模后为0--ROW-1=1-9
		int y = rand() % col+1;
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;//生成一个雷就减一个
		}
	}
}


//1.对于给定坐标的位置周围进行判断有多少个'1'然后++
//2.将给定坐标周围数字进行相加得到的数字就是我们雷的个数
//'3'-'0'=3   字符数字减去'0'得到对应数字
int get_mine_count(char mine[ROWS][COLS],int x,int y)
{
	//1.
	//int count = 0;
	//if (mine[x][y] == '1')
	//{
	//	count++;
	//}
	
	return mine[x - 1][y] + mine[x - 1][y - 1] + mine[x - 1][y + 1] + mine[x][y - 1] + mine[x][y + 1] + mine[x + 1][y - 1] + mine[x + 1][y] + mine[x + 1][y + 1] - 8 * '0';
}

//扫雷的过程
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int win = 0;
	while (win<row*col- EASY_COUNT)
	{
		printf("请输入坐标进行排查雷（x,y）先行后列\n");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (mine[x][y] == '1')
			{
				printf("游戏结束\n");
				DisplayBoard(mine, row, col);
				break;//打印一下mine也就是雷分布图
			}
			else//没有踩雷计算x,y坐标周围有多少雷
			{
				int count=get_mine_count(mine, x, y);//另外写一个函数进行判断雷个数
				show[x][y] = count + '0';//放入一个字符
				DisplayBoard(show, ROW, COL);//打印排雷过后的棋盘
				win++;
			}
		}
		else
		{
			printf("输入坐标非法重新输入\n");
		}
	}
	if (win == row * col - EASY_COUNT)
	{
		printf("恭喜你，排雷成功\n");
		DisplayBoard(mine, row, col);
	}
}


