#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//�������
#define N 9
int main()
{
	int i = 0;
	int j = 0;
	int arr[N][N] = { 0 };
	for (i = 0; i < N; i++)
	{
		arr[i][0] = 1;
	}
	for (i = 2; i <= N; i++)
	{
		for (j = 1; j < i; j++)
		{
			if (i == j)
			{
				arr[i][j] = 1;
			}
			arr[i][j] = arr[i - 1][j] + arr[i - 1][j - 1];
			
		}
	}
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < i; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}

//
//int main()
//{
//	int killer = '0';
//	for (killer = 'A'; killer <= 'D'; killer++)
//	{
//		if ((killer != 'A') + (killer == 'C') + (killer == 'D') + (killer != 'D') == 3)
//		{
//			printf("%c ", killer);
//		}
//	}
//	return 0;
//}

//���ʵ���������м���bitλ��ͬ��
//int Difer_bits(int m, int n)
//{
//	int i = 0;
//	int count = 0;
//	for (i = 0; i < 32; i++)
//	{
//		if ((m >> i & 1) != (n >> i & 1))
//		{
//			count++;
//		}
//	}
//	return count;
//}
//int main()
//{
//	int m = 0;
//	int n = 0;
//	int ret = 0;
//	scanf("%d%d", &m, &n);
//	ret = Difer_bits(m, n);
//	printf("%d", ret);
//	return 0;
//}
//
//
//
//
//���һ��������ÿһλ��
//void Print(int n)
//{
//	if (n > 9)
//		Print(n / 10);
//	printf("%d ", n % 10);
//}
//int main( )
//{
//	int n = 0;
//	scanf("%d",&n);
//	Print(n);
//	system("pause");
//	return 0;
//
//}
//
//
//
//��ȡһ�������ж��������е���żλ��Ȼ��ֱ��ӡ������
//int main( )
//{
//	int i = 0;
//	int n = 0;
//	scanf("%d", &n);
//	printf("ż����Ϊ��\n");
//	for (i = 31; i > 0; i = i - 2)
//	{
//		printf("%d ", (n >> i & 1));
//	}
//	printf("\n");
//	printf("������Ϊ��\n");
//	for (i = 30; i >= 0; i = i - 2)
//	{
//		printf("%d ", (n >> i & 1));
//	}
//	printf("\n");
//	return 0;
//}
//
//
//
//
//�õ�һ�������ж������е�1�ĸ�����
//int count_one_bits(unsigned int value)
//{
//	int count = 0;
//	while (value)
//	{
//		value = value&(value - 1);
//		count++;
//	}
//	return count;
//}
//int main()
//{
//	int ret = 0;
//	int value = 0;
//	scanf("%d", &value);
//	ret = count_one_bits(3);
//	printf("%d",ret);
//	return 0;
//}
