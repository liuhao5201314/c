//扫雷游戏
#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"


void game()
{
	//printf("扫雷\n");
	//雷的数字存储
	//布置雷：格子用数字，为雷就随机存放数字1，不是雷就存放0
	//排查雷。为1雷游戏结束，不为雷显示周围雷的个数(周围8个格子寻找1并且打印找到的1的个数)
	//安排二个数组一个存放初始雷的信息，一个存放排查出雷的信息，之所以分开是由于雷为1，自己打印雷的数日也可能为1，进行区分
	//玩家看见的为排查出雷的信息表格为排查显示*排查打印数字
	//注意点：边界点的显示将数组扩大一圈9*9----11*11，全部存放字符0

	//雷的信息存储图
	char mine[ROWS][COLS] = { 0 };
	//排查雷的信息图
	char show[ROWS][COLS] = { 0 };
	//初始化棋盘画出一片区域
	InitBoard(mine, ROWS, COLS,'0');//初始化全部变为0实参写数组名，形参写数组[]
	InitBoard(show, ROWS, COLS,'*');//初始化全部变为*
	//打印棋盘
	//DisplayBoard(mine,ROW,COL);
	//printf("\n");
	DisplayBoard(show, ROW, COL);//传递过去必须为11*11但是我们进行操作时只操作9*9
	//布置雷
	SetMind(mine, ROW, COL);
	//DisplayBoard(mine, ROW, COL);//测试雷是否写入
	///D扫雷
	FindMine(mine,show, ROW, COL);
}
void menu()
{
	printf("*************************\n");
	printf("********1.玩游戏*********\n");
	printf("*******0.退出游戏********\n");
	printf("****数字为周围雷的数*****\n");
	printf("*************************\n");
}
void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));//生成时间戳
	printf("");
	do
	{
		menu();
		printf("请选择：\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:game();
			break;
		case 0:printf("游戏结束\n");
			break;
		default:
			printf("输入数字无效，请重新输入\n");
			break;
		}
	} while (input);
}

int main()
{
	test();
	return 0;
}