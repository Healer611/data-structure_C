#define _CRT_SECURE_NO_WARNINGS 1
#include "Seqlist.h"

void SLInit(SL* psl)//��ʼ��
{
	assert(psl);
	psl->a = (SLDatatype*)malloc(sizeof(SLDatatype) * 4);
	if (psl->a == NULL) {
		perror("malloc fail");
		return;
	}
	psl->size = 0;
	psl->capacity = 4;//ÿ�ο��ٵ�����Ϊ�ĸ�
}

void SLPrint(SL* psl)//��ӡ����
{
	assert(psl);
	for (int i = 0; i < psl->size; i++) {
		printf("%d ", psl->a[i]);
	}
}

void SLDestroy(SL* psl)//����ʹ����Ҫ����
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
		//����һ������
		SLDatatype* tmp = (SLDatatype*)realloc(psl->a, sizeof(SLDatatype) * psl->capacity * 2);
		if (tmp == NULL) {
			perror("realloc fail");
			return;
		}
		psl->a = tmp;
		psl->capacity *= 2;
	}
	
}

void SLPushBack(SL* psl, SLDatatype x)//β��
{
	assert(psl);
	//psl->a[psl->size] = x;
	//psl->size++;
	//������Ҫ�ж�a�Ƿ�������������Ҫ����
	SLCheckCapacity(psl);
	//����д��һ��
	psl->a[psl->size++] = x;//��������
}

void SLPushFront(SL* psl, SLDatatype x)//ͷ��
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
	assert(psl);//βɾ
	//�����ж�
	//assert(psl->size == 0);
	//�����ж�
	if (psl->size == 0)
		return;
	psl->a[psl->size - 1] = 0;
	psl->size--;
}

void SLPopFront(SL* psl)//ͷɾ
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

void SLInsert(SL* psl, int pos, SLDatatype x)//ָ��λ�ò���Ԫ��,�ɴ���ͷ��β��
{
	assert(psl);
	assert(0 <= pos && pos <= psl->size);//�ж�����λ���Ƿ�Ϸ�
	SLCheckCapacity(psl);
	int end = psl->size - 1;
	while (end >= pos) {
		psl->a[end + 1] = psl->a[end];
		end--;
	}
	psl->size++;
	psl->a[pos] = x;
}

void SLErase(SL* psl, int pos)//ɾ��ָ��λ��Ԫ�أ�����ͷɾβɾ
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

int SLFind(SL* psl, SLDatatype x)//����ָ��Ԫ��λ��
{
	assert(psl);
	for (int i = 0; i < psl->size; i++) {
		if (psl->a[i] == x)
			return i+1;
	}
	return -1;//�Ҳ�������-1
}

void SLModify(SL* psl, int pos, SLDatatype x)//�޸�ָ��λ��Ԫ��
{
	assert(psl);
	assert(0 <= pos && pos <= psl->size);
	psl->a[pos] = x;
}