#define _CRT_SECURE_NO_WARNINGS
#include "SList.h"

void SListInit(SList *plist)
{
	assert(plist);
	plist->_head = NULL;
}

void SListPrint(SList *plist)
{
	assert(plist);
	SListNode *cur = plist->_head;
	while (cur != NULL)
	{
		printf("%d->", cur->_data);
		cur = cur->_next;
	}
	printf("NULL\n");
}

void SListDestory(SList *plist)
{
	assert(plist);
	SListNode *cur = plist->_head;
	SListNode *next = NULL;
	while (cur != NULL)
	{
		next = cur->_next;
		free(cur);
		cur = next;
	}
	plist->_head = NULL;
}

SListNode* BuyNode(SLDataType x)
{
	SListNode *pnode = (SListNode*)malloc(sizeof (SListNode));
	pnode->_data = x;
	pnode->_next = NULL;
	return pnode;
}


void SListPushFront(SList *plist, SLDataType x)
{
	assert(plist);
	SListNode* newnode = BuyNode(x);
	newnode->_next = plist->_head;
	plist->_head = newnode;
}

void SListPushBack(SList *plist, SLDataType x)//ע���Ϊ���޽���������
{
	assert(plist);
	SListNode* newnode = BuyNode(x);
	SListNode* tail = plist->_head;
	if (tail == NULL)
	{
		plist->_head = newnode;
	}
	//SListNode* tail = plist->_head;
	else
	{
		while (tail->_next != NULL)
		{
			tail = tail->_next;
		}
		tail->_next = newnode;
		//newnode->_next = NULL;
	}
	newnode->_next = NULL;
}
SListNode *SListFind(SList *plist, SLDataType x)
{
	assert(plist);
	SListNode *cur = plist->_head;
	while (cur)
	{
		if (cur->_data == x)
		{
			return cur;
		}
		else
		{
			cur = cur->_next;
		}
	}

}

void SListInsertAfter(SListNode *pos, SLDataType x)
{
	assert(pos);
	SListNode *newnode = BuyNode(x);
	newnode->_next = pos->_next;
	pos->_next = newnode;

}

void  SListEraseAfter(SListNode *pos)
{
	assert(pos && pos->_next);
	SListNode *tail = pos->_next->_next;
	free(pos->_next);
	pos->_next = tail;
}

//SListNode* partition(SList* plist,SLDataType x)
////�Ը���ֵxΪ��׼������ָ�������֣�����С��x�Ľ�����ڴ��ڻ����x�Ľ��֮ǰ
//{
//	assert(plist);
//	SListNode *lesshead = (SListNode *)malloc(sizeof (SListNode));
//	SListNode *morehead = (SListNode *)malloc(sizeof (SListNode));
//	//��ÿһ����������һ���ƽ�㣬������������ݣ�û����Чֵ��
//	SListNode *pless = lesshead;
//	SListNode *pmore = morehead;
//	SListNode *cur = plist->_head;
//	while (cur)
//	{
//		if (cur->_data < x)
//		{
//			pless->_next = cur;
//			pless = pless->_next;
//		}
//		else
//		{
//			pmore->_next = cur;
//			pmore = pmore->_next;
//		}
//		cur = cur->_next;
//	}
//	pless->_next = morehead->_next;
//	pmore->_next = NULL;
//	plist->_head = lesshead->_next;
//	free(lesshead);
//	free(morehead);
//	return plist->_head;
//}

SListNode* deleteDuplication(SList* plist)
//��һ������������У������ظ��Ľ�㣬��ɾ�����������ظ��Ľ��.
//�ظ��Ľ�㲻��������������ͷָ�롣
{
	assert(plist);
	SListNode *prev = NULL;
	SListNode *cur = plist->_head;
	SListNode *tail = plist->_head->_next;
	while (tail)
	{
		if (cur == NULL || tail == NULL)
		{
			return plist->_head;
		}
		if (cur->_data == tail->_data)
		{
			while (tail)
			{
				if (cur->_data != tail->_data)
				{
					break;
				}
				tail = tail->_next;
			}
			while (cur != tail)
			{
				SListNode *tmp = cur->_next;
				free(cur);
				cur = tmp;
			}
			if (prev == NULL)
			{
				plist->_head == tail;
			}
			else
			{
				prev->_next = tail;
			}
			if (tail)
			{
				tail = tail->_next;//
			}

		}
		prev = cur;
		cur = tail;
		tail = tail->_next;
	}
	return plist->_head;
}

SListNode* chkPalindrome(SList *plist)
//����һ�����������һ��ʱ�临�Ӷ�ΪO(n), ����ռ临�Ӷ�ΪO(1)���㷨���ж����Ƿ�Ϊ���Ľṹ��
//����һ�������ͷָ��A���뷵��һ��boolֵ���������Ƿ�Ϊ���Ľṹ����֤������С�ڵ���900��
//����������
//1->2->2->1
//���أ�true
{
	assert(plist);

}

void test()
{
	SList plist;
	SListInit(&plist);

	SListPushFront(&plist, 3);
	SListPushFront(&plist, 6);
	SListPushFront(&plist, 1);
	SListPushFront(&plist, 1);
	SListPushFront(&plist, 2);
	SListPushFront(&plist, 2);
	SListPushFront(&plist, 1);

	//SListInsertAfter(SListFind(&plist, 1), 8);
	//SListInsertAfter(SListFind(&plist, 2), 8);
	SListPrint(&plist);

	
	/*partition(&plist, 9);*/
	deleteDuplication(&plist);

	SListPrint(&plist);

	SListDestory(&plist);
}
