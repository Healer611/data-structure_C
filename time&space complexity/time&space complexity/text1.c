#define _CRT_SECURE_NO_WARNINGS 1

//消失的数字

//数组nums包含从0到n的所有整数，但其中缺了一个。请编写代码找出那个缺失的整数。你有办法在O(n)时间内完成吗？
//示例 1：
//
//输入：[3, 0, 1]
//输出：2
//
//
//示例 2：
//
//输入：[9, 6, 4, 2, 3, 5, 7, 0, 1]
//输出：8
//异或
int missingNumber(int* nums, int numsSize) {
    int x = 0;
    for (int i = 0; i < numsSize; i++)
        x ^= nums[i];
    for (int i = 0; i < numsSize + 1; i++)
        x ^= i;
    return x;
}
//等差公式
//int missingNumber(int* nums, int numsSize) {
//    int x = (1 + numsSize) * numsSize / 2;
//    for (int i = 0; i < numsSize; i++)
//        x -= nums[i];
//    return x;
//}
