#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

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
	que->_a = (QUDataType*)malloc(10*sizeof(QUDataType));
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

void QueuePush(Queue* que, QUDataType x){
	assert(que);
	if (que->_rear + 1 - 10 != que->_front && que->_front == que->_a){
		*(que->_rear) = x;
		que->_rear++;
		que->_size++;
	}
	else{
		printf("��������\n");
		return -1;
	}
}



int main( ){
	Queue* que;
	QueueInit(&que);
	//QueueDestory(&que);

	QueuePush(&que, 1);

	system("pause");
	return 0;
}

