#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//��һ���ַ����������Ϊ:"student a am i",
//	���㽫��������ݸ�Ϊ"i am a student".
//	Ҫ��
//	����ʹ�ÿ⺯����
//	ֻ�ܿ������޸��ռ䣨�ռ�������ַ����ĳ����޹أ���

int strlen(char*str)//�����ַ����ĳ���
{
	int count = 0;
	while (*str)
	{
		count++;
		str++;//�ַ����ĳ��ȼ�һ������ָ����һ���ַ�
	}
	return count;
}

void Reverse_str(char* start, char* end)
{
	while (start < end)
	{
		int tmp = *start;
		*start = *end;
		*end = tmp;
		start++;
		end--;
	}
}




////һ����������һ����ֻ������һ�Σ������Ķ��ǳɶԵĳ��֡�
////�ҳ�������֣�ʹ��λ���㣩
//int main()
//{
//	int i = 0;
//	int ret = 0;
//	int arr[] = { 1, 2, 3, 5, 3, 2, 1 };
//	int sz = sizeof(arr) / sizeof (arr[0]);
//	for (i = 0; i < sz; i++)
//	{
//		ret = ret^arr[i];
//		//��ӦΪ1�ĸ���Ϊ����ʱ����ӦΪ���Ϊ1��Ϊż��ʱ����ӦΪ�϶�Ϊ0��
//	}
//	printf("%d ", ret);
//	system("pause");
//	return 0;
//}



//��ʹ��(a+b)/2,��ƽ��ֵ
//
//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d%d", &a, &b);
//	//printf("%d\n", ((a + b) >> 1));
//	//printf("%d\n", (a + ((b - a) >> 1)));
//	printf("%d\n", (a & b + ((a^b) >> 1)));
//	//a&b����������ͬ�Ĳ��֣�a^b����������ͬ�Ĳ��֣�����2�Ǳ�֤��ͬ�Ĳ���������ƽ��
//	system("pause");
//	return 0;
//}

//ʵ�ֶ����������еķ�ת��

//unsigned int Reserve_bits(unsigned int value)
//{
//	int i = 0;
//	unsigned int sum = 0;
//	for (i = 0; i < 32; i++)
//	{
//		sum = sum + ((value >> i) & 1)*pow(2 ,32 - i);
//	}
//	return sum;
//}

//unsigned int Reserve_bits(unsigned int value)
//{
//	int i = 0;
//	unsigned int ret = 0;
//	for (i = 0; i < 32; i++)
//	{
//		ret = ret << 1;
//		ret = ret | ((value >> i) & 1);  //��һ������ÿһλ�ֱ�浽ret�����λ
//	}
//	return ret;
//}
//
//int main(  )
//{
//	unsigned int ret = 0;
//	unsigned int value = 0;
//	scanf("%d", &value);
//	ret = Reserve_bits(value);
//	printf("%u\n", ret);
//	system("pause");
//	return 0;
//}



//int main()
//{
//	char arr1[] = "abcdefg";
//	char arr2[] = "abcdefg";
//	char *p1  = "abcdefg";
//	char *p2  = "abcdefg";
//	printf("%p\n", arr1);
//	printf("%p\n", arr2);//��ͬ
//	//arr1,arr2�����飬�ɱ��޸�
//	//"abcdefg"���������Ǵ���ڲ�ͬ�Ŀռ���
//	printf("%p\n", p1);
//	printf("%p\n", p2);//��ͬ
//	//p1,p2��Ķ���a�ĵ�ַ�����ܱ���
//	//"abcdefg"���������ڳ�����
//	//���ܱ��޸�
//	system("pause");
//	return 0;
//
//}
//
//��ӡһ����ά���飺
//
//void Print(int(*arr)[5],int x, int y)//����ָ��
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
//int main()
//{
//	int arr[3][5] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 2, 3, 6, 7, 9, 0, };
//	Print(arr, 3, 5);
//	system("pause");
//	return 0;
//}
//
//
//
//��ͬ�ķ���ʵ�ּ�����
//void menu( )
//{
//	printf("*************************\n");
//	printf("*******1.Add 2.Sub*******\n");
//	printf("*******3.Mul 4.Div*******\n");
//	printf("*******   0.exit  *******\n");
//	printf("*************************\n");
//}
//
//
//int Add(int x, int y)
//{
//	return x + y;
//}
//int Sub(int x, int y)
//{
//	return x - y;
//}
//int Mul(int x, int y)
//{
//	return x * y;
//}
//int Div(int x, int y)
//{
//	return x / y;
//}
//
//void Calc(int(*pfun)(int, int))
////���ú���ָ����ʵ��case�����Ż�
//{
//	int x = 0;
//	int y = 0;
//	int ret = 0;
//	printf("������������:>\n");
//	scanf("%d%d", &x, &y);
//	ret = pfun(x, y);
//	printf("%d\n", ret);
//
//}
//
//int main( )
//{
//	int input = 0;
//	int x = 0;
//	int y = 0;
//	int ret = 0;
//	do
//	{
//		menu();
//		printf("��ѡ��:>\n");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			Calc(Add);
//			break;
//		case 2:
//			Calc(Sub);
//			break;
//		case 3:
//			Calc(Mul);
//			break;
//		case 4:
//			Calc(Div);
//			break;
//		case 0:
//			printf("�˳�\n");
//			break;
//		default :
//			break;
//		}
//	} while (input);
//	system("pause");
//	return 0;
//}

//int main()
//{
//	int input = 0;
//	int x = 0;
//	int y = 0;
//	int ret = 0;
//	int(*pfun[5])(int, int) = {exit, Add, Sub, Mul, Div};//����һ������ָ������
//	do
//	{
//		menu();
//		printf("��ѡ��:>\n");
//		scanf("%d", &input);
//		if (input >= 1 & input <= 4)
//		{
//			printf("������������:>\n");
//			scanf("%d%d", &x, &y);
//			ret = pfun[input](x, y);
//			printf("%d\n", ret);
//		}
//		else
//		{
//			printf("�˳�\n");
//			break;
//		}
//
//	} while (input);
//	system("pause");
//	return 0;
//
//}



//int main( )
//{
//	int input = 0;
//	int x = 0;
//	int y = 0;
//	int ret = 0;
//	do
//	{
//		menu();
//		printf("��ѡ��:>\n");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			printf("������������:>\n");
//			scanf("%d%d", &x, &y);
//			ret = Add(x, y);
//			printf("%d\n", ret);
//			break;
//		case 2:
//			printf("������������:>\n");
//			scanf("%d%d", &x, &y);
//			ret = Sub(x, y);
//			printf("%d\n", ret);
//			break;
//		case 3:
//			printf("������������:>\n");
//			scanf("%d%d", &x, &y);
//			ret = Mul(x, y);
//			printf("%d\n", ret);
//			break;
//		case 4:
//			printf("������������:>\n");
//			scanf("%d%d", &x, &y);
//			ret = Div(x, y);
//			printf("%d\n", ret);
//			break;
//		case 0:
//			printf("�˳�\n");
//			break;
//		default :
//			break;
//		}
//	} while (input);
//	system("pause");
//	return 0;
//}