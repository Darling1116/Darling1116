#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef int SLDataType;

typedef struct SeqList{
	SLDataType* data;
	int maxSize;
	int length;
}SeqList;

void InitList(SeqList* sl,int maxsize){
	sl->data = (SLDataType*)malloc(sizeof(SLDataType)*maxsize);
	assert(sl->data);
	sl->maxSize = maxsize;
	sl->length = 0;
}

void PrintList(SeqList* sl){
	for (int i = 0; i < sl->length; i++){
		printf("%d ", sl->data[i]);
	}
	printf("\n");
}


bool InsertList(SeqList* sl, int pos,SLDataType x){
	assert(sl);
	if (pos<1 || pos>sl->length + 1){
		return false;
	}
	if (sl->length >= sl->maxSize){
		return false;
	}
	//�����һ��Ԫ�ؿ�ʼ���Ų��
	for (int i = sl->length; i >= pos; i--){
		sl->data[i] = sl->data[i-1];
	}
	sl->data[pos - 1] = x;
	sl->length++;
	return true;
}


//ɾ����СֵԪ�أ�����Ψһ�����ճ���λ�������һ��Ԫ�ز���
SLDataType DeleteMinNum(SeqList* sl){
	if (sl->length == 0){
		return false;
	}
	int min = sl->data[0];
	int pos = 0;
	for (int i = 1; i < sl->length; i++){
		if (sl->data[i] < min){
			int tmp = sl->data[i];
			sl->data[i] = min;
			min = tmp;
			pos = i;
		}
	}
	sl->data[pos] = sl->data[sl->length - 1];
	sl->length--;
	return min;
}


//ʱ�临�Ӷ�O(n),�ռ临�Ӷ�O(1)
void DeleteAllNum1(SeqList* sl, SLDataType x){
	int k = 0;
	//��k��¼ֵΪx��Ԫ�أ�������¼ɾ��Ԫ�أ�
	for (int i = 0; i < sl->length; i++){
		if (sl->data[i] == x){
			k++;
		}
		else{
			sl->data[i - k] = sl->data[i];
		}
	}
	sl->length = sl->length - k;
}

void DeleteAllNum2(SeqList* sl, SLDataType x){
	int k = 0;
	//��k��¼ֵ��Ϊx��Ԫ��
	for (int i = 0; i < sl->length; i++){
		if (sl->data[i] != x){
			sl->data[k++] = sl->data[i];
		}
	}
	sl->length = k;
}

//ɾ��x~y֮���Ԫ�أ�Ҫ��x<y��
bool DeleteBetween(SeqList* sl, SLDataType x, SLDataType y){
	if (sl->length == 0){
		return false;
	}
	if (x >= y){
		return false;
	}
	int k = 0;
	for (int i = 0; i < sl->length; i++){
		if (sl->data[i] >= x&&sl->data[i] <= y){
			k++;
		}
		else{
			sl->data[i - k] = sl->data[i];
		}
	}
	sl->length = sl->length - k;
	return true;
}



//ɾ������˳����е������ظ���Ԫ�أ�ʹ���е�Ԫ�ز���ͬ
void SeqDeleteRepeat(SeqList* sl){
	assert(sl);
	//��һ��Ԫ�����ó������ӵڶ���Ԫ�ؿ�ʼ�Ա�
	int i, j;
	for (i = 0, j = 1; j < sl->length; j++){
		//��¼���ظ���ֵ
		if (sl->data[i] != sl->data[j]){
			sl->data[++i] = sl->data[j];
		}
	}
	sl->length = i + 1;
}


//ɾ���������x~y֮���Ԫ�أ�Ҫ��x<y
bool SeqDeleteBetween(SeqList* sl, SLDataType x, SLDataType y){
	if (sl->length == 0){
		return false;
	}
	if (x >= y){
		return false;
	}
	int i, j;
	for ( i = 0; i < sl->length; i++){
		if (sl->data[i] >= x){
			break;
		}
	}
	if (i >= sl->length){
		return false;
	}
	for (j = i; j < sl->length; j++){
		if (sl->data[j] > y){
			break;
		}
	}
	while (j < sl->length){
		sl->data[i++] = sl->data[j++];
	}
	sl->length = i;
}

int main( ){
	SeqList sl;
	InitList(&sl,10);
	InsertList(&sl, 1, 8);
	InsertList(&sl, 1, 7);
	InsertList(&sl, 1, 3);
	InsertList(&sl, 1, 3);
	InsertList(&sl, 1, 2);
	InsertList(&sl, 1, 2);
	InsertList(&sl, 1, 1);

	//DeleteMinNum(&sl);

	//DeleteAllNum1(&sl, 2);
	//DeleteAllNum2(&sl, 2);
	//DeleteBetween(&sl, 1, 4);

	//SeqDeleteRepeat(&sl);
	SeqDeleteBetween(&sl, 2, 3);

	PrintList(&sl);




	system("pause");
	return 0;
}