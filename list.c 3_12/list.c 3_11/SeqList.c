#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLDataType;
typedef struct SeqList{
	SLDataType * array;
	size_t size;
	size_t capacity;
}SeqList;

//��ʼ��˳���
void SeqListInit(SeqList* sl, size_t capacity){
	sl->array = malloc(capacity*sizeof(SLDataType));
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

//�������
void CheckCapacity(SeqList* sl){
	assert(sl);
	if (sl->size >= sl->capacity){
		size_t newcapacity = sl->capacity * 2;
		SLDataType* newarray = malloc(sizeof(SLDataType)* newcapacity);
		assert(newarray);
		for (int i = 0; i < sl->size; i++){
			newarray[i] = sl->array[i];
		}
		free(sl->array);
		sl->array = newarray;
		sl->capacity = newcapacity;
	}
	else{
		return;
	}
}

//β��
void SeqListPushBack(SeqList* sl, SLDataType x){
	assert(sl);
	CheckCapacity(sl);
	sl->array[sl->size] = x;
	sl->size++;
}
//βɾ
void SeqListPopBack(SeqList* sl){
	assert(sl->size);
	sl->size--;
}

//ͷ��
void SeqListPushFront(SeqList* sl, SLDataType x){
	assert(sl);
	CheckCapacity(sl);
	for (int i = sl->size - 1; i >= 0; i--){
		sl->array[i + 1] = sl->array[i];
	}
	sl->array[0] = x;
	sl->size++;
}

//ͷɾ
void SeqListPopFront(SeqList* sl){
	assert(sl->size);
	for (int i = 0; i < sl->size - 1; i++){
		sl->array[i] = sl->array[i + 1];
	}
	sl->size--;
}


//���루pos��ʾ����Ҫ����Ԫ��λ�õ��±꣩
void SeqListInsert(SeqList* sl, size_t pos, SLDataType x){
	assert(sl->array);
	assert(pos >= 0 && pos <= sl->size);
	for (int i = sl->size - 1; i >= pos; i--){
		sl->array[i + 1] = sl->array[i];
	}
	sl->array[pos] = x;
	sl->size++;
}

void SeqListErase(SeqList* sl, size_t pos){
	assert(sl->array);
	assert(pos >= 0 && pos < sl->size);
	for (int i = pos; i < sl->size - 1; i++){
		sl->array[i] = sl->array[i + 1];
	}
	sl->size--;
}


size_t SeqListFind(SeqList* sl, SLDataType x){
	assert(sl);
	for (int i = 0; i < sl->size; i++){
		if (sl->array[i] == x){
			return i;
		}
	}
	return -1;
}


//ɾ������ֵΪx��Ԫ��
void SeqListRemove(SeqList* sl, SLDataType x){
	assert(sl->array);
	int pos = SeqListFind(sl, x);
	if (pos == -1){
		return;
	}
	else{
		SeqListErase(sl, pos);
	}
}

void SeqListModify(SeqList* sl, size_t pos, SLDataType x){
	assert(sl->array);
	assert(pos >= 0 && pos < sl->size);
	sl->array[pos] = x;
}


void SeqListPrint(SeqList* sl){
	assert(sl->array);
	for (int i = 0; i < sl->size; i++){
		printf("%d ", sl->array[i]);
	}
}

//ð��������������
void SeqListBubbleSort(SeqList* sl){
	for (int i = 0; i <sl->size; i++){
		for (int j = 0; j < i; j++){
		if (sl->array[j] > sl->array[i]){
			int tmp = sl->array[i];
			sl->array[i] = sl->array[j];
			sl->array[j] = tmp;
		}
	  }
	}
}

//���ֲ��ң�ǰ���ǣ���������
int SeqListBinaryFind(SeqList* sl, SLDataType x){
	int begin = 0;
	int end = sl->size-1;
	//int mid = (begin + end) / 2;
	while (begin<=end){
		int mid = (begin + end) / 2;
		if (x == sl->array[mid]){
			return mid;
		}
		else if (x > sl->array[mid]){
			begin = mid+1;
		}
		else {
			end = mid-1;
		}
	}
	if (begin > end){
		return -1;
	}
}


//ɾ��ֵΪX������Ԫ��
void SeqListRemoveAll(SeqList* sl, SLDataType x){
	int i, j;
	for (i = 0, j = 0; i < sl->size; i++){
		if (sl->array[i] != x){
			sl->array[j] = sl->array[i];
			j++;
		}
	}
	sl->size = j;
}


void main(){
	SeqList sl;
	SeqListInit(&sl, 10);
	SeqListPushBack(&sl, 6);
	SeqListPushBack(&sl, 5);
	SeqListPushBack(&sl, 10);
	SeqListPushBack(&sl, 3);
	SeqListPushBack(&sl, 1);
	SeqListPushBack(&sl, 10);
	SeqListPushBack(&sl, 3);
	SeqListPushBack(&sl, 1);

	//SeqListBubbleSort(&sl);

	//int key = SeqListBinaryFind(&sl, 10);
	//printf("%d ", key);


	SeqListRemoveAll(&sl, 3);

	SeqListPrint(&sl);
	//SeqListDestory(&sl);
	system("pause");
	return 0;
}
