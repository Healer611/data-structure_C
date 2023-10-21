#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int LTDataType;
typedef struct ListNode
{
	struct ListNode* next;
	struct ListNode* prev;
	LTDataType data;
}LTNode;

//��ʼ������
LTNode* LTInit();
//void LTInit(LTNode** phead);

//��ӡ����
void LTPrint(LTNode* phead);

//ͷ��&β��
void LTPushFront(LTNode* phead, LTDataType x);
void LTPushBack(LTNode* phead, LTDataType x);

//ͷɾ&βɾ
void LTPopFront(LTNode* phead);
void LTPopBack(LTNode* phead);

//����ֵΪx�Ľڵ㣬���ؽڵ��ַ
LTNode* LTFind(LTNode* phead, LTDataType x);

//��ָ���ڵ�ǰ����
void LTInsert(LTNode* pos, LTDataType x); 

//ɾ��ָ���ڵ�
void LTErase(LTNode* pos);

//��������
void LTDestroy(LTNode** phead);