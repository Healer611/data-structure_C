#define _CRT_SECURE_NO_WARNINGS 1
#include "LList.h"

void SLTPrint(SLTNode* phead)
{
	SLTNode* cur = phead;
	while (cur != NULL) {
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

SLTNode* BuyLTNode(SLTDataType x)//为新元素开辟空间
{
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	if (newnode == NULL) {
		perror("malloc fall");
		return;
	}
	newnode->data = x;
	newnode->next = NULL;
	return newnode;
}

void SLPushFront(SLTNode** pphead, SLTDataType x)//头插
{
	SLTNode* newnode = BuyLTNode(x);//newnode是局部变量
	newnode->next = *pphead;//头插后首元素next指向原有的首元素
	*pphead = newnode;//改变pphead
}

void SLPushBack(SLTNode** pphead, SLTDataType x)
{
	SLTNode* newnode = BuyLTNode(x);
	//两种情况
	//空链表  非空链表
	if (*pphead == NULL)//链表为空改变结构体指针
		*pphead = newnode;

	else {//不为空，则改变结构体的节点
		SLTNode* tail = *pphead;
		while (tail->next != NULL)
			tail = tail->next;
		
		tail->next = newnode;
	}		
}

void SLPopFront(SLTNode** pphead)
{
	assert(*pphead);
	//SLTNode* del = *pphead;
	*pphead = (*pphead)->next;
	//free(del);
}

void SLPopBack(SLTNode** pphead)
{
	//没有节点（空链表）
	assert(*pphead);

	//只有一个节点
	if ((*pphead)->next == NULL) {
		free(*pphead);
		*pphead = NULL;
	}
	else {
		//第一种
		//SLTNode* prev = NULL;
		//SLTNode* tail = *pphead;
		//while (tail->next) {
		//	prev = tail;
		//	tail = tail->next;
		//}
		//free(tail);
		//prev->next = NULL;

		//第二种不新增变量
		//改变结构体的节点
		SLTNode* tail = *pphead;
		while (tail->next->next) {
			tail = tail->next;
		}
		free(tail->next);//将指向的最后一个节点释放
		tail->next = NULL;
	}
}

