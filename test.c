#define _CRT_SECURE_NO_WARNINGS 1
//通讯录的实现
//1.存放1000个好友
//2.增加好友信息
//3.删除好友信息
//4.查找好友信息
//5.修改好友信息
//6.打印好友信息
//7.排序
#include "contact.h"
void menu()
{
	printf("****************************************\n");
	printf("*****1.add              2.del      *****\n");
	printf("*****3.search           4.modify   *****\n");
	printf("*****5.show             6.sort     *****\n");
	printf("*****0.exit                        *****\n");
	printf("****************************************\n");
}
int main()
{
	int input = 0;
	//int size = 0;//个数
	//struct people con[MAX];//存放通讯人员数
	//可以进行合并为下面的结构体
	//创建通讯录
	struct contact con;//con就为通讯录包含1000个元素和size
	//初始化通讯录
	Initcontact(&con);
	do
	{
		menu();
		printf("请选择");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			Addcontact(&con);//传递地址而不是值是为了节约空间
			break;
		case DEL:
			Delcontact(&con);
			break;
		case SEARCH:
			Searchcontact(&con);
			break;
		case MODIFY:
			Modifycontact(&con);
			break;
		case SHOW:
			Showcontact(&con);//
			break;
		case SORT:
			Sortcontact(&con);
			break;
		case EXIT:
			printf("退出");
			break;
		default:
			printf("选择错误");
			break;
		}
	} while (input);
}