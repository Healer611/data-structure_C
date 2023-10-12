#define _CRT_SECURE_NO_WARNINGS 1
#include "Seqlist.h"

void test1()
{
	SL s;
	SLInit(&s);
	SLPushBack(&s, 5);
	SLPushBack(&s, 9);
	SLPushBack(&s, 50);
	SLPushFront(&s, 1);
	SLPushFront(&s, 15);
	SLPushFront(&s, 0);
	SLPopBack(&s, 50);
	SLPopFront(&s, 0);
	SLInsert(&s, 2, 555);
	SLErase(&s, 4);


	SLPrint(&s);

	int a=SLFind(&s, 15);
	printf("\n%d\n", a);
	if (a != -1)
		SLErase(&s, a);
	SLPrint(&s);

	SLDestroy(&s);
}

int main()
{
	test1();
	return 0;
}