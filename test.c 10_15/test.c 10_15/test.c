#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void menu( )
{
	printf("*************************\n");
	printf("*********1. play*********\n");
	printf("*********0. exit*********\n");
	printf("*************************\n");
}

void game( )
{
	int ret = rand() % 100 + 1;
	int num = 0;
	while (1)
	{
		printf("�������:>\n");
		scanf("%d", &num);
		if (num == ret)
		{
			printf("��ϲ�㣬�¶���\n");
			break;
		}
		else if (num < ret)
		{
			printf("��С�ˣ�\n");
		}
		else {
			printf("�´��ˣ�\n");
		}
	}
}

int main( )
{
	int input = 0;
	srand((unsigned int)time(NULL));
	menu();
	do
	{
		printf("��ѡ��:>\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			break;
		default:
			printf("����������������룡\n");
			break;
		}
	} while (input);
	return 0;


}