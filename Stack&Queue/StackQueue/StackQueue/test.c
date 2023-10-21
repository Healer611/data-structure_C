#define _CRT_SECURE_NO_WARNINGS 1
#include "Stack.h"

void test1()
{
	ST st;
	STInit(&st);
	STPush(&st, 999);
	STPush(&st, 99);
	STPush(&st, 9);
	printf("%d ", STTop(&st));
	STPop(&st);
	printf("%d ", STTop(&st));
}

int main()
{
	test1();
	return 0;
}