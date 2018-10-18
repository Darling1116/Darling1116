#define _CRT_SECURE_NO_WARNINGS
#include "game..h"

void menu()
{
	printf("**********************\n");
	printf("********1.play********\n");
	printf("********0.exit********\n");
	printf("**********************\n");
}

void game()
{
	char arr[ROW][COL] = { 0 };
	int ret = 0;
	InitBoard(arr,ROW,COL);
	DisplayBoard(arr,ROW,COL);
	while (1)
	{

		ComputerMove(arr, ROW, COL);
		DisplayBoard(arr, ROW, COL);
	
		 ret = IsWin(arr, ROW, COL);
		if (ret != ' ')
			break;
		PlayerMove(arr, ROW, COL);
		DisplayBoard(arr, ROW, COL);
	    ret = IsWin(arr, ROW, COL);
		if (ret != ' ')
			break;
	}

	if (ret == 'X')
		printf("����Ӯ��\n");
	else if (ret == '0')
		printf("���Ӯ��\n");
	else if (ret == 'Q')
		printf("ƽ�֣�\n");

}


int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	menu( );
	printf("��ѡ��:>\n");
	do{
		//printf("��ѡ��:>\n");
		scanf("%d",&input);
		switch (input)
		{
		case 1:
			game( );
			break;
		case 0:
			break;
		default:
			printf("�����������������룡\n");
			break;
		}
	} while (input);
	return 0;
}
