#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//实现向右旋转k次数组
// 旋转一次[1,2,3,4,5]变为[5,1,2,3,4]

//三段逆置
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

//空间换时间，复制
void rotate_1(int* nums, int numsSize, int k)
{
	if (k > numsSize)
		k %= numsSize;
	int* tmp = (int*)malloc(sizeof(int) * numsSize);
	memcpy(tmp + k, nums, sizeof(int) * (numsSize - k));
	memcpy(tmp, nums + numsSize - k, sizeof(int) * (k));
	memcpy(nums, tmp, sizeof(int) * (numsSize));
	free(tmp);
	tmp = NULL;//可以不置空，出函数局部变量tmp就被销毁了
}
