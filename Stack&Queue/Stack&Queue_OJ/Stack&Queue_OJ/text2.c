#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
//225. 用队列实现栈
//https://leetcode.cn/problems/implement-stack-using-queues/

typedef int QDataType;
typedef struct QueueNode
{
    struct QueueNode* next;
    QDataType data;
}QNode;

typedef struct Queue
{
    QNode* phead;
    QNode* ptail;
    int size;
}Queue;

void QueueInit(Queue* pq)
{
    assert(pq);
    pq->phead = NULL;
    pq->ptail = NULL;
    pq->size = 0;
}
void QueueDestroy(Queue* pq)
{
    assert(pq);
    QNode* cur = pq->phead;
    while (cur) {
        QNode* next = cur->next;
        free(cur);
        cur = next;
    }
    pq->phead = pq->ptail = NULL;
    pq->size = 0;
}
void QueuePush(Queue* pq, QDataType x)
{
    assert(pq);
    QNode* newnode = (QNode*)malloc(sizeof(QNode));
    if (newnode == NULL) {
        perror("mallloc fail\n");
        return;
    }
    newnode->data = x;
    newnode->next = NULL;
    if (pq->ptail == NULL) {
        assert(pq->phead == NULL);
        pq->phead = pq->ptail = newnode;
    }
    else {
        pq->ptail->next = newnode;
        pq->ptail = newnode;
    }
    pq->size++;
}
bool QueueEmpty(Queue* pq)
{
    assert(pq);
    return pq->size == 0;
}
void QueuePop(Queue* pq)
{
    assert(pq);
    assert(!QueueEmpty(pq));
    if (pq->phead->next == NULL) {
        free(pq->phead);
        pq->phead = pq->ptail = NULL;
    }
    else {
        QNode* next = pq->phead->next;
        free(pq->phead);
        pq->phead = next;
    }
    pq->size--;
}
QDataType QueueFront(Queue* pq)
{
    assert(pq);
    assert(!QueueEmpty(pq));
    return pq->phead->data;
}
QDataType QueueBack(Queue* pq)
{
    assert(pq);
    assert(!QueueEmpty(pq));
    return pq->ptail->data;
}
int QueueSize(Queue* pq)
{
    assert(pq);
    return pq->size;
}

typedef struct {
    Queue q1;
    Queue q2;
} MyStack;


MyStack* myStackCreate() {
    MyStack* obj = (MyStack*)malloc(sizeof(MyStack));
    if (obj == NULL) {
        perror("malloc fail");
        return NULL;
    }
    QueueInit(&obj->q1);
    QueueInit(&obj->q2);
    return obj;
}

void myStackPush(MyStack* obj, int x) {
    if (!QueueEmpty(&obj->q1)) {
        QueuePush(&obj->q1, x);
    }
    else {
        QueuePush(&obj->q2, x);
    }
}

int myStackPop(MyStack* obj) {
    Queue* pEmptyQ = &obj->q1;
    Queue* pNonEmptyQ = &obj->q2;
    if (!QueueEmpty(&obj->q1)) {
        pEmptyQ = &obj->q2;
        pNonEmptyQ = &obj->q1;
    }
    while (QueueSize(pNonEmptyQ) > 1) {
        QueuePush(pEmptyQ, QueueFront(pNonEmptyQ));
        QueuePop(pNonEmptyQ);
    }
    int top = QueueFront(pNonEmptyQ);
    QueuePop(pNonEmptyQ);
    return top;
}

int myStackTop(MyStack* obj) {
    if (!QueueEmpty(&obj->q1)) {
        return QueueBack(&obj->q1);
    }
    else {
        return QueueBack(&obj->q2);
    }
}

bool myStackEmpty(MyStack* obj) {
    return QueueEmpty(&obj->q1) &&
        QueueEmpty(&obj->q2);
}

void myStackFree(MyStack* obj) {
    QueueDestroy(&obj->q1);
    QueueDestroy(&obj->q2);
    free(obj);
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);

 * int param_2 = myStackPop(obj);

 * int param_3 = myStackTop(obj);

 * bool param_4 = myStackEmpty(obj);

 * myStackFree(obj);
*/