#define _CRT_SECURE_NO_WARNINGS 1

#include "contact.h"

//��ʼ�������ڴ�洢��Ա��Ϣ
void Initcontact(struct contact* ps)
{
	memset(ps->date, 0, sizeof(ps->date));//�����ڴ沢��ֵΪ0
	ps->size = 0;
}

//������Һ���������ҵ���Ա
//static���κ���Ϊȫ�ֺ��� ֻ����contact.c�ļ�����ʹ��
static int Findbyname(struct contact*ps, char name[MAX_NAME])
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (0 == strcmp(ps->date[i].name, name))//�ַ������бȽ�
		{
			return i;
		}
	}
	return -1;
}

//���Ӻ���
void Addcontact(struct contact* ps)
{
	if (ps->size == MAX)
	{
		printf("ͨѶ¼����");
	}
	else
	{
		//scanf����ȡ��ַ������Ĭ���׵�ַ��int������Ҫ����ȡ��ַ��������
		printf("�����������֣�>");
		scanf("%s", ps->date[ps->size].name);//ָ���Ӧ��size����
		printf("�����������䣺>");
		scanf("%d", &(ps->date[ps->size].age));//ָ���Ӧ��size����
		printf("���������Ա�>");
		scanf("%s", ps->date[ps->size].sex);//ָ���Ӧ��size����
		printf("�������ӵ绰��>");
		scanf("%s", ps->date[ps->size].tele);//ָ���Ӧ��size����
		printf("��������סַ��>");
		scanf("%s", ps->date[ps->size].addr);//ָ���Ӧ��size����

		ps->size++;
		printf("��ӳɹ�\n");
	}
}

void Showcontact(const struct contact* ps)
{
	if (ps->size==0)
	{
		printf("ͨѶ¼��");
	}
	else
	{
		int i = 0;
		printf("%20s\t%4s\t%5s\t%12s\t%20s\n", "����", "����", "�Ա�", "�绰", "��ַ");
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
	//ɾ��������Ԫ��Ҫ��ǰ��λ
	//
	char name[MAX_NAME];
	printf("����ɾ����Ա����:>");
	scanf("%s", name);

	//���ҵ�Ҫɾ����λ��
	int ret = Findbyname(ps, name);//��������һ�����Һ������ҵ������±꣬�Ҳ�������-1
	//�Ҳ�����Ա��Ϣ���
	if (ret == -1)
	{
		printf("��Ա������\n");
	}
	//ɾ���ˣ���������ǰ��λ
	else
	{
		int j = 0;
		for (j = ret; j < ps->size - 1; j++)//01234567   8��  �±�Ϊ8-��7 
		{
			ps->date[j] = ps->date[j + 1];//��ǰ��λ
		}
		ps->size--;
		printf("ɾ���ɹ�\n");
	}
}

void Searchcontact(struct contact* ps)
{
	char name[MAX_NAME];
	printf("���������Ա����:>");
	scanf("%s", name);
	//���ҵ�Ҫ��ѯ��λ��
	int ret = Findbyname(ps, name);
	if (ret == -1)
	{
		printf("�Ҳ�����Ա��Ϣ");
	}
	else
	{
		printf("%20s\t%4s\t%5s\t%12s\t%20s\n", "����", "����", "�Ա�", "�绰", "��ַ");
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
	printf("���������Ա����:>");
	scanf("%s", name);
	//���ҵ�Ҫ��ѯ��λ��
	int ret = Findbyname(ps, name);
	if (ret == -1)
	{
		printf("Ҫ�޸�����Ϣ������");
	}
	else
	{
		printf("�����������֣�>");
		scanf("%s", ps->date[ret].name);//ָ���Ӧ��size����
		printf("�����������䣺>");
		scanf("%d", &(ps->date[ret].age));//ָ���Ӧ��size����
		printf("���������Ա�>");
		scanf("%s", ps->date[ret].sex);//ָ���Ӧ��size����
		printf("�������ӵ绰��>");
		scanf("%s", ps->date[ret].tele);//ָ���Ӧ��size����
		printf("��������סַ��>");
		scanf("%s", ps->date[ret].addr);//ָ���Ӧ��size����

		printf("�޸����");
	}
}

int compare(const void * a, const void * b)//����Ҫ�Ƚ����ֵĵ�ַ���ȽϺ���
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