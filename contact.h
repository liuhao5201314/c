#define _CRT_SECURE_NO_WARNINGS 1

#define MAX 1000
#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TELE 12
#define MAX_ADDR 30

#include<stdio.h>
#include<string.h>
#include <stdlib.h>  
//���
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

//��Ա��Ϣ����
struct people
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
};
//ͨѶ¼����
struct contact
{
	struct people date[MAX];
	int size;
};

//������ʼ������
void Initcontact(struct contact* ps);
//�������Ӻ���
void Addcontact(struct contact* ps);
//������ʾ����
void Showcontact(const struct contact* ps);
//ɾ����������
void Delcontact(struct contact* ps);
//������Ա��������
void Searchcontact(struct contact* ps);
//�޸ĺ�������
void Modifycontact(struct contact* ps);
//����������
void Sortcontact(struct contact* ps);