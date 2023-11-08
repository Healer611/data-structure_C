#define _CRT_SECURE_NO_WARNINGS 1
#include "sort.h"

void PrintArray(int* a, int n)
{
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}

void InsertSort(int* a, int n)
{
	for (int i = 0; i < n - 1; i++) {
		int end = i;
		int tmp = a[i + 1];
		while (end >= 0) {
			if (a[end] > tmp) {
				a[end + 1] = a[end];
				end--;
			}
			else {
				break;
			}
		}
		a[end + 1] = tmp;
	}
}

void ShellSort(int* a, int n)
{
	//1、gap >  1 预排序
	//2、gap == 1 直接插入排序
	int gap = n;
	while (gap > 1) {
		gap = gap / 3 + 1;// +1可以保证最后一次一定是1
		for (int i = 0; i < n - gap; i++) {
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0) {
				if (a[end] > tmp) {
					a[end + gap] = a[end];
					end -= gap;
				}
				else {
					break;
				}
			}
			a[end + gap] = tmp;
		}
	}
}

void BubbleSort(int* a, int n)
{
	for (int j = 0; j < n; ++j)
	{
		bool exchange = false;
		for (int i = 1; i < n - j; i++)
		{
			if (a[i - 1] > a[i])
			{
				int tmp = a[i];
				a[i] = a[i - 1];
				a[i - 1] = tmp;

				exchange = true;
			}
		}

		if (exchange == false)
		{
			break;
		}
	}
}

void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

void SelectSort(int* a, int n)
{
	int begin = 0, end = n - 1;
	while (begin < end)
	{
		int maxi = begin, mini = begin;
		for (int i = begin; i <= end; i++)
		{
			if (a[i] > a[maxi])
			{
				maxi = i;
			}

			if (a[i] < a[mini])
			{
				mini = i;
			}
		}

		Swap(&a[begin], &a[mini]);
		// 如果maxi和begin重叠，修正一下即可
		if (begin == maxi)
		{
			maxi = mini;
		}

		Swap(&a[end], &a[maxi]);

		++begin;
		--end;
	}
}

void AdjustDown(int* a, int n, int parent)
{
	int child = parent * 2 + 1;
	while (child < n) {
		if (child + 1 < n && a[child + 1] > a[child]) {
			child++;
		}
		if (a[child] > a[parent]) {
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else {
			break;
		}
	}
}
void HeapSort(int* a, int n)
{
	for (int i = (n - 1 - 1) / 2; i >= 0; --i) {
		AdjustDown(a, n, i);
	}
	int end = n - 1;
	while (end > 0) {
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		end--;
	}
}

// hoare
// [left, right]
int PartSort1(int* a, int left, int right)
{
	int keyi = left;
	while (left < right) {
		//右边找小
		while (left < right && a[right] >= a[keyi]) {
			right--;
		}
		while (left < right && a[left] <= a[keyi]) {
			left++;
		}
		Swap(&a[left], &a[right]);
	}
	Swap(&a[keyi], &a[left]);
}

// 挖坑法
// [left, right]
int PartSort2(int* a, int left, int right)
{
	int key = a[left];
	int hole = left;
	while (left < right) {
		while (left < right && a[right] >= key) {
			right--;
		}
		a[hole] = a[right];
		hole = right;
		while (left < right && a[left] <= key) {
			left++;
		}
		a[hole] = a[left];
		hole = right;
	}
	a[hole] = key;
	return hole;
}

// 前后指针法
// [left, right]
int PartSort3(int* a, int left, int right)
{
	int prev = left;
	int cur = left + 1;
	int keyi = left;
	while (cur <= right) {
		if (a[cur] < a[keyi] && ++prev != cur) {
			Swap(&a[prev], &a[cur]);
		}
		cur++;
	}
	Swap(a[prev], &a[keyi]);
	keyi = prev;
	return keyi;
}