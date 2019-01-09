#define _CRT_SECURE_NO_WARNINGS
#include "Queue.h"

Queue pq;
void QueueInit(Queue* pq)
{

	pq->_prev = NULL;
	//pq->_tail = NULL;
}

void QueueDestory(Queue* pq)//�������ͷ�ʱ��ÿһ����㶼Ҫ�ͷš�
{
	QueueNode* cur = pq->_prev;
	while (cur)
	{
		QueueNode* tail = cur->_next;
		free(cur);
		cur = tail;
	}
	pq->_prev = NULL;
}

Queue* BuyQueueNode(QUDataType x)
{
	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
	newnode->_data = x;
	newnode->_next = NULL;
	return newnode;
}

void QueuePush(Queue* pq, QUDataType x)
//�ն���  ��   �ǿն���
{
	assert(pq);
	QueueNode* cur = BuyQueueNode(x);
	if (pq->_prev == NULL)
	{
		pq->_prev = pq->_tail = cur;
		return;//return����˼�ǲ�Ҫ��������Ĳ��衣
	}
	//QueueNode* cur = BuyQueueNode(x);
	pq->_tail ->_next= cur;
	pq->_tail = pq->_tail->_next;
}

void QueuePop(Queue* pq)//�Ƚ��ȳ�
//�ն���  ��   �ǿն���
{
	if (pq->_prev == NULL)
	{
		return;
	}
	if (pq->_prev == pq->_tail)
	{
		pq->_tail = NULL;
	}
	QueueNode* cur = pq->_prev;
	pq->_prev = pq->_prev->_next;
	free(cur);
}

//Ĭ���Ѿ������ݿ�ȡ
QUDataType QueueFront(Queue* pq)//ȡͷ����ʱ
{
	return pq->_prev->_data;
}

QUDataType QueueBack(Queue* pq)//ȡβ����
{
	return pq->_tail->_data;
}

int QueueEmpty(Queue* pq)
{
	if (pq->_prev != NULL)
	{
		return 1;
	}
	return 0;
}

int QueueSize(Queue* pq)
{
	QueueNode* cur = pq->_prev;
	int size = 0;
	while (cur != NULL)
	{
		size++;
		cur = cur->_next;
	}
	return size;
}

void TestQueue()
{
	QueueInit(&pq);
	//QueueDestory(&pq);
	//printf("%d", BuyQueueNode(2));
	BuyQueueNode(2);
	//printf ("%d ",QueuePush(&pq, 3));
	QueuePush(&pq, 3);
	QueuePush(&pq, 3);
	QueuePush(&pq, 3);
	QueuePush(&pq, 3);
	QueuePop(&pq);
	printf("%d ", QueueFront(&pq));
	QueueDestory(&pq);
}
