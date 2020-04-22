#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef int SLDataType;
typedef struct SeqList{
	SLDataType * array;
	size_t size;
	size_t capacity;
}SeqList;

//��ʼ��˳���
void SeqListInit(SeqList* sl, size_t capacity){
	sl->array = (SLDataType*)malloc(capacity*sizeof(SLDataType));
	assert(sl->array);
	sl->size = 0;
	sl->capacity = capacity;
}

//����˳���
void SeqListDestory(SeqList* sl){
	assert(sl);
	free(sl->array);
	sl->array = NULL;
	sl->size = 0;
	sl->capacity = 0;
}


//�ڵ�i��λ�ò���
bool ListInsert(SeqList* sl, int i, SLDataType x){
	assert(sl);
	if (i<1 || i>sl->size + 1){
		return false;
	}
	//CheckCapacity(sl);
	if (sl->capacity == sl->size){
		return false;
	}
	for (int j = sl->size; j >= i; j--){
		sl->array[j] = sl->array[j - 1];
	}
	sl->array[i - 1] = x;
	sl->size++;
	return true;
}

//ɾ����i��λ�õ���
bool ListDelete(SeqList* sl, int i){
	assert(sl);
	if (i<1 || i>sl->size){
		return false;
	}
	for (int j = i; j < sl->size; j++){
		sl->array[i - 1] = sl->array[i];
	}
	sl->size--;
	return true;
}

//���ҵ�һ��ֵΪx��Ԫ�أ�������λ��
int LocateElem(SeqList* sl, SLDataType x){
	assert(sl);
	for (int i = 0; i < sl->size; i++){
		if (sl->array[i] ==  x){
			return i + 1;
		}
	}
	return 0;
}

void SeqListPrint(SeqList* sl){
	assert(sl->array);
	for (int i = 0; i < sl->size; i++){
		printf("%d ", sl->array[i]);
	}
}

int main(){
	SeqList* sq;
	SeqListInit(&sq,10);
	ListInsert(&sq, 1, 1);
	ListInsert(&sq, 1, 2);
	ListInsert(&sq, 1, 3);
	ListInsert(&sq, 1, 4);
	ListInsert(&sq, 1, 5);
	ListInsert(&sq, 1, 6);

	//ListDelete(&sq, 6);

	SeqListPrint(&sq);
	printf("\n");
	int i = LocateElem(&sq, 3);
	printf("%d ",i);
	//SeqListDestory(&sq);

	system("pause");
	return 0;
}