#define _CRT_SECURE_NO_WARNINGS 1

#define MAX 1000
#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TELE 12
#define MAX_ADDR 30

#include<stdio.h>
#include<string.h>
#include <stdlib.h>  
//输出
enum option
{
	EXIT,//0
	ADD,//1
	DEL,
	SEARCH,
	MODIFY,
	SHOW,
	SORT
};

//人员信息类型
struct people
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
};
//通讯录类型
struct contact
{
	struct people date[MAX];
	int size;
};

//声明初始化函数
void Initcontact(struct contact* ps);
//声明增加函数
void Addcontact(struct contact* ps);
//声明显示函数
void Showcontact(const struct contact* ps);
//删除函数声明
void Delcontact(struct contact* ps);
//查找人员函数声明
void Searchcontact(struct contact* ps);
//修改函数声明
void Modifycontact(struct contact* ps);
//排序函数声明
void Sortcontact(struct contact* ps);