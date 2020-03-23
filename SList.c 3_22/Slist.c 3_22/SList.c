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


//�ָ�����(��ʱ��buynode��s11��s22����Ͳ��ð�next�ÿգ�
//��Ϊbuynode�������Ѿ�������)
SListNode* partition(SList* plist, int x){
	assert(plist);
	if (plist->_head == NULL || plist->_head->_next == NULL){
		return plist->_head;
	}
	SListNode* cur = plist->_head;
	SListNode* s1 = BuySListNode(0);
	SListNode* s2 = BuySListNode(0);
	SListNode* s11 = s1;
	SListNode* s22 = s2;
	while (cur != NULL){
		if (cur->_data < x){
			s1->_next = cur;
			s1 = s1->_next;
		}
		else{
			s2->_next = cur;
			s2 = s2->_next;
		}
		cur = cur->_next;
	}
	s1->_next = s22->_next;
	return s11->_next;
}

//����һ�������б�ɾ���������ظ��Ľ��,ֻ����һ��
SListNode* deleteDuplicate(SList* plist){
	assert(plist);
	SListNode* cur = plist->_head;
	SListNode* tail = plist->_head->_next;
	SListNode* s = BuySListNode(0);
	SListNode* s1 = s;
	while (tail != NULL){
		if (cur->_data != tail->_data){
			s1->_next = cur;
			s1 = s1->_next;	
		}
		cur = tail;
		tail = tail->_next;
	}
	return s->_next;
}


//����һ�������б�ɾ���������ظ��Ľ��
SListNode* deleteDuplicates(SList* plist){
	assert(plist);
	SListNode* prev = NULL;
	SListNode* cur = plist->_head;
	SListNode* tail = plist->_head->_next;
	if (plist->_head == NULL || plist->_head->_next == NULL)
	{
		return plist->_head;
	}
	while (tail){
		if (cur->_data == tail->_data){
			tail = tail->_next;
			while (tail){
				if (cur->_data != tail->_data){
					break;
				}
				else{
					tail = tail->_next;
				}
			}
			while (cur != tail){
				SListNode* tnode = cur;
				cur = cur->_next;
				free(tnode);

			}
			if (prev == NULL){
				plist->_head = tail;
			}
			else{
				prev->_next = tail;
			}
			if (tail){
				tail = tail->_next;
			}
		}
		else{
			prev = cur;
			cur = tail;
			tail = tail->_next;
		}
	}
	return plist->_head;
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

void main(){
	SList psl;
//	SList psl2;
	SListInit(&psl);
//	SListInit(&psl2);
	//SListDestory(&psl);

	SListPushFront(&psl, 5);
	SListPushFront(&psl, 4);
	SListPushFront(&psl, 4);
	SListPushFront(&psl, 3);
	SListPushFront(&psl, 3);
	SListPushFront(&psl, 2);
	/*
	SListPushFront(&psl2, 4);
	SListPushFront(&psl2, 2);
	SListPushFront(&psl2, 1);
	*/


	SListPrint(&psl);
	//SListPrint(&psl2);

/*	SListNode* cur = partition(&psl, 3);
	while (cur != NULL){
		printf("%d->", cur->_data);
		cur = cur->_next;
	}
*/

	SListNode* cur = deleteDuplicates(&psl);
	while (cur != NULL){
		printf("%d->", cur->_data);
		cur = cur->_next;
	}
	system("pause");
	return 0;
}