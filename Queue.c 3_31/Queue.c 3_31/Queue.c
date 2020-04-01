#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//�ض��峣��
#define Capacity 10

typedef int QUDataType;

//�����ʵ�ֻ��ζ���

typedef struct Queue{
	QUDataType* _a;
	//Ĭ�ϻ����б�Ĵ�С�Ѿ�ȷ��
	QUDataType*	_front;
	QUDataType* _rear;
	//ָ�������ָ��
	size_t _size;
}Queue;


void QueueInit(Queue* que){
	assert(que);
	que->_a = (QUDataType*)malloc(Capacity*sizeof(QUDataType));
	assert(que->_a);
	que->_front = que->_a;
	que->_rear = que->_a;
	que->_size = 0;
}

void QueueDestory(Queue* que){
	assert(que);
	free(que->_a);
	que->_front = NULL;
	que->_rear = NULL;
	que->_size = 0;
}

//que->_front����������Ԫ�صĵ�ַ
void QueuePush(Queue* que, QUDataType x){
	assert(que);
	//��10���ռ䣬����ֻ��9��Ԫ�أ����һ���յģ������ж϶����Ƿ�Ϊ��
	if (que->_rear + 1 != que->_front + 10 ){
		*(que->_rear)= x;
		que->_rear++;
		que->_size++;
	}
	else{
		printf("��������\n");
		return -1;
	}
}

//ע��������Ƚ��ȳ�
void QueuePop(Queue* que){
	assert(que->_a);
	if (que->_rear == que->_front){
		printf("��������Ԫ�أ�����ɾ\n");
		return -1;
	}
	que->_front++;
	que->_size--;
	//��ͷָ�������һ���յ�Ԫ��ʱ��������β��
	//Ӧ����ͷָ������ָ����еĿ�ʼ
	if (que->_front == que->_a + Capacity){
		que->_front = que->_a;
	}
}

int QueueFront(Queue* que){
	assert(que);
	return *(que->_front);
}

//_rearÿ�β������ָ�������һ��λ�õĵ�ַ
//���ԣ����һ��Ԫ��Ӧ����rear����һ��ָ��Ԫ��
int QueueRear(Queue* que){
	assert(que);
	return *(que->_rear-1);
}

size_t QueueIsEmpty(Queue* que){
	assert(que);
	if (que->_front == que->_rear){
		return 1;
	}
	else{
		return 0;
	}
}


size_t QueueSize(Queue* que){
	assert(que);
	return que->_size;
}

void QueuePrint(Queue* que){
	assert(que);
	QUDataType* cur = que->_front;
	while (cur!=que->_rear){
		printf("%d->", *cur);
		cur++;
	}
	printf("\n");
	//_rearÿ�β������ָ�������һ��λ�õĵ�ַ
//	printf("%d\n", *(que->_rear));
}


int main( ){
	Queue* que;
	QueueInit(&que);
	//QueueDestory(&que);
	
	QueuePush(&que, 2);
	QueuePush(&que, 1);
	QueuePush(&que, 1);
	QueuePush(&que, 1);
	QueuePush(&que, 1);
	QueuePush(&que, 1);
	QueuePush(&que, 1);
	QueuePush(&que, 1);
	QueuePush(&que, 1);

	//QueuePush(&que, 1);
	
	QueuePop(&que);
	QueuePop(&que);
	QueuePop(&que); 
	QueuePush(&que, 3);
	QueuePush(&que, 3);
	QueuePrint(&que);

	int front = QueueFront(&que);
	printf("%d\n", front);
	int rear = QueueRear(&que);
	printf("%d\n", rear);

	system("pause");
	return 0;
}

