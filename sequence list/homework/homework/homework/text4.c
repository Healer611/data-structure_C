#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//4.旋转数组
//https://leetcode.cn/problems/rotate-array/
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
void rotate(int* nums, int numsSize, int k) {
    if (k > numsSize)
        k %= numsSize;
    reserve(nums, numsSize - k, numsSize - 1);
    reserve(nums, 0, numsSize - k - 1);
    reserve(nums, 0, numsSize - 1);
}


/*
解题思路：使用三次逆转法，让数组旋转k次
1. 先整体逆转
2. 逆转子数组[0, k - 1]
3. 逆转子数组[k, size - 1]
*/
void reverse(int* nums, int begin, int end)
{
    while (begin < end)
    {
        int tmp = nums[begin];
        nums[begin] = nums[end];
        nums[end] = tmp;

        ++begin;
        --end;
    }
}

// 三趟逆置倒的思路
void rotate(int* nums, int numsSize, int k) {
    if (k > numsSize)
    {
        k %= numsSize;
    }

    reverse(nums, 0, numsSize - 1);
    reverse(nums, 0, k - 1);
    reverse(nums, k, numsSize - 1);
}
