#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//给你一个数组 nums 和一个值 val，你需要原地移除数组中所有数值等于val的元素，并返回移除后数组的新长度。
//不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并 原地 修改输入数组。
//元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。
//https://leetcode.cn/problems/remove-element/
//示例 1：
//
//输入：nums = [3, 2, 2, 3], val = 3
//输出：2
//解释：函数应该返回新的长度 2, 并且 nums 中的前两个元素均为 2。
//你不需要考虑数组中超出新长度后面的元素。例如，函数返回的新长度为 2 ，
//而 nums = [2, 2, 3, 3] 或 nums = [2, 2, 0, 0]，也会被视作正确答案。
//
//示例 2：
//
//输入：nums = [0, 1, 2, 2, 3, 0, 4, 2], val = 2
//输出：5
//解释：函数应该返回新的长度 5, 并且 nums 中的前五个元素为 0, 1, 3, 0, 4。
//注意这五个元素可为任意顺序。你不需要考虑数组中超出新长度后面的元素。
// 
int removeElement(int* nums, int numsSize, int val) {
    int src = 0;
    int dst = 0;
    while (src < numsSize) {
        if (nums[src] != val)
            nums[dst++] = nums[src++];
        else
            src++;
    }
    return dst;
}


/*
    方法1
    解题思路：
        1. 从前往后遍历nums，找到val第一次出现的位置
        2. 将val之后的所有元素整体往前搬移，即删除该val
        3. nums中有效元素个数减少一个
    循环进行上述操作，直到nums中所有值为val的元素全部删除完
    时间复杂度:O(N^2)  空间复杂度:O(1)
*/
#if 0
int removeElement(int* nums, int numsSize, int val) {
    // 
    while (1)
    {
        // 1. 在nums中找val出现的位置
        int pos = 0;
        for (; pos < numsSize; ++pos)
        {
            if (nums[pos] == val)
            {
                break;
            }
        }


        // 2. 检测是否找到
        if (pos == numsSize)
            break;


        // 3. 找到值为value的元素--将其删除
        for (int j = pos + 1; j < numsSize; ++j)
        {
            nums[j - 1] = nums[j];
        }


        numsSize--;
    }


    return numsSize;
}
#endif



#if 0
/*
    方法2：
    解题思路:
        1. 创建一个长度与nums相同的数组temp
        2. 遍历nums，将nums中所有与val不同的元素搬移到temp中
        3. 将temp中所有元素拷贝回nums中
       时间复杂度: O(N)  空间复杂度: O(N)
*/
int removeElement(int* nums, int numsSize, int val) {
    // 1. 申请numSize个元素的新空间
    int* temp = (int*)malloc(sizeof(int) * numsSize);
    if (NULL == temp)
    {
        return 0;
    }


    // 2. 将nums中非value的元素搬移到temp中---尾插到temp中
    int count = 0;
    for (int i = 0; i < numsSize; ++i)
    {
        if (nums[i] != val)
        {
            temp[count] = nums[i];
            ++count;
        }
    }


    // 3. 将temp中删除val之后的所有元素拷贝到nums中
    memcpy(nums, temp, sizeof(int) * count);
    free(temp);
    return count;
}
#endif


#if 0
/*
    方法2优化：
    解题思路:
    因为题目说了，数组中元素个数最大为100，所以不用动态申请，至二级创建100个元素数组即可
        1. 创建一个100个元素的整形数组temp
        2. 遍历nums，将nums中所有与val不同的元素搬移到temp中
        3. 将temp中所有元素拷贝回nums中
       时间复杂度: O(N)  空间复杂度: O(N)
*/
int removeElement(int* nums, int numsSize, int val) {
    // 1. 申请numSize个元素的新空间
    int temp[100];


    // 2. 将nums中非value的元素搬移到temp中---尾插到temp中
    int count = 0;
    for (int i = 0; i < numsSize; ++i)
    {
        if (nums[i] != val)
        {
            temp[count] = nums[i];
            ++count;
        }
    }


    // 3. 将temp中删除val之后的所有元素拷贝到nums中
    memcpy(nums, temp, sizeof(int) * count);
    return count;
}
#endif


#if 1
/*
    解题思路:
        1. 设置一个变量count，用来记录nums中值等于val的元素的个数
        2. 遍历nums数组，对于每个元素进行如下操作：
            a. 如果num[i]等于val，说明值为val的元素出现了一次，count++
            b. 如果nums[i]不等于元素，将nums[i]往前搬移count个位置
                因为nums[i]元素之前出现过count个值等于val的元素，已经被删除了
                因此次数需要将nums[i]往前搬移
        3. 返回删除之后新数组中有效元素个数

    时间复杂度：O(N)   空间复杂度：O(1)
 */
int removeElement(int* nums, int numsSize, int val) {
    int count = 0;
    for (int i = 0; i < numsSize; ++i)
    {
        if (nums[i] == val)
        {
            count++;
        }
        else
        {
            nums[i - count] = nums[i];
        }
    }


    return numsSize - count;
}
#endif