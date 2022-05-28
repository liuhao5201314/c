#define _CRT_SECURE_NO_WARNINGS 1

#include "contact.h"

//初始化划分内存存储人员信息
void Initcontact(struct contact* ps)
{
	memset(ps->date, 0, sizeof(ps->date));//划分内存并赋值为0
	ps->size = 0;
}

//定义查找函数方便查找到人员
//static修饰函数为全局函数 只能在contact.c文件进行使用
static int Findbyname(struct contact*ps, char name[MAX_NAME])
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (0 == strcmp(ps->date[i].name, name))//字符串进行比较
		{
			return i;
		}
	}
	return -1;
}

//增加函数
void Addcontact(struct contact* ps)
{
	if (ps->size == MAX)
	{
		printf("通讯录满了");
	}
	else
	{
		//scanf输入取地址，数组默认首地址，int我们需要单独取地址进行输入
		printf("输入增加名字：>");
		scanf("%s", ps->date[ps->size].name);//指向对应的size下面
		printf("输入增加年龄：>");
		scanf("%d", &(ps->date[ps->size].age));//指向对应的size下面
		printf("输入增加性别：>");
		scanf("%s", ps->date[ps->size].sex);//指向对应的size下面
		printf("输入增加电话：>");
		scanf("%s", ps->date[ps->size].tele);//指向对应的size下面
		printf("输入增加住址：>");
		scanf("%s", ps->date[ps->size].addr);//指向对应的size下面

		ps->size++;
		printf("添加成功\n");
	}
}

void Showcontact(const struct contact* ps)
{
	if (ps->size==0)
	{
		printf("通讯录空");
	}
	else
	{
		int i = 0;
		printf("%20s\t%4s\t%5s\t%12s\t%20s\n", "名字", "年龄", "性别", "电话", "地址");
		for (i = 0; i < ps->size; i++)
		{
			printf("%20s\t%4d\t%5s\t%12s\t%20s\n",
				ps->date[i].name,
				ps->date[i].age,
				ps->date[i].sex,
				ps->date[i].tele,
				ps->date[i].addr);
		}
	}
}

void Delcontact(struct contact* ps)
{
	//删除后后面的元素要向前移位
	//
	char name[MAX_NAME];
	printf("输入删除人员姓名:>");
	scanf("%s", name);

	//查找到要删除人位置
	int ret = Findbyname(ps, name);//单独定义一个查找函数，找到返回下标，找不到返回-1
	//找不到人员信息输出
	if (ret == -1)
	{
		printf("人员不存在\n");
	}
	//删除人，其后的人向前移位
	else
	{
		int j = 0;
		for (j = ret; j < ps->size - 1; j++)//01234567   8个  下标为8-》7 
		{
			ps->date[j] = ps->date[j + 1];//向前移位
		}
		ps->size--;
		printf("删除成功\n");
	}
}

void Searchcontact(struct contact* ps)
{
	char name[MAX_NAME];
	printf("输入查找人员姓名:>");
	scanf("%s", name);
	//查找到要查询人位置
	int ret = Findbyname(ps, name);
	if (ret == -1)
	{
		printf("找不到成员信息");
	}
	else
	{
		printf("%20s\t%4s\t%5s\t%12s\t%20s\n", "名字", "年龄", "性别", "电话", "地址");
		printf("%20s\t%4d\t%5s\t%12s\t%20s\n",
				ps->date[ret].name,
				ps->date[ret].age,
				ps->date[ret].sex,
				ps->date[ret].tele,
				ps->date[ret].addr);
	}
}

void Modifycontact(struct contact* ps)
{
	char name[MAX_NAME];
	printf("输入查找人员姓名:>");
	scanf("%s", name);
	//查找到要查询人位置
	int ret = Findbyname(ps, name);
	if (ret == -1)
	{
		printf("要修改人信息不存在");
	}
	else
	{
		printf("输入增加名字：>");
		scanf("%s", ps->date[ret].name);//指向对应的size下面
		printf("输入增加年龄：>");
		scanf("%d", &(ps->date[ret].age));//指向对应的size下面
		printf("输入增加性别：>");
		scanf("%s", ps->date[ret].sex);//指向对应的size下面
		printf("输入增加电话：>");
		scanf("%s", ps->date[ret].tele);//指向对应的size下面
		printf("输入增加住址：>");
		scanf("%s", ps->date[ret].addr);//指向对应的size下面

		printf("修改完成");
	}
}

int compare(const void * a, const void * b)//接受要比较数字的地址，比较函数
{
	return strcmp(((struct  contact*)a)->date->name, ((struct contact*)b)->date->name);
}
void Sortcontact(struct contact* ps)
{
	int i = 0;
	int sz = sizeof(ps->date->name) / sizeof(ps->date->name[0]);
	qsort(ps->date->name, sz, sizeof(ps->date->name[0]), compare);
	for (i = 0; i < ps->size; i++)
	{
		printf("%s\n", ps->date[i].name);
	}
}