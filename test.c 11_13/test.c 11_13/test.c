#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
char *my_strcat(char *dest, const char *src)
{
	char *ret = dest;
	assert(*dest != NULL);
	assert(*src != NULL);
	while (*dest)
	{
		dest++;
	}
	while (*dest++ = *src++)
	{
		;
	}
	return ret;
}


char *my_strcpy(char *dest, const char *src)
{
	char *ret = dest;
	assert(*dest != NULL);
	assert(*src != NULL);
	while (*dest++ = *src++)
	{
		;
	}
	return ret;
}
int main()
{
	char a[] = "abhujh";
	char b[] = "guijkk";
	//my_strcpy(a, b);
	my_strcat(a, b);
	printf("%s", a);
	system("pause");
	return 0;
}

int main()
{
	int money = 0;
	scanf("%d", &money);
	int total = money;
	int empty = money;
	while (empty>1)
	{
		total = total + empty / 2;
		empty = empty / 2 + empty % 2;
	}
	printf("%d ", total);
	system("pause");
	return 0;
}

int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 5, 4, 3, 2, 1 };
	int ret = 0;
	int pos = 0;
	int x = 0;
	int y = 0;
	int i = 0;
	int len = sizeof (arr) / sizeof (arr[0]);
	for (i = 0; i < len; i++)
	{
		ret = ret^arr[i];
	}
	for (i = 0; i < 32; i++)
	{
		if (((ret >> i) & 1) == 1)
		{
			pos = i;
			break;
		}
	}
	for (i = 0; i < 32; i++)
	{
		if (((arr[i] >> pos) & 1) == 1)
		{
			x = x^arr[i];
		}
		else
		{
			y = y^arr[i];
		}
	}
	printf("%d %d\n", x, y);
	system("pause");
	return 0;

}

//�ж�һ���ַ����Ƿ�Ϊ����һ���ַ�����ת֮����ַ�����
//���磺����s1 = AABCD��s2 = BCDAA������1������s1 = abcd��s2 = ACBD������0.
//AABCD����һ���ַ��õ�ABCDA
//AABCD���������ַ��õ�BCDAA
//AABCD����һ���ַ��õ�DAABC


//void reverse(char *start, char *end)
//{
//	while (start < end)
//	{
//		char tmp = *start;
//		*start = *end;
//		*end = tmp;
//		start++;
//		end--;
//	}
//}
//
//void left_rotate(char *str, int k)
//{
//	reverse(str, str + k - 1);
//	reverse(str + k, str + strlen(str) - 1);
//	reverse(str, str + strlen(str) - 1);
//}
//
//int is_rotate(char *dest, char *rotate)
//{
//	if (strlen(dest) != strlen(rotate))
//	{
//		return 0;
//	}
//
//	strncat(dest, dest,strlen (dest));//������ƴ��
//	if (strstr(dest, rotate) != NULL)//Ȼ�������ж��Ӵ��ķ���
//	{
//		return 1;
//	}
	//ÿ������һ�Σ��ж�һ�Σ�����תstrlen(str)��
	//���з��Ͻ���ģ�����1�����򣬷���0.
	//int len = strlen(rotate);
	//while (len--)
	//{
	//	left_rotate(rotate, 1);
	//	if (!strcpy(dest, rotate))
	//	{
	//		return 1;
	//	}
	//}
//	return 0;
//}
//
//int main()
//{
//	char a[] = { 0 };
//	char b[] = { 0 };
//	scanf("%s", &a);
//	scanf("%s", &b);
//	int ret=is_rotate(a, b);
//	printf("%d", ret);
//	system("pause");
//	return 0;
//
//}


//ʵ��һ�����������������ַ����е�k���ַ���
//ABCD����һ���ַ��õ�BCDA
//ABCD���������ַ��õ�CDAB

//����һ�Σ�ABCD----->BCDA
//�������Σ�ABCD----->CDAB
//void left_rotate(char *str, int k)
//{
//	char *cur = str;
//	char temp = *str;
//	while (*(cur + 1) != '\0')
//	{
//		*cur = *(cur + 1);
//		cur++;
//	}
//	*cur = temp;
//}

//����k�Σ�ABCDEF----->EFABCD
//��һ�Σ���תǰn����
//�ڶ��Σ���תʣ�����
//�����Σ�������ת
//
//void reverse(char *start, char *end)
//{
//	while (start < end)
//	{
//		char tmp = *start;
//		*start = *end;
//		*end = tmp;
//		start++;
//		end--;
//	}
//}
//
//void left_rotate(char *str, int k)
//{
//	reverse(str, str + k - 1);
//	reverse(str + k, str + strlen(str) - 1);
//	reverse(str, str + strlen(str) - 1);
//}


//int main()
//{
//	char arr[] = { 0 };
//	int k = 0;
//	scanf("%s", &arr);
//	scanf("%d", &k);
//	left_rotate(arr, k);
//	printf("%s", arr);
//	system("pause");
//	return 0;
//}




//char * my_strcpy(char *dest, char *src)
//{
//	char *ret = dest;
//	assert(*dest != NULL);
//	assert(*src != NULL);
//	while (*src != '\0')
//	{
//		*dest = *src;
//		src++;
//		dest++;
//
//	}
//	dest = '\0';
//	return ret;
//}
//int main()
//{
//	char a[] = "abcgy";
//	char b[] = "shbui";
//	my_strcpy(a, b);
//	printf("%s", a);
//	system("pause");
//	return 0;
//}



//int strlen(const char *str)
//{
//	int count = 0;
//	assert(*str != NULL);
//	while (*str)
//	{
//		count++;
//		str++;
//	}
//	return count;
//}
//
//void reverse_r(char *start, char *end)
//{
//	while (start < end)
//	{
//		char tmp = *start;
//		*start = *end;
//		*end = tmp;
//		start++;
//		end--;
//	}
//}
//void reverse(char *str)
//{
//	//char arr[] = "student a am i";
//	char *cur = str;
//	char *left = str;
//	char *right = str + strlen(str) - 1;
//	reverse_r(left, right);
//
//	while (*cur)
//	{
//		char *start = cur;
//		while ((*cur != ' ') && (*cur != '\0'))
//		{
//			cur++;
//		}
//		reverse_r(start, cur - 1);
//		if (*cur == ' ')
//		{
//			cur++;
//		}
//
//	}
//
//}
//int main()
//{
//	//char arr[] = "student a am i";
//	char arr[] = { 0 };
//	gets(arr);
//	reverse(arr);
//	printf("%s\n", arr);
//	system("pause");
//	return 0;
//}




//int rearch(int arr[3][3], int row, int col, int k, int x, int y, int *px, int *py)
//{
//	if (x < 0 || (y >= col))
//	{
//		*px = -1;
//		*py = -1;
//		return 0;
//	}
//	if (arr[x][y] == k)
//	{
//		*px = x;
//		*py = y;
//		return 1;
//	}
//	else if (arr[x][y] > k)
//	{
//		rearch(arr, 3, 3, k, x - 1, y, px, py);
//	}
//	else if (arr[x][y] < k)
//	{
//		rearch(arr, 3, 3, k, x, y + 1, px, py);
//	}
//}
//
//int main()
//{
//	int px = 0;
//	int py = 0;
//	int arr[3][3] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
//	rearch(arr, 3, 3, 6, 2, 0, &px, &py);
//	printf("%d %d\n", px, py);
//	system("pause");
//	return 0;
//}









