#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLTDataType;
typedef struct SListNode
{
	SLTDataType data;
	struct SListNode* next;
}SLTNode;

//��ӡ����
void SLTPrint(SLTNode* phead);

//ͷ��β��
void SLPushFront(SLTNode** pphead, SLTDataType x);
void SLPushBack(SLTNode** pphead, SLTDataType x);

//ͷɾβɾ
void SLPopFront(SLTNode** pphead);
void SLPopBack(SLTNode** pphead);

// ���������
SLTNode * STFind(SLTNode * phead, SLTDataType x);

// ��pos֮ǰ����
void SLInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x);
void SLInsertAfter(SLTNode* pos, SLTDataType x);

// ɾ��posλ�õ�ֵ
void SLErase(SLTNode** pphead, SLTNode* pos);

// ɾ��posλ�ú����ֵ
void SLEraseAfter(SLTNode* pos);

// �����������
void SListDestroy(SLTNode* plist);