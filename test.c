#define _CRT_SECURE_NO_WARNINGS 1
//ͨѶ¼��ʵ��
//1.���1000������
//2.���Ӻ�����Ϣ
//3.ɾ��������Ϣ
//4.���Һ�����Ϣ
//5.�޸ĺ�����Ϣ
//6.��ӡ������Ϣ
//7.����
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
	//int size = 0;//����
	//struct people con[MAX];//���ͨѶ��Ա��
	//���Խ��кϲ�Ϊ����Ľṹ��
	//����ͨѶ¼
	struct contact con;//con��ΪͨѶ¼����1000��Ԫ�غ�size
	//��ʼ��ͨѶ¼
	Initcontact(&con);
	do
	{
		menu();
		printf("��ѡ��");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			Addcontact(&con);//���ݵ�ַ������ֵ��Ϊ�˽�Լ�ռ�
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
			printf("�˳�");
			break;
		default:
			printf("ѡ�����");
			break;
		}
	} while (input);
}