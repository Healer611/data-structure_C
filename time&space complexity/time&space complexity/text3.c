#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//ʵ��������תk������
// ��תһ��[1,2,3,4,5]��Ϊ[5,1,2,3,4]

//��������
void reserve(int* a, int left, int right)
{
	while (left < right) {
		int tmp = a[left];
		a[left] = a[right];
		a[right] = tmp;
		left++;
		right--;
	}
}

void rotate(int* nums, int numsSize, int k)
{
	if (k > numsSize)
		k %= numsSize;
	reserve(nums, numsSize - k, numsSize);
	reservr(nums, 0, numsSize - k - 1);
}

//�ռ任ʱ�䣬����
void rotate_1(int* nums, int numsSize, int k)
{
	if (k > numsSize)
		k %= numsSize;
	int* tmp = (int*)malloc(sizeof(int) * numsSize);
	memcpy(tmp + k, nums, sizeof(int) * (numsSize - k));
	memcpy(tmp, nums + numsSize - k, sizeof(int) * (k));
	memcpy(nums, tmp, sizeof(int) * (numsSize));
	free(tmp);
	tmp = NULL;//���Բ��ÿգ��������ֲ�����tmp�ͱ�������
}
