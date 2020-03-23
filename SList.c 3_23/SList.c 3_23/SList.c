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
void SListPushBack(SList* plist, SLDataType x){
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
	while (tail->_next->_next != NULL){
		tail = tail->_next;
	}
	free(tail->_next);
	tail->_next = NULL;

}

size_t slistSize(SList* plist){
	assert(plist);
	SListNode* cur = plist->_head;
	size_t count = 0;
	while (cur != NULL){
		count++;
		cur = cur->_next;
	}
	return count;
}

//��ӡ��ʱ�򣬲���ֱ����plist->_headֱ�ӱ�������ı�ͷָ���λ�á�
void SListPrint(SList* plist){
	assert(plist);
	SListNode* head = plist->_head;
	while (head->_next != NULL){
		printf("%d->", head->_data);
		head = head->_next;
	}
	printf("%d\n", head->_data);
}


SListNode* slistReverse(SList* plist){
	assert(plist);
	SListNode* prev = NULL;
	SListNode* cur = plist->_head;
	SListNode* tail = NULL;
	while (cur){
		tail = cur->_next;
		cur->_next = prev;
		prev = cur;
		cur = tail;
	}
	return prev;
}
//�ж������Ƿ�Ϊ���Ľṹ
int isPalindrome(SList* plist){
	assert(plist);
	if (plist->_head == NULL || plist->_head->_next == NULL){
		return 1;
	}
	SListNode* fast = plist->_head;
	SListNode* slow = plist->_head;
	while (fast && fast->_next){
		fast = fast->_next->_next;
		if (fast){
			slow = slow->_next;
		}
	}
	//Ҫ����һ�ε�����Ľ����㸽�Ͽ�ָ��
	//���������ҵ��м�����ǰһ�����磺2->3->4->5,�ҵ�Ϊ3��
	SListNode* begin = plist->_head;
	SListNode* newbegin = slow->_next;
	slow->_next = NULL;
	newbegin = slistReverse(newbegin);
	while (begin && newbegin){
		if (begin->_data != newbegin->_data){
			return -1;
		}
		else{
			begin = begin->_next;
			newbegin = newbegin->_next;
		}
	}
	return 1;
}

void main(){
	SList psl;
	//	SList psl2;
	SListInit(&psl);
	//	SListInit(&psl2);
	//SListDestory(&psl);

	SListPushFront(&psl, 5);
	SListPushFront(&psl, 3);
	SListPushFront(&psl, 4);
	SListPushFront(&psl, 1);
	SListPushFront(&psl, 1);
	SListPushFront(&psl, 1);
	SListPrint(&psl);
	//SListPrint(&psl2);

	/*int i = slistSize(&psl) / 2;
	printf("%d\n", i);
	*/
	
	/*SListNode* cur = slistReverse(&psl);
	while (cur){
		printf("%d->", cur->_data);
		cur = cur->_next;
	}
	*/

	int is = isPalindrome(&psl);
	printf("%d\n", is);


	system("pause");
	return 0;
}