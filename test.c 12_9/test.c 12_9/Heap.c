#define _CRT_SECURE_NO_WARNINGS
#include "Heap.h"

void HeapInit(Heap *hp, HPDataType *a, size_t n)
{
	assert(hp && a);
	hp->_array = (HPDataType *)malloc(n*sizeof(HPDataType));//������hp->_array���ٿռ䡣
	hp->_size = n;
	hp->_capacity = n;
	memcpy(hp->_array, a, n*sizeof(HPDataType));//������a�ŵ�hp->_array�С�
}

void Adjustdown(HPDataType *a, size_t n, int parent)//���µ�����������������������ݡ�
//Ĭ�ϵ��ɴ�ѡ�
{
	assert(a);
	int child = parent * 2 + 1;//Ĭ��childΪ���ӡ�

	while (child < n)
	{
		if (a[child] < a[child + 1] && (child+1)<n)
		{
			child++;
		}
		if (a[parent] < a[child])
		{
			HPDataType *tmp = a[parent];
			a[parent] = a[child];
			a[child] = tmp;

			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;//���parent �� child����Ҫ�������ͽ������ν����Ĳ��衣
		}
	}
}

void Adjustup(HPDataType *a, size_t n, int child)
//Ĭ�ϵ��ɴ�ѡ�
{
	assert(a);
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (a[child] > a[parent])
		{
			HPDataType *tmp = a[child];
			a[child] = a[parent];
			a[parent] = tmp;

			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}

}

void HeapSort(Heap *hp,HPDataType *a)
{
	assert(hp&&a);
	int i = hp->_size - 1;
	for ((i - 1)/2; i >= 0; i--)//
	{
		Adjustup(a, 9, i);
	}

}

void Heappush(Heap *hp, HPDataType x)
{
	assert(hp);
	if (hp->_size == hp->_capacity)
	{
		hp->_capacity *= 2;
		hp->_array = realloc(hp->_array, hp->_capacity*sizeof(HPDataType));
	}
	hp->_array[hp->_size] = x;
	hp->_size++;

}
void Heappop(Heap *hp)
{
	assert(hp);
	HPDataType *tmp = hp->_array[0];
	hp->_array[0] = hp->_array[hp->_size - 1];
	hp->_array[hp->_size - 1] = tmp;

	hp->_size--;

}

int  HeapSize(Heap *hp)
{
	assert(hp);
	return hp->_size;
}

int HeapEmpty(Heap *hp)
{
	assert(hp);
	return (hp->_size > 0 ? 1: -1);
}
void HeapPrint(Heap *hp)
{
	assert(hp);
	int i = 0;
	for (i = 0; i < hp->_size; i++)
	{
		printf("%d ", hp->_array[i]);
	}
	printf("\n");
}

void HeapDestory(Heap *hp)
{
	assert(hp);
	free(hp->_array);
	hp->_size = 0;
	hp->_capacity = 0;
}

void test()
{
	int a[] = { 2, 8, 6, 8, 1,8,8,8,8 };
	HeapInit(&hp, a, 9);
	Heappush(&hp, 3);
	Heappop(&hp);
	HeapSort(&hp, a);
	HeapPrint(&hp);

	printf("%d\n", HeapSize(&hp));
	printf("%d\n", HeapEmpty(&hp));
	
	HeapDestory(&hp);
}
