#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

//20. ÓÐÐ§µÄÀ¨ºÅ
//https://leetcode.cn/problems/valid-parentheses/submissions/
typedef char STDataType;
typedef struct Stack
{
	STDataType* a;
	int top;
	int capacity;
}ST;

void STInit(ST* pst);
void STDestroy(ST* pst);
void STPush(ST* pst, STDataType x);
void STPop(ST* pst);
STDataType STTop(ST* pst);
bool STEmpty(ST* pst);
int STSize(ST* pst);

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
	pst->a = NULL;
	pst->top = 0;
	pst->capacity = 0;
}

void STPush(ST* pst, STDataType x)
{
	if (pst->top == pst->capacity) {
		int newCapacity = pst->capacity == 0 ? 4 : pst->capacity * 2;
		STDataType* tmp = (STDataType*)realloc(pst->a, newCapacity * sizeof(STDataType));
		if (tmp == NULL) {
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

STDataType STTop(ST* pst)
{
	assert(pst);
	assert(!STEmpty(pst));
	return pst->a[pst->top - 1];
}

bool STEmpty(ST* pst)
{
	assert(pst);
	return pst->top == 0;
}

int STSize(ST* pst)
{
	assert(pst);
	return pst->top;
}

bool isValid(char* s) {
	ST st;
	STInit(&st);
	while (*s) {
		if (*s == '(' || *s == '[' || *s == '{') {
			STPush(&st, *s);
		}
		else {
			if (STEmpty(&st)) {
				STDestroy(&st);
				return false;
			}
			char top = STTop(&st);
			STPop(&st);
			if ((top != '(' && *s == ')') ||
				(top != '{' && *s == '}') ||
				(top != '[' && *s == ']')) {
				STDestroy(&st);
				return false;
			}
		}
		s++;
	}
	bool ret = STEmpty(&st);
	STDestroy(&st);
	return ret;
}