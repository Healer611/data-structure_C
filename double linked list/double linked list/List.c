#define _CRT_SECURE_NO_WARNINGS 1
#include "List.h"

//创建新节点
LTNode* BuyLTNode(LTDataType x)
{
	LTNode* newnode = (LTNode*)malloc(sizeof(LTNode));
	if (newnode == NULL) {
		perror("malloc fail");
		return NULL;
	}
	newnode->data = x;
	newnode->prev = NULL;
	newnode->next = NULL;
	return newnode;
}

//初始化链表
LTNode* LTInit()
{
	LTNode* phead = BuyLTNode(-1);
	phead->prev = phead;
	phead->next = phead;
	return phead;
}
//void LTInit(LTNode** phead)
//{
//	assert(phead);
//	* phead = BuyLTNode(-1);
//	(*phead)->prev = *phead;
//	(*phead)->next = *phead;
//	(*phead)->data = 0;
//}

//打印链表
void LTPrint(LTNode* phead)
{
	assert(phead);
	printf("guard<==>");
	LTNode* cur = phead->next;
	while (cur != phead) {
		if(cur!=phead->prev)
			printf("%d<==>", cur->data);
		else
			printf("%d\n", cur->data);
		cur = cur->next;
	}
}

//头插
void LTPushFront(LTNode* phead, LTDataType x)
{
	LTInsert(phead->next, x);
}

//void LTPushFront(LTNode* phead, LTDataType x)
//{
//	assert(phead);
//	LTNode* newnode = BuyLTNode(x);
//	LTNode* first = phead->next;
//	//下面两块代码的顺序可以颠倒，因为使用指针first储存了原来链表第一个元素的地址
//	newnode->next = first;
//	first->prev = newnode;
//
//	phead->next = newnode;
//	newnode->prev = phead;
//}

//void LTPushFront(LTNode* phead, LTDataType x)
//{
//	assert(phead);
//	LTNode* newnode = BuyLTNode(x);
//
//	newnode->next = phead->next;
//	phead->next->prev = newnode;
//
//	newnode->prev = phead;
//	phead->next = newnode;
//}

//尾插
void LTPushBack(LTNode* phead, LTDataType x)
{
	assert(phead);

	LTInsert(phead, x);
}
//void LTPushBack(LTNode* phead, LTDataType x)
//{
//	assert(phead);
//	LTNode* newnode = BuyLTNode(x);
//	LTNode* tail = phead->prev;
//	
//	newnode->next = phead;
//	phead->prev = newnode;
//
//	tail->next = newnode;
//	newnode->prev = tail;
//}

//监测链表是否为空
bool LTEmpty(LTNode* phead)
{
	assert(phead);
	return phead->next == phead;
}

//头删
void LTPopFront(LTNode* phead)
{
	assert(phead);
	assert(!LTEmpty(phead));

	LTErase(phead->next);
}

//void LTPopFront(LTNode* phead)
//{
//	assert(phead);
//	assert(!LTEmpty(phead));
//
//	LTNode* first = phead->next;
//	LTNode* second = first->next;
//
//	second->prev = phead;
//	phead->next = second;
//	free(first);
//}


//尾删
void LTPopBack(LTNode* phead)
{
	assert(phead);
	assert(!LTEmpty(phead));

	LTErase(phead->prev);
}

//void LTPopBack(LTNode* phead)
//{
//	assert(phead);
//	assert(!LTEmpty(phead));
//	//LTErase(phead->prev);
//
//	LTNode* tail = phead->prev;
//	LTNode* tailPrev = tail->prev;
//
//	free(tail);
//	tailPrev->next = phead;
//	phead->prev = tailPrev;
//
//}




//查找值为x的节点，返回节点地址
LTNode* LTFind(LTNode* phead, LTDataType x)
{
	assert(phead);
	LTNode* cur = phead->next;
	while (cur != phead) {
		if (cur->data == x)
			return cur;

		cur = cur->next;
	}
	return NULL;
}

//在指定节点前插入，与LTFind搭配使用
void LTInsert(LTNode* pos, LTDataType x)
{
	assert(pos);

	LTNode* prev = pos->prev;
	LTNode* newnode = BuyLTNode(x);

	prev->next = newnode;
	newnode->prev = prev;

	newnode->next = pos;
	pos->prev = newnode;
}

// 删除指定节点
void LTErase(LTNode* pos)//可以判断phead是否等于哨兵位
{
	assert(pos);
	LTNode* posPrev = pos->prev;
	LTNode* posNext = pos->next;
	
	posPrev->next = posNext;
	posNext->prev = posPrev;
	free(pos);
}

//销毁链表
void LTDestroy(LTNode** phead)
{
	assert(phead);
	assert(*phead);
	LTNode* cur = (*phead)->next;
	while (cur != *phead) {
		LTNode* next = cur->next;
		free(cur);
		cur = next;
	}
	free(*phead);
	*phead = NULL;
}
