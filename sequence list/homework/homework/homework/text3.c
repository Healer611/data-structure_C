#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//合并两个有序数组
//https://leetcode.cn/problems/merge-sorted-array/
//给你两个按 非递减顺序 排列的整数数组 nums1 和 nums2，
//另有两个整数 m 和 n ，分别表示 nums1 和 nums2 中的元素数目。
//
//请你 合并 nums2 到 nums1 中，使合并后的数组同样按 非递减顺序 排列。
//
//注意：最终，合并后数组不应由函数返回，而是存储在数组 nums1 中。
//为了应对这种情况，nums1 的初始长度为 m + n，其中前 m 个元素表示应合并的元素，
//后 n 个元素为 0 ，应忽略。nums2 的长度为 n 。


//两种解法
//最优解：从后向前比大小进行尾插，
// 粗暴解法：qsort排序


//最优解：从后向前比大小进行尾插
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int end1 = m - 1;//数组1已有最后一个元素的下标
    int end2 = n - 1;//数组2最后一个元素的下标
    int i = m + n - 1;//数组1合并后最后一个元素的下标
    while (end1 >= 0 && end2 >= 0) {//从末尾开始比较，某一个数组比较完第一个元素后停止比较
        if (nums2[end2] > nums1[end1])
            nums1[i--] = nums2[end2--];
        //如果数组2指向的当前元素大于数组1当前指向的原有元素，则将其插入数组1最后
        //然后i和end的位置前移一位，便于比较下一对元素大小
        else {
            nums1[i--] = nums1[end1--];
            //如果数组2小于当前元素，则数组1当前元素移动到i的位置
        }
    }
    while (end2 >= 0)
        //如果从数组1某个元素开始一直比数组2元素大，
        //数组1将大于数组2的元素从后向前依次填入下标i的位置，
        // 过程中数组1的下标i一直自减，从i指向的位置到数组1开头用于插入数组2剩余元素
        // 数组1的下标end1不断自减中已为负数了，而数组2可能在某处小于数组1某个元素处停下，
        //利用这个条件进行循环，将那些小于数组1的元素在下标为i处从后向前开始插入
        nums1[i--] = nums2[end2--];
}


//粗暴解法：qsort排序
//int cmp(int* a, int* b) {
//    return *a - *b;
//}
//
//void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
//    for (int i = 0; i != n; ++i) {
//        nums1[m + i] = nums2[i];
//    }
//    qsort(nums1, nums1Size, sizeof(int), cmp);
//}

