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

SListNode* SListFind(SList* plist, SLDataType x){
	    assert(plist);
		SListNode* tNode = plist->_head;
		while (tNode != NULL){
			if (tNode->_data != x){
				tNode = tNode->_next;
			}
			else{
				return tNode;
			}
		}
		return -1;
		
}

//��pos�ĺ��������(posλ�ò����ڣ�pos��ͷ�ϣ�pos�ں��)
void SListInsertAfter(SList*plist,SListNode* pos, SLDataType x){
	assert(plist);
	SListNode* newNode = BuySListNode(x);
	assert(newNode);
	if (pos == -1){
		return - 1;
	}
	else if (pos == plist->_head){
		SListPushFront(plist,x);
	}
	else{
		SListNode* tNode = plist->_head->_next;
		while (tNode != pos){
			tNode = tNode->_next;
		}
		tNode = pos->_next;
		pos->_next = newNode;
		newNode->_next = tNode;
	}
}

//��pos�ĺ���ɾ�����
void SListEraseAfter(SList*plist, SListNode* pos){
	assert(plist);
	if (pos == -1){
		return -1;
	}
	else if (pos == plist->_head){
		SListPopFront(plist);
	}
	else{
		SListNode* tNode = plist->_head->_next;
		while (tNode != pos){
			tNode = tNode->_next;
		}
		SListNode* cur = tNode->_next;
		SListNode* tail = tNode->_next->_next;
		free(cur);
		tNode->_next = tail;
	}
}

//ɾ�������е�ֵΪX��Ԫ��
void SListRemove(SList* plist, SLDataType x){
	assert(plist);
	SListNode* bNode = plist->_head;
	if (bNode->_data == x){
		SListNode* cur = bNode;
		free(bNode);
		cur->_next = plist->_head;
		return;
	}
	else{
		SListNode* tNode = plist->_head->_next;
		while (tNode->_data != x){
			bNode = bNode->_next;
			tNode = tNode->_next;
		}
		SListNode* eNode = tNode->_next;
		free(tNode);
		bNode->_next = eNode;
	}
}

//ɾ��������ֵΪval������Ԫ��
SListNode*  removeElements(SList* plist, int val) {
//��������ָ���㣬����������������������ֵ<�Ƿ�Ϊͷ��>�����ڲ�����������ֵ��
	/*SListNode* prev = NULL;
	SListNode* cur = plist->_head;
	SListNode* tail = NULL;
	while (cur != NULL){
		if (cur->_data == val){
			tail = cur->_next;
			free(cur);
			cur = tail;
			if (prev == NULL){
				plist->_head = tail;
			}
			else{
				prev->_next = tail;
			}
		}
		else{
			prev = cur;
			cur = cur->_next;
		}
	}
	return plist->_head;
	*/

	SListNode* head = plist->_head;
	if (head == NULL){
		return NULL;
	}
	while (head->_data==val && head!=NULL)
	{
		SListNode* tnode = head;
		head = head->_next;
		free(tnode);
	}
	SListNode* cur = head->_next;
	SListNode* prev = head;
	while (cur != NULL){
		if (cur->_data == val){
			SListNode* tail = cur->_next;
			free(cur);
			prev->_next = tail;
			cur = tail;
		}
		else{
			prev = cur;
			cur = cur->_next;
		}
	}
	return plist->_head;
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
	SListPushFront(&psl, 2);
	SListPushFront(&psl, 5);
	SListPushFront(&psl, 6);
	SListPopFront(&psl);

	SList* s = removeElements(&psl, 2);
	SListPrint(&s);

	//BuySListNode(&psl, 1);
	/*
	SListPushBack(&psl, 6);
	SListPopBack(&psl);

	SListNode* pos = SListFind(&psl, 32);
	SListInsertAfter(&psl,pos,12);
	SListEraseAfter(&psl, pos);
    
	SListRemove(&psl, 1);
	*/

	SListPrint(&psl);
	system("pause");
	return 0;
}