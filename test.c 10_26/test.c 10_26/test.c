#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//����int λ����m��n�Ķ����Ʊ���У��ж��ٸ�bitλ��ͬ��
int Difer_bits(int m,int n)
{
	int count = 0;
	int i = 0;
	for (i = 0; i < 32; i++)
	{
		if ((m >> i & 1) != (n >> i & 1))
		{
			count++;
		}
	}
	return count;
}
int main()
{
	int ret=Difer_bits(13, 24);
	printf("%d", ret);
	return 0;
}




//�ֱ��ӡһ�����Ķ������е�ż��λ������λ��
//void even_bits(int value)
//{
//	int i = 0;
//	for (i = 31; i > 0; i = i - 2)
//	{
//		printf("%d ", value >> i & 1);
//	}
//}
//void odd_bits(int value)
//{
//	int i = 0;
//	for (i = 30; i >= 0; i = i - 2)
//	{
//		printf("%d ", value >> i & 1);
//	}
//}
//int main()
//{
//	int n = 13;
//	even_bits(n);
//	printf("\n");
//	odd_bits(n);
//	return 0;
//
//}


//���һ��������������һ�ĸ�����
//int count_one_bits(int value)
//{
//	int count = 0;
//	int i = 0;
//	for (i = 1; i != 0; i = i << 1)
//	{
//		if (value & 1 == 1)
//			count++;
//		value = value >> 1;
//	}
//	return count;
//
//}
//int main()
//{
//	int value = 0;
//	scanf("%d", &value);
//	int ret = count_one_bits(value);
//	printf("%d", ret);
//}

