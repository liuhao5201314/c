//goto 语句就是跳转
/*
#include<stdio.h>
int main()
{
	printf("hello bit");
	goto again;
	printf("呵呵");
again:
	printf("你好");
}
*/
//关机程序
//shutdown -s -t 60    就是电脑60秒关机在cmd输入
//system()----执行系统命令
//安装到服务就成为了病毒：将debug编入到电脑服务程序里面将其运行改为自动运行，就会出现开机一分钟就关机
/*
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	char arr1[20];
again:
	system("shutdowm -s -t 60");
	printf("请注意你的电脑在一分钟内将关机，如果输入：我是刘浩，就取消关机\n请输入：");
	scanf("%s", &arr1);
	if (strcmp(arr1, "我是刘浩")==0)//strcmp比较字符串函数，为0则字符串相同
	{
		system("shutdown -a");
	}
	else
	{
		goto again;
	}
}
*/

//函数
//1.库函数
//2.自定义函数
//1.io函数2.字符串操作函数3.内存操作函数4.时间日期函数5.数学函数6.其他库函数
//strcpy-----字符串拷贝<string.h>
/*
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
int main()
{
	char arr1[30];
	char arr2[] = "########";
	strcpy(arr1, arr2);//将arr2的数字复制到arr1中,\0也会拷贝过去（结束标志）
	printf("%s", arr1);
}
*/

//memset内存设置
/*
#include<stdio.h>
#include <string.h>
int main()
{
	char arr1[] = "liuhao love";
	memset(arr1, 'i', 6);
	puts(arr1);
}
*/

//自定义函数包含函数名、函数类型、函数参数、语句项
/*
#include<stdio.h>

int max(int x,int y)//设置int 返回数字
{
	return(x, y) ? x : y;
}
int main()
{
	int a, b;
	printf("请输入二个数字\n");
	scanf_s("%d%d", &a, &b);
	int getmax=max(a, b);
	printf("%d", getmax);
}
*/
//a,b为实际参数(可以为一个函数，实数，变量，表达式)但必须有一个确切的值传递给形式参数
//x,y为形式参数只能在函数里面使用
//当实参传给形参的时候形参为实参的临时拷贝，对形参的修改不会改变实参，当我们把地址传过去就能改变实参了


//这样书写函数里面的x,y和我们书写的a,b没有联系虽然函数里面x,y进行了交换但是a,b没有执行这项命令
//不能完成要求交换二个数字
//调试的时候要进入函数按F11
/*
#include<stdio.h>
void swap(int x, int y)
{
	int tem=0;
	tem = x;
	x = y;
	y = tem;
}
int main()
{
	int a = 10;
	int b = 20;
	printf("a=%d b=%d\n", a, b);
	swap(a, b);
	printf("a=%d b=%d", a, b);
}
*/


//采用指针指向地址，让x,y接受a,b的地址
//int*定义指针类型，*x解指针其实就是a
/*
#include<stdio.h>
void swap(int* x, int* y)
{
	int tem = 0;
	tem= *x;
	*x = *y;
	*y = tem;
}

int main()
{
	int a = 10;
	int b = 20;
	printf("a=%d b=%d\n", a, b);
	swap(&a, &b);//调用自己定义的函数
	printf("a=%d b=%d", a, b);
}
*/
//函数调用分为1.传值调用2.传址调用
//就比如上面的二个函数一个传递数过去，一个传递地址过去
//1.传值调用函数的实参和形参分别占有不同的内存块，对形参的修改不会影响实参
//2.传址调用可以让函数和函数外部的变量建立联系，也就是说函数内部可以直接操作函数外部变量。
//对于函数的练习
//运用函数的方法判断素数
/*
#include<stdio.h>

int sushu(int x)
{
	int y = 1;
	if (x == 1 || x < 1)
	{
		return 0;
	}
	for (y = 2; y < x; y++)
	{
		if (x%y == 0)
		{
			return 0;
		}
	}
	return 1;
}

int main()
{
	int i = 0;
	int j = 0;
	printf("请输入一个数字进行素数判断\n");
	scanf_s("%d", &i);
	j = sushu(i);
	if (j == 0)
	{
		printf("这个不是素数");
	}
	if (j == 1)
	{
		printf("这个是素数");
	}
}
*/
//打印100-200素数
/*
#include<stdio.h>
#include<math.h>
int is_prime(int x)
{
	int y = 1;
	if (x == 1 || x < 1)
	{
		return 0;
	}
	for (y = 2; y < sqrt(x); y++)//sqrt 进行优化
	{
		if (x%y == 0)
		{
			return 0;
		}
	}
	return 1;
}


int main()
{
	int i = 0;
	for (i = 100; i < 200;i++)
	{
		if (is_prime(i) == 1)
		{
			printf("%d ", i);
		}
	}
}
*/



//运用函数的方法将输入的年份进行判断
/*
#include<stdio.h>

int run(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
	{
		return 1;
	}
	return 0;
}

int main()
{
	int i,j;
	printf("请输入一个年份进行判断闰年\n");
	scanf_s("%d", &i);
	j = run(i);
	if (j == 1)
	{
		printf("这是一个闰年");
	}
	if (j == 0)
	{
		printf("这不是一个闰年");
	}
}
*/


//采用二分法找到顺序数组对应数组的角标
/*
#include<stdio.h>
int fenn(int x)
{
	int left = 0;
	char arr1[] = { 1,2,3,4,5,6,7,8,9,10 };
	int sz = sizeof(arr1) / sizeof(arr1[0]);
	int right = sz - 1;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (arr1[mid] > y)
		{
			right = mid - 1;
		}
		else if (arr1[mid] < y)
		{
			left = mid + 1;
		}
		else
		{
			return mid;
		}
	}
	if (left > right)
	{
		return 0;
	}
}
int main()
{
	int k = 0;
	int m = 0;
	printf("请输入您想查找的数字(1-10)\n");
	scanf_s("%d", &k);
	m=fenn()
}
*/
//mid值一直为0没有改变，sz也不对
/*
#include<stdio.h>

int binary_search(int arr[],int k,int sz)//这里的arr[]为首元素的地址，本质上为指针
{
	//算法的实现二分法
	int left = 0;
	//int sz = sizeof(arr) / sizeof(arr[0]);//指针大小为4/8
	int right = sz - 1;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (arr[mid] > k)
		{
			right = mid - 1;
		}
		else if (arr[mid] < k)
		{
			left = mid + 1;
		}
		else
		{
			return mid;
		}
	}
	if (left > right)
	{
		return 0;
	}
}

int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int k = 7;
	int sz = sizeof(arr) / sizeof(arr[0]);//数组大小必须在外面计算不然会出错
	//在函数中找到返回下标找不到返回0
	int ret = binary_search(arr, k, sz);//数组在进行传参的时候仅仅传递了数组第一个元素地址
	if (ret == 0)
	{
		printf("找不到指定数字");
	}
	else
	{
		printf("找到了%d", ret);
	}
}
*/




//书写一个函数每次调用num加一
/*
#include<stdio.h>

int add(int* x)
{
	int i = 0;
	i = *x;
	i++;
	return i;
}
int main()
{
	int num = 1;
	int k = 0;
	int j = 0;
	j = add(&num);
	k = add(&j);
	printf("%d", k);
}
*/
//书写一个函数每次加一
/*
#include<stdio.h>

void add(int* num)
{
	*num = *num + 1;
}
int main()
{
	int num = 0;
	add(&num);
	printf("%d\n", num);
	add(&num);
	printf("%d\n", num);
	add(&num);
	printf("%d\n", num);
}
*/


//函数嵌套
//函数里面是可以使用另一个函数
/*
#include<stdio.h>

void new_line()
{
	printf("hehe\n");
}
void three_line()
{
	int i = 0;
	for (i = 0; i < 3; i++)
	{
		new_line();
	}
}
int main()
{
	three_line();
}
*/

//链式访问
//把一个函数的返回值作为另一个函数参数
//例如：printf("%d\n",strlen("abc"));

#include<stdio.h>
int main()
{
	printf("%d", printf("%d", printf("%d", 43)));//printf()打印的为数字的格式第一次打印43-->2--->1所以结果就为4321
	printf("%d", 1);//就是打印字符个数，在上面的printf("%d",43)=2
}


//函数的声明和定义
//如果函数写到了主函数后面就需要进行声明
//一般进行函数书写时用于格式要求，一个主文件，其他就是函数调用的函数，分开书写
/*
#include<stdio.h>
#include "add.h"
int main()
{
	int a = 10;
	int b = 20;
	int sum = 0;
	sum = add(a, b);
	printf("%d",sum);
}

*/