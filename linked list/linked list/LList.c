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
	assert(pphead);  // 链表为空，pphead也不为空，因为他是头指针plist的地址
	//assert(*pphead); // 不能断言，链表为空，也需要能插入
	SLTNode* newnode = BuyLTNode(x);//newnode是局部变量
	newnode->next = *pphead;//头插后首节点next指向原有的首节点
	*pphead = newnode;//将链表的头指针 *pphead 指向新插入的节点
}

void SLPushBack(SLTNode** pphead, SLTDataType x)
{
	assert(pphead); // 链表为空，pphead也不为空，因为他是头指针plist的地址
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
	assert(pphead); // 链表为空，pphead也不为空，因为他是头指针plist的地址
	assert(*pphead); // 链表为空，不能头删。（当然你还可以用温柔的检查）
	SLTNode* del = *pphead;//指针del用于释放节点空间
	*pphead = (*pphead)->next;
	free(del);
}

void SLPopBack(SLTNode** pphead)
{
	assert(pphead); // 链表为空，pphead也不为空，因为他是头指针plist的地址
	assert(*pphead); // 链表为空，不能头删。（当然你还可以用温柔的检查）

	//只有一个节点
	if ((*pphead)->next == NULL) {
		free(*pphead);
		*pphead = NULL;//修改头节点为空
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


SLTNode* STFind(SLTNode* phead, SLTDataType x)//找到返回链表地址
{
	SLTNode* cur = phead;
	while (cur) {
		if (cur->data == x)
			return cur;
		
		cur = cur->next;
	}
	return NULL;
}

// 在pos之前插入
void SLInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x)
{
	assert(pphead);
	assert(pos);
	if (*pphead == pos){//在头节点前插入等于头插
		SLPushFront(pphead, x);
	}
	else {
		SLTNode* prev = *pphead;//用于找到pos前的位置

		while (prev->next != pos){
			prev = prev->next;
		}

		SLTNode* newnode = BuyLTNode(x);
		prev->next = newnode;//pos前一个位置next指向新开辟节点
		newnode->next = pos;//新节点next指向pos
	}
}

// 在pos之后插入
void SLInsertAfter(SLTNode* pos, SLTDataType x)
{
	assert(pos);
	SLTNode* newnode = BuyLTNode(x);
	//下面两行不能调换顺序，否则无法链接新节点后项节点
	newnode->next = pos->next;
	pos->next = newnode;
}

void SLErase(SLTNode** pphead, SLTNode* pos)// 删除pos位置的值
{
	assert(pphead);
	assert(*pphead);//链表为空则不能删除
	if (pos = *pphead){
		SLPopFront(pphead);
	}
	else {
		SLTNode* prev = *pphead;
		while (prev->next != pos) {//找到pos前一个节点
			prev = prev -> next;
		}
		prev->next = pos->next;//将pos前一个节点的next指向pos后一个节点
		free(pos);//释放pos空间
	}
}

void SLEraseAfter(SLTNode* pos)
{
	assert(pos);
	assert(pos->next);//后项为空则不能删除
	SLTNode* next = pos->next;
	pos->next = next->next;
	free(next);
}

void SListDestroy(SLTNode* pphead)
{
	SLTNode* cur = pphead;
	SLTNode* tmp = NULL;
	while (cur != NULL) {
		tmp = cur;
		cur = cur->next;
		free(tmp);
	}
}