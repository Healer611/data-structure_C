#define _CRT_SECURE_NO_WARNINGS 1
#include "List.h"

void test1() {
	LTNode* plist = LTInit();
	LTPushFront(plist, 1);
	LTPushFront(plist, 2);
	LTPushFront(plist, 3);
	LTPushFront(plist, 4);
	LTPushBack(plist, 888);
	LTPushBack(plist, 888);

	LTNode* pos = LTFind(plist, 888);
	LTInsert(pos, 999);

	LTErase(pos);

	LTPrint(plist);
	LTDestroy(&plist);
}

int main()
{
	test1();
	return 0;
}