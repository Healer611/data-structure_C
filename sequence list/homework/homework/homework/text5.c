#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//5.数组形式的整数加法
//https://leetcode.cn/problems/add-to-array-form-of-integer/
/*
解题思路：此题是用一个数的数组形式 + 一个整数， 返回和的数组形式。
模拟加法进行逐位相加， 从低位向高位相加，最后整体逆置，得到最终结果
1. 每一位的值 = 对应位值的和 + 前一位的进位
2. 每一位的值计算出来之后，需要检查是否需要进位
3. 最高位计算之后，需要考虑是否还需要向上进位
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

// 本题需要特别注意对[9,9,9,7] + 5的等特殊情况的处理
int* addToArrayForm(int* A, int ASize, int K, int* returnSize) {
    int* addRet = (int*)malloc(10001 * sizeof(int));
    //reti: 第i位的结果
    int reti = 0;
    //从低位开始相加
    int ai = ASize - 1;
    int next = 0; // 进位值
    while (ai >= 0 || K > 0)
    {

        int x1 = 0;
        //如果ai没有越界，还有未相加的位，取出一位存入x1
        if (ai >= 0)
        {
            x1 = A[ai];
            --ai;
        }

        int x2 = 0;
        //如果k大于0，获取k的第i位
        if (K > 0)
        {
            x2 = K % 10;
            K /= 10;
        }
        //第i位的结果：每一位的值 + 进位
        int ret = x1 + x2 + next;
        //如果结果大于9，需要进位
        if (ret > 9)
        {
            ret %= 10;
            next = 1;
        }
        else
        {
            next = 0;
        }
        //存入第i位的结果到数组中
        addRet[reti++] = ret;
    }
    //如果最高位有进位，需要在存入1
    if (next == 1)
    {
        addRet[reti++] = 1;
    }
    //逆置结果
    reverse(addRet, 0, reti - 1);
    *returnSize = reti;

    return addRet;
}
