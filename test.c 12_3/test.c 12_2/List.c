#include "List.h"
List plist;

ListNode *BuyNode(LTDataType x)//Buynode������ֻ�ǲ���һ�����
{
	ListNode *pnode = (ListNode*)malloc(sizeof (ListNode));
	pnode->_data = x;
	pnode->_next = NULL;
	pnode->_prev = NULL;
}

void ListInit(List *plist)
{
	assert(plist);
	ListNode *head = BuyNode(-1);
	head->_next = head;
	head->_prev = head;

	plist->_head = head;//��ͷָ��ָ���һ��û����Чֵ�Ľ�㣬��Ϊ��ͷ
}

void Listpushback(List *plist, LTDataType x)
{
	//assert(plist);
	//ListNode *tail = plist->_head->_prev;
	//ListNode *newnode = BuyNode(x);
	//tail->_next = newnode;
	//newnode->_prev = tail;
	//newnode->_next = plist->_head;
	//plist->_head->_prev = newnode;

	ListInsert(plist->_head, x);
}

void Listpushfront(List *plist, LTDataType x)
{
	//assert(plist);
	//ListNode *cur = plist->_head->_next;
	//ListNode *newnode = BuyNode(x);
	//newnode->_next = cur;
	//cur->_prev = newnode;
	//plist->_head->_next = newnode;
	//newnode->_prev = plist->_head;

	ListInsert(plist->_head->_next, x);

}


void Listpopback(List *plist)
{
	//assert(plist && plist->_head->_next != plist->_head);//Ҫ��֤�н�����ɾ
	//	ListNode *cur = plist->_head->_prev;
	//	ListNode *tail = cur->_prev;
	//	free(cur);
	//	tail->_next = plist->_head;
	//	plist->_head->_prev = tail;

	ListErase(plist->_head->_prev);

}

void Listpopfront(List *plist)
{
	//assert(plist && plist->_head->_next != plist->_head);
	//ListNode *cur = plist->_head->_next;
	//ListNode *tail = cur->_next;
	//free(cur);
	//plist->_head->_next = tail;
	//tail->_prev = plist->_head;

	ListErase(plist->_head->_next);
}

ListNode *ListFind(List *plist,LTDataType x)
{
	assert(plist);
	ListNode *head = plist->_head->_next;
	ListNode *cur = head->_next;
	while (cur->_next != head)
	{
		if (cur->_data == x)
		{
			return cur;
		}
		cur = cur->_next;
	}
}


void ListPrint(List *plist)
{
	assert(plist);
	printf("<-head->");
	ListNode *cur = plist->_head->_next;//��˫�������У�ͷ��㲻����Чֵ������Ҫ����ӡ��
	while (cur != plist->_head)
	{
		printf("<-%d->", cur->_data);
		cur = cur->_next;
	}
	printf("\n");
}

void ListDestory(List *plist)
{
	assert(plist);
	ListNode *head = plist->_head;
	ListNode *cur = head->_next;
	while (cur != head)
	{
		ListNode *next = cur->_next;
		free(cur);
		cur = next;
	}
	//�ͷŵ�ʱ��Ҫ��ͷ���Ҳ�ͷŵ�
	free(head);
	plist->_head = NULL;
}

void ListInsert(ListNode *pos, LTDataType x)//��posǰ�����һ����
{
	assert(pos);
	ListNode *newnode = BuyNode(x);
	ListNode *cur = pos->_prev;

	cur->_next = newnode;
	newnode->_prev = cur;
	newnode->_next = pos;
	pos->_prev = newnode;
}

void ListErase(ListNode *pos)//ɾ��pos������
{
	assert(pos);
	ListNode *cur = pos->_prev;
	ListNode *tail = pos->_next;
	free(pos);

	cur->_next = tail;
	tail->_prev = cur;
}

//int ListSize(List *plist)
//{
//	assert(plist);
//	ListNode *cur = plist->_head->_next;
//	int count = 0;
//	while (cur != plist->_head)
//	{
//		count++;
//		cur = cur->_next;
//	}
//	return count;
//}
//
//int ListEmpty(List *plist)
//{
//	assert(plist);
//	ListNode *head = plist->_head;
//	if (head->_next != head)
//	{
//		return 1;
//	}
//	else
//	{
//		return 0;
//	}
//
//}

//void ListReserve(List *plist)//����һ�����ǰ��ָ��ķ�����
//{
//	assert(plist);
//	ListNode *head = plist->_head;
//	ListNode *cur = head->_next;
//	while (cur != head)
//	{
//		ListNode *ptmp = cur->_prev;
//		cur->_prev = cur->_next;
//		cur->_next = ptmp;
//
//		//cur = cur->_next;
//		//��cur��_next��_prev������ָ�뽻��λ�ú�cur����һ����㲻������cur->_nextȥѰ�ҡ�
//		cur = cur->_prev;
//	}
//	ListNode *tmp = head->_prev;
//	head->_prev = head->_next;
//	head->_next = tmp;
//}

void ListReserve(List *plist)//���ν�����ǰ�˺����������ڵ��data��
{
	assert(plist);
	ListNode *head = plist->_head;
	ListNode *begin = head->_next;
	ListNode *end = head->_prev;
	while (begin != end && end->_next != begin)
	{
		LTDataType tmp = begin->_data;
		begin->_data = end->_data;
		end->_data = tmp;

		begin = begin->_next;//ע�ⲻ����begin++
		end = end->_prev;
	}
}
void test1()
{
	ListInit(&plist);
	Listpushback(&plist, 1);
	Listpushback(&plist, 2);
	Listpushback(&plist, 3);
	Listpushback(&plist, 5);
	Listpushback(&plist, 6);
	Listpushfront(&plist, 8);
	Listpushfront(&plist, 9);

	//Listpopback(&plist);
	//Listpopfront(&plist);

	//ListInsert(ListFind(&plist,3), 8);
	//ListErase(ListFind(&plist, 2));
    
	ListPrint(&plist);

	//printf("%d\n", ListSize(&plist));
	//printf("%d\n", ListEmpty(&plist));
	ListDestory(&plist);
}

void test2()
{
	ListInit(&plist);
	Listpushback(&plist, 1);
	Listpushback(&plist, 2);
	Listpushback(&plist, 3);
	Listpushback(&plist, 5);
	Listpushback(&plist, 6);
	Listpushfront(&plist, 8);
	Listpushfront(&plist, 9);

	ListReserve(&plist);

	ListPrint(&plist);
	ListDestory(&plist);

}

