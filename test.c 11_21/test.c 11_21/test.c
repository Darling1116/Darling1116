#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
void menu()
{
	printf("***********************\n");
	printf("******   0.exit  ******\n");
	printf("******1.Add 2.Sub******\n");
	printf("******3.Mul 4.Div******\n"); 
	printf("***********************\n");
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
//	int ret = 0;
	int(*pfun[5])(int, int) = { 0, Add, Sub, Mul, Div };//����ָ�����飬һ��Ҫ��������Ĵ�С
	do
	{
		menu();
		printf("��ѡ��:>\n");
		scanf("%d", &input);
		if (input >= 1 && input <= 4)
		{
			printf("������������:>\n");
			scanf("%d%d", &x, &y);
			//ret = pfun[input](x, y);//ʹ�ú���ָ������ʱ���±�һ��Ҫ��������
			printf("%d ", pfun[input](x, y));
		}
		else
		{
			printf("ѡ������˳�\n");
		}

	} while (input);
	return 0;
}

//int Add(int x, int y)
//{
//	return x + y;
//}
//
//int main()
//{
//	int(*p)(int, int) = &Add;//����ָ�룬�����д��Σ������ǵ�ַ
//	printf("%d ", p(1, 2));
//	system("pause");
//	return 0;
//}

//void Print(int(*arr)[5], int x, int y)
////*arrΪ����ָ�룬ÿһ�д��5��Ԫ�أ�����Ϊint�Ρ�
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
//
//int main()
//{
//	int arr[3][5] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 12, 13, 15, 16, 17, 18 };
//	Print(&arr, 3, 5);//�����б������Σ������ǵ�ַ
//	system("pause");
//	return 0;
//}