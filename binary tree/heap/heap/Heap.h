#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int HPDataType;
typedef struct Heap
{
	HPDataType* a;
	int size;
	int capacity;
}HP;

void HeapInit(HP* php);
void HeapDestroy(HP* php);

void AdjustUp(HPDataType* a, int child);
void HeapPush(HP* php, HPDataType x);
bool HeapEmpty(HP* php);
void AdjustDown(int* a, int n, int parent);
void HeapPop(HP* php);

HPDataType HeapTop(HP* php);
int HeapSize(HP* php);