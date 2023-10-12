#define _CRT_SECURE_NO_WARNINGS 1

#include "LList.h"

void test1()
{
	SLTNode* plist = NULL;
	//SLPushFront(&plist, 5);
	//SLPushFront(&plist, 4); 
	//SLPushFront(&plist, 3);
	//SLPushBack(&plist, 6);

	SLPopFront(&plist);
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