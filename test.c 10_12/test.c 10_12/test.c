#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
void menu( )
{
	printf("*********************\n");
	printf("*******1.play********\n");
	printf("*******0.exit********\n");
	printf("*********************\n");
}
void game( )
{
	int num = 0;
	int ret = rand( ) % 100 + 1;//����һ�������
	while (1)
	{
		printf("������֣�>\n");
		scanf("%d", &num);
		if (num==ret)
		{
			printf("��ϲ��\n");
			break;
		}
		else if (num > ret)
			printf("�´���\n");
		else
			printf("��С��\n");
	}
}
int main( )
{
	int input = 0;

	do
	{
		srand((unsigned)time(NULL));//�ṩÿ�λ��������Ļ�����unsignedҪ����������
		menu( );
		printf("��ѡ��>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game( );
			break;
		case 2:
			break;
		default:
			printf("ѡ�����\n");
			break;
		}
		
	}
	while (input);
	return 0;
}
