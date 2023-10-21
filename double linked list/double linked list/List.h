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

//初始化链表
LTNode* LTInit();
//void LTInit(LTNode** phead);

//打印链表
void LTPrint(LTNode* phead);

//头插&尾插
void LTPushFront(LTNode* phead, LTDataType x);
void LTPushBack(LTNode* phead, LTDataType x);

//头删&尾删
void LTPopFront(LTNode* phead);
void LTPopBack(LTNode* phead);

//查找值为x的节点，返回节点地址
LTNode* LTFind(LTNode* phead, LTDataType x);

//在指定节点前插入
void LTInsert(LTNode* pos, LTDataType x); 

//删除指定节点
void LTErase(LTNode* pos);

//销毁链表
void LTDestroy(LTNode** phead);