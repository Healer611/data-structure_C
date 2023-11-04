#define _CRT_SECURE_NO_WARNINGS 1
#include "Seqlist.h"

void SLInit(SL* psl)//初始化
{
	assert(psl);
	psl->a = (SLDatatype*)malloc(sizeof(SLDatatype) * 4);
	if (psl->a == NULL) {
		perror("malloc fail");
		return;
	}
	psl->size = 0;
	psl->capacity = 4;//每次开辟的容量为四个
}

void SLPrint(SL* psl)//打印数据
{
	assert(psl);
	for (int i = 0; i < psl->size; i++) {
		printf("%d ", psl->a[i]);
	}
}

void SLDestroy(SL* psl)//结束使用需要销毁
{
	assert(psl);
	free(psl->a);
	psl->a = NULL;
	psl->size = 0;
	psl->capacity = 0;
}

void SLCheckCapacity(SL* psl)
{
	if (psl->size == psl->capacity) {
		//增加一倍容量
		SLDatatype* tmp = (SLDatatype*)realloc(psl->a, sizeof(SLDatatype) * psl->capacity * 2);
		if (tmp == NULL) {
			perror("realloc fail");
			return;
		}
		psl->a = tmp;
		psl->capacity *= 2;
	}
	
}

void SLPushBack(SL* psl, SLDatatype x)//尾插
{
	assert(psl);
	//psl->a[psl->size] = x;
	//psl->size++;
	//插入需要判断a是否已满，已满需要扩容
	SLCheckCapacity(psl);
	//或者写成一句
	psl->a[psl->size++] = x;//后置自增
}

void SLPushFront(SL* psl, SLDatatype x)//头插
{
	assert(psl);
	SLCheckCapacity(psl);
	int end = psl->size - 1;
	while (end >= 0) {
		psl->a[end + 1] = psl->a[end];
		end--;
	}
	psl->a[0] = x;
	psl->size++;
}
void SLPopBack(SL* psl)
{
	assert(psl);//尾删
	//暴力判断
	//assert(psl->size == 0);
	//常规判断
	if (psl->size == 0)
		return;
	psl->a[psl->size - 1] = 0;
	psl->size--;
}

void SLPopFront(SL* psl)//头删
{
	assert(psl);
	assert(psl->size > 0);
	int start = 0;
	while (start < psl->size) {
		psl->a[start] = psl->a[start + 1];
		start++;
	}
	psl->size--;
}

void SLInsert(SL* psl, int pos, SLDatatype x)//指定位置插入元素,可代替头插尾插
{
	assert(psl);
	assert(0 <= pos && pos <= psl->size);//判读插入位置是否合法
	SLCheckCapacity(psl);
	int end = psl->size - 1;
	while (end >= pos) {
		psl->a[end + 1] = psl->a[end];
		end--;
	}
	psl->size++;
	psl->a[pos] = x;
}

void SLErase(SL* psl, int pos)//删除指定位置元素，代替头删尾删
{
	assert(psl);
	assert(0 <= pos && pos <= psl->size);
	int start = pos + 1;
	while (start < psl->size) {
		psl->a[start - 1] = psl->a[start];
		start++;
	}
	psl->size--;
}

int SLFind(SL* psl, SLDatatype x)//查找指定元素位置
{
	assert(psl);
	for (int i = 0; i < psl->size; i++) {
		if (psl->a[i] == x)
			return i+1;
	}
	return -1;//找不到返回-1
}

void SLModify(SL* psl, int pos, SLDatatype x)//修改指定位置元素
{
	assert(psl);
	assert(0 <= pos && pos <= psl->size);
	psl->a[pos] = x;
}