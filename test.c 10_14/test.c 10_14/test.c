#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main( )
{
	char input[20] = { 0 };
	system("shutdown -s -t 60");
	//again:
	while (1)
	{
		printf("������һ�����ڽ���ػ���������룺��������ȡ���ػ�\n");
		scanf("%s", input);
		if (strcmp(input, "������") == 0)//�Ƚ������ַ����Ƿ���ͬ��strcmp
		{
			system("shutdown -a");//ȡ���ػ�
			break;
		}
	}
	//else
	//{ 
		//goto again;
	//}
	return 0;
}