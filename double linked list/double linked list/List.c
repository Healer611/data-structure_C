#define _CRT_SECURE_NO_WARNINGS 1
#include "List.h"

//�����½ڵ�
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

//��ʼ������
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

//��ӡ����
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

//ͷ��
void LTPushFront(LTNode* phead, LTDataType x)
{
	LTInsert(phead->next, x);
}

//void LTPushFront(LTNode* phead, LTDataType x)
//{
//	assert(phead);
//	LTNode* newnode = BuyLTNode(x);
//	LTNode* first = phead->next;
//	//������������˳����Եߵ�����Ϊʹ��ָ��first������ԭ�������һ��Ԫ�صĵ�ַ
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

//β��
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

//��������Ƿ�Ϊ��
bool LTEmpty(LTNode* phead)
{
	assert(phead);
	return phead->next == phead;
}

//ͷɾ
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


//βɾ
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




//����ֵΪx�Ľڵ㣬���ؽڵ��ַ
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

//��ָ���ڵ�ǰ���룬��LTFind����ʹ��
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

// ɾ��ָ���ڵ�
void LTErase(LTNode* pos)//�����ж�phead�Ƿ�����ڱ�λ
{
	assert(pos);
	LTNode* posPrev = pos->prev;
	LTNode* posNext = pos->next;
	
	posPrev->next = posNext;
	posNext->prev = posPrev;
	free(pos);
}

//��������
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
