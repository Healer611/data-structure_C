#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

//232. 用栈实现队列
//https://leetcode.cn/problems/implement-queue-using-stacks/description/

typedef int STDataType;
typedef struct Stack
{
	STDataType* a;
	int top;
	int capacity;
}ST;

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

bool STEmpty(ST* pst)
{
	assert(pst);
	return pst->top == 0;
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
	assert(!STEmpty(pst));//栈为空则不能访问
	return pst->a[pst->top - 1];
}

int STSize(ST* pst)
{
	assert(pst);
	return pst->top;
}

typedef struct {
	ST pushst;
	ST popst;
} MyQueue;

MyQueue* myQueueCreate() {
	MyQueue* obj = (MyQueue*)malloc(sizeof(MyQueue));
	if (obj == NULL) {
		perror("malloc fail");
		return 0;
	}
	STInit(&obj->pushst);
	STInit(&obj->popst);
	return obj;
}

void myQueuePush(MyQueue* obj, int x) {
	STPush(&obj->pushst, x);
}

int myQueuePop(MyQueue* obj) {
	int front = myQueuePeek(obj);
	STPop(&obj->popst);
	return front;
}

int myQueuePeek(MyQueue* obj) {
	if (STEmpty(&obj->popst)) {
		while (!STEmpty(&obj->pushst)) {
			STPush(&obj->popst, STTop(&obj->pushst));
			STPop(&obj->pushst);
		}
	}
	return STTop(&obj->popst);
}

bool myQueueEmpty(MyQueue* obj) {
	return STEmpty(&obj->pushst) && STEmpty(&obj->popst);
}

void myQueueFree(MyQueue* obj) {
	STDestroy(&obj->pushst);
	STDestroy(&obj->popst);
	free(obj);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 
 * int param_2 = myQueuePop(obj);

 * int param_3 = myQueuePeek(obj);

 * bool param_4 = myQueueEmpty(obj);

 * myQueueFree(obj);
*/