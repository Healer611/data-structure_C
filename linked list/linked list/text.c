#define _CRT_SECURE_NO_WARNINGS 1

#include "SList.h"

void test1()
{
	SLTNode* plist = NULL;
	SLPushFront(&plist, 5);
	SLPushFront(&plist, 4); 
	SLPushFront(&plist, 3);
	SLPushBack(&plist, 6);

	//SLPopFront(&plist);

	SLTNode* pos = STFind(plist, 3);
	SLInsert(&plist, pos, 99);

	//pos = STFind(plist, 2);
	//if (pos)
	//{
	//	SLInsertAfter(pos, 20);
	//}
	
	//SLPopBack(&plist);
	//SLPopBack(&plist);
	//SLPopBack(&plist);
	//SLPopBack(&plist);
	//SLPopBack(&plist);

	SLTPrint(plist);
}

int main()
{
	test1();
	return 0;
}