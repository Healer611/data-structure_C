#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
//void InsertSort(int* a, int n)
//{
//	for (int i = 0; i < n - 1; i++) {
//		int end = i;
//		int tmp = a[i + 1];
//		while (end >= 0) {
//			if (a[end] > tmp) {
//				a[end + 1] = a[end];
//				end--;
//			}
//			else {
//				break;
//			}
//		}
//		a[end + 1] = tmp;
//	}
//}
//void ShellSort(int* a,int n)
//{
//	int gap = n;
//	while (gap > 1) {
//		gap = gap / 3 + 1;
//		for (int i = 0; i < n - gap; i++) {
//			int end = i;
//			int tmp = a[end + gap];
//			while (end >= 0) {
//				if (a[end] > tmp) {
//					a[end + gap] = a[end];
//					end -= gap;
//				}
//				else {
//					break;
//				}
//			}
//			a[end + gap] = tmp;
//		}
//	}
//}
//void BubbleSort(int* a, int n) {
//	for (int j = 0; j < n; j++) {
//		bool exchange = false;
//		for (int i = 1; i < n - j; i++) {
//			if (a[i - 1] > a[i]) {
//				int tmp = a[i];
//				a[i] = a[i - 1];
//				a[i - 1] = tmp;
//				exchange = true;
//			}
//		}
//		if (exchange == false) {
//			break;
//		}
//	}
//}
//
//void Swap(int* a, int* b)
//{
//	int tmp = *a;
//	*a = *b;
//	*b = tmp;
//}
//void SelectSort(int* a, int n)
//{
//	int begin = 0, end = n - 1;
//	while (begin < end) {
//		int max = begin, min = begin;
//		for (int i = begin; i < end; i++) {
//			if (a[i] > a[max]) {
//				max = i;
//			}
//			if (a[i] < a[min]) {
//				min = i;
//			}
//		}
//		Swap(&a[begin], &a[min]);
//		if(begin==max){
//			max = min;
//		}
//		Swap(&a[end], &a[max]);
//		begin++;
//		end--;
//	}
//}