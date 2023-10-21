#define _CRT_SECURE_NO_WARNINGS 1
#include "Stack.h"
void STInit(ST* pst)
{
	assert(pst);
	pst->a = NULL;
	pst->top = 0;
	pst->capacity = 0;
}

void STDestroy(ST* pst)
{
	assert(pst);
	free(pst->a);
	pst->top = 0;
	pst->capacity = 0;
}

void STPush(ST* pst, STDataType x)
{
	if (pst->top == pst->capacity) {
		int newCapacity = pst->capacity == 0 ? 4 : pst->capacity * 2;
		STDataType* tmp = (STDataType*)realloc(pst->a, sizeof(STDataType) * newCapacity);
		if(tmp==NULL){
			perror("realloc fail");
			return;
		}
		pst->a = tmp;
		pst->capacity = newCapacity;
	}
	pst->a[pst->top] = x;
	pst->top++;
}

void STPop(ST* pst)
{
	assert(pst);
	assert(!STEmpty(pst));
	pst->top--;
}

bool STEmpty(ST* pst)
{
	assert(pst);
	return pst->top == 0;
}

STDataType STTop(ST* pst)
{
	assert(pst);
	assert(!STEmpty(pst));
	return pst->a[pst->top - 1];
}

int STSize(ST* pst)
{
	assert(pst);
	return pst->top;
}