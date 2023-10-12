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

SLTNode* BuyLTNode(SLTDataType x)//Ϊ��Ԫ�ؿ��ٿռ�
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

void SLPushFront(SLTNode** pphead, SLTDataType x)//ͷ��
{
	SLTNode* newnode = BuyLTNode(x);//newnode�Ǿֲ�����
	newnode->next = *pphead;//ͷ�����Ԫ��nextָ��ԭ�е���Ԫ��
	*pphead = newnode;//�ı�pphead
}

void SLPushBack(SLTNode** pphead, SLTDataType x)
{
	SLTNode* newnode = BuyLTNode(x);
	//�������
	//������  �ǿ�����
	if (*pphead == NULL)//����Ϊ�ոı�ṹ��ָ��
		*pphead = newnode;

	else {//��Ϊ�գ���ı�ṹ��Ľڵ�
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
	//û�нڵ㣨������
	assert(*pphead);

	//ֻ��һ���ڵ�
	if ((*pphead)->next == NULL) {
		free(*pphead);
		*pphead = NULL;
	}
	else {
		//��һ��
		//SLTNode* prev = NULL;
		//SLTNode* tail = *pphead;
		//while (tail->next) {
		//	prev = tail;
		//	tail = tail->next;
		//}
		//free(tail);
		//prev->next = NULL;

		//�ڶ��ֲ���������
		//�ı�ṹ��Ľڵ�
		SLTNode* tail = *pphead;
		while (tail->next->next) {
			tail = tail->next;
		}
		free(tail->next);//��ָ������һ���ڵ��ͷ�
		tail->next = NULL;
	}
}

