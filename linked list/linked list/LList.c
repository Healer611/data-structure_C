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
	assert(pphead);  // ����Ϊ�գ�ppheadҲ��Ϊ�գ���Ϊ����ͷָ��plist�ĵ�ַ
	//assert(*pphead); // ���ܶ��ԣ�����Ϊ�գ�Ҳ��Ҫ�ܲ���
	SLTNode* newnode = BuyLTNode(x);//newnode�Ǿֲ�����
	newnode->next = *pphead;//ͷ����׽ڵ�nextָ��ԭ�е��׽ڵ�
	*pphead = newnode;//�������ͷָ�� *pphead ָ���²���Ľڵ�
}

void SLPushBack(SLTNode** pphead, SLTDataType x)
{
	assert(pphead); // ����Ϊ�գ�ppheadҲ��Ϊ�գ���Ϊ����ͷָ��plist�ĵ�ַ
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
	assert(pphead); // ����Ϊ�գ�ppheadҲ��Ϊ�գ���Ϊ����ͷָ��plist�ĵ�ַ
	assert(*pphead); // ����Ϊ�գ�����ͷɾ������Ȼ�㻹����������ļ�飩
	SLTNode* del = *pphead;//ָ��del�����ͷŽڵ�ռ�
	*pphead = (*pphead)->next;
	free(del);
}

void SLPopBack(SLTNode** pphead)
{
	assert(pphead); // ����Ϊ�գ�ppheadҲ��Ϊ�գ���Ϊ����ͷָ��plist�ĵ�ַ
	assert(*pphead); // ����Ϊ�գ�����ͷɾ������Ȼ�㻹����������ļ�飩

	//ֻ��һ���ڵ�
	if ((*pphead)->next == NULL) {
		free(*pphead);
		*pphead = NULL;//�޸�ͷ�ڵ�Ϊ��
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


SLTNode* STFind(SLTNode* phead, SLTDataType x)//�ҵ����������ַ
{
	SLTNode* cur = phead;
	while (cur) {
		if (cur->data == x)
			return cur;
		
		cur = cur->next;
	}
	return NULL;
}

// ��pos֮ǰ����
void SLInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x)
{
	assert(pphead);
	assert(pos);
	if (*pphead == pos){//��ͷ�ڵ�ǰ�������ͷ��
		SLPushFront(pphead, x);
	}
	else {
		SLTNode* prev = *pphead;//�����ҵ�posǰ��λ��

		while (prev->next != pos){
			prev = prev->next;
		}

		SLTNode* newnode = BuyLTNode(x);
		prev->next = newnode;//posǰһ��λ��nextָ���¿��ٽڵ�
		newnode->next = pos;//�½ڵ�nextָ��pos
	}
}

// ��pos֮�����
void SLInsertAfter(SLTNode* pos, SLTDataType x)
{
	assert(pos);
	SLTNode* newnode = BuyLTNode(x);
	//�������в��ܵ���˳�򣬷����޷������½ڵ����ڵ�
	newnode->next = pos->next;
	pos->next = newnode;
}

void SLErase(SLTNode** pphead, SLTNode* pos)// ɾ��posλ�õ�ֵ
{
	assert(pphead);
	assert(*pphead);//����Ϊ������ɾ��
	if (pos = *pphead){
		SLPopFront(pphead);
	}
	else {
		SLTNode* prev = *pphead;
		while (prev->next != pos) {//�ҵ�posǰһ���ڵ�
			prev = prev -> next;
		}
		prev->next = pos->next;//��posǰһ���ڵ��nextָ��pos��һ���ڵ�
		free(pos);//�ͷ�pos�ռ�
	}
}

void SLEraseAfter(SLTNode* pos)
{
	assert(pos);
	assert(pos->next);//����Ϊ������ɾ��
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