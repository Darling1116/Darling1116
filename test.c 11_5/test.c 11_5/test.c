#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void menu(  )
{
	printf("*************************\n");
	printf("******1.sum  2.sub*******\n");
	printf("******3.mul  4.div*******\n");
	printf("******   0.exit   *******\n");
	printf("*************************\n");
}


int Add(int x, int y)
{
	return x + y;
}

int Sub(int x, int y)
{
	return x - y;
}

int Mul(int x, int y)
{
	return x * y;
}

int Div(int x, int y)
{
	return x / y;
}


int main()
{
	int input = 0;
	int x = 0;
	int y = 0;
	int ret = 0;
	do
	{
		menu();
		printf("��ѡ��:>\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("������������:>\n");
			scanf("%d%d", &x, &y);
			ret = Add(x, y);
			printf("%d\n", ret);
			break;
		case 2:
			printf("������������:>\n");
			scanf("%d%d", &x, &y);
			ret = Sub(x, y);
			printf("%d\n", ret);
			break;
		case 3:
			printf("������������:>\n");
			scanf("%d%d", &x, &y);
			ret = Mul(x, y);
			printf("%d\n", ret);
			break;
		case 4:
			printf("������������:>\n");
			scanf("%d%d", &x, &y);
			ret = Div(x, y);
			printf("%d\n", ret);
			break;
		case 0:
			printf("�˳�\n");
			break;
		default :
			break;
		}
	} while (input);
	return 0;
}


int Add(int x, int y)
{
	return x + y;
}
int main()
{
	int(*p)(int, int) = &Add;//����ָ��
	printf("%d ", p(2, 3));
	return 0;
}


//void Print(int(*arr)[5], int x, int y)//����ָ��
//���ڶ�ά������˵��������������������Ԫ�صĵ�ַ
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < x; i++)
//	{
//		for (j = 0; j < y; j++)
//		{
//			printf("%d ", *(*(arr + i) + j));
//		}
//		printf("\n");
//	}
//}
//int main( )
//{
//	int arr[3][5] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2, 3, 4, 5 };
//	Print(arr, 3, 5);
//	return 0;
//}



//int main( )
//{
//	char arr1[] = "abcdef";
//	char arr2[] = "abcdef";
//	//"abcdef"�������У����Ա��޸�
//	//arr1��arr2�������������ͬ�Ŀռ��У��ַ�����Ԫ��a�ĵ�ַ
//	char *p1 = "abcdef";
//	char *p2 = "abcdef";
//	//ָ�����ָ���"abcdef"��һ�������������ܱ��޸�
//	printf("%p\n", arr1);
//	printf("%p\n", arr2);//��ͬ
//	printf("%p\n", p1);
//	printf("%p\n", p2);//����ͬ
//	return 0;
//}