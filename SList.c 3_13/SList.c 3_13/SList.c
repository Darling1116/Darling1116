#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLDataType;
//��㣨���ݺ�ָ����һ������ָ�룬������Ϊ���ָ�룩
typedef struct SListNode{
	SLDataType _data;
	struct  SListNode* _next;
}SListNode;
//��������������:����ͷ��㣩
typedef struct SList{
	SListNode* _head;
}SList;


void SListInit(SList* plist){
	assert(plist);
	plist->_head = NULL;
}


//�������������ʱ��Ҫ��ʼɾ��(Ҫ��¼ÿ��ɾ��������һ����㣩
void SListDestory(SList* plist){
	assert(plist);
	while (plist->_head){
		SListNode* tNode = plist->_head->_next;
		free(plist->_head);
		plist->_head = tNode;
	}
}


SListNode* BuySListNode(SLDataType x){
	SListNode* newNode = (SListNode*)malloc(sizeof(SListNode));
	assert(newNode);
	newNode->_data = x;
	newNode->_next = NULL;
	return newNode;
}

//����ͷ�壨�����ǰ����Ϊ�գ��Ͱ��½�㵱���������㣬
//ԭ��������ͱ��������ĵڶ�����㣩
void SListPushFront(SList* plist, SLDataType x){
	assert(plist);
	SListNode* newNode = BuySListNode(x);
	assert(newNode);
	if (plist->_head == NULL){
		plist->_head = newNode;
		return;
	}
	else{
		newNode->_next = plist->_head;
		plist->_head = newNode;
	}

}

void SListPopFront(SList* plist){
	assert(plist);
	SListNode* tNode = plist->_head->_next;
	free(plist->_head);
	plist->_head = tNode;
}

//β�壺�޽��
//�Ѿ��н�㣨�ҵ����һ������ٲ����½�㣩
void SListPushBack(SList* plist,SLDataType x){
	assert(plist);
	SListNode* newNode = BuySListNode(x);
	assert(newNode);
	if (plist->_head == NULL){
		plist->_head = newNode;
	}
	else{
		SListNode* tail = plist->_head;
		while (tail->_next){
			tail = tail->_next;
		}
		tail->_next = newNode;
	}
}


//βɾ����һ����㣻
//�ж����㣺Ҫ��¼�����ڶ�������λ��
void SListPopBack(SList* plist){
	assert(plist->_head);
	SListNode* tail = plist->_head;
	if (tail->_next == NULL){
		free(tail);
		plist->_head = NULL;
	}
	while (tail->_next->_next!=NULL){
		tail = tail->_next;
	}
	free(tail->_next);
	tail->_next = NULL;

}

void SListPrint(SList* plist){
	assert(plist);
	while (plist->_head){
		printf("%d->", plist->_head->_data);
		plist->_head = plist->_head->_next;
	}
}

void main(){
	SList psl;
	SListInit(&psl);
	//SListDestory(&psl);

	SListPushFront(&psl, 1);
	SListPushFront(&psl, 2);
	SListPushFront(&psl, 3);
	SListPopFront(&psl);
	//BuySListNode(&psl, 1);

	SListPushBack(&psl, 6);
	SListPopBack(&psl);

	SListPrint(&psl);
	system("pause");
	return 0;
}