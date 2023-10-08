#define _CRT_SECURE_NO_WARNINGS 1

//撞色搭配
//整数数组 sockets 记录了一个袜子礼盒的颜色分布情况，其中 sockets[i] 表示该袜子的颜色编号。
//礼盒中除了一款撞色搭配的袜子，每种颜色的袜子均有两只。
//请设计一个程序，在时间复杂度 O(n)，空间复杂度O(1) 内找到这双撞色搭配袜子的两个颜色编号。
//
//示例 1：
//输入：sockets = [4, 5, 2, 4, 6, 6]
//输出：[2, 5] 或[5, 2]
//
//示例 2：
//输入：sockets = [1, 2, 4, 1, 4, 3, 12, 3]
//输出：[2, 12] 或[12, 2]
#include <stdio.h>
int* sockCollocation(int* sockets, int socketsSize, int* returnSize) {
    int* result = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;
    int ret = 0;
    for (int i = 0; i < socketsSize; i++)
        ret ^= sockets[i];
    int div = 1;
    while ((div & ret) == 0)
        div <<= 1;
    int a = 0, b = 0;
    for (int i = 0; i < socketsSize; i++) {
        if (div & sockets[i])
            a ^= sockets[i];
        else
            b ^= sockets[i];
    }
    result[0] = a;
    result[1] = b;
    return result;
}