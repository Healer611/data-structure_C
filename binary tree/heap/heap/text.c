#define _CRT_SECURE_NO_WARNINGS 1
#include "Heap.h"

// O(N*logN)
void HeapSort(int* a, int n)
{
	// ���� -- �����
	// ���� -- ��С��


	// ����--���ϵ�������
	//for (int i = 1; i < n; i++)
	//{
	//	AdjustUp(a, i);
	//}

	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(a, n, i);
	}

	// N*logN
	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);

		// �ٵ�����ѡ����С����
		AdjustDown(a, end, 0);

		--end;
	}
	
				
}

int main()
{
	int a[] = { 7,8,3,5,1,9,5,4 };
	HeapSort(a, sizeof(a) / sizeof(int));
	for (int i = 0; i < 8; i++) {
		printf("%d  ", a[i]);
	}
	return 0;
}

//---���ԶѺ�������---
//int main()
//{
//	HP hp;
//	HeapInit(&hp);
//	int a[] = { 65,100,70,32,50,60 };
//	for (int i = 0; i < sizeof(a) / sizeof(int); ++i)
//	{
//		HeapPush(&hp, a[i]);
//	}
//	
//	while (!HeapEmpty(&hp))
//	{
//		int top = HeapTop(&hp);
//		printf("%d\n", top);
//		HeapPop(&hp);
//	}
//
//	return 0;
//}