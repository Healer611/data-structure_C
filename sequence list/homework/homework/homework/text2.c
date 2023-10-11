#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
// 删除排序数组中的重复项,返回值为数组元素个数
// https://leetcode.cn/problems/remove-duplicates-from-sorted-array/description/
int removeDuplicates(int* nums, int numsSize) {
    int src = 1;
    int dst = 0;
    while (src < numsSize) {
        if (nums[src] == nums[dst])
            src++;
        else
            nums[++dst] = nums[src++];
    }
    return dst + 1;
}