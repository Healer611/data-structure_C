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

void SLTPrint(SLTNode* phead);
void SLPushFront(SLTNode** pphead, SLTDataType x);
void SLPushBack(SLTNode** pphead, SLTDataType x);
void SLPopFront(SLTNode** pphead);
void SLPopBack(SLTNode** pphead);