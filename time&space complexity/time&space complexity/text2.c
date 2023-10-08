#define _CRT_SECURE_NO_WARNINGS 1

//ײɫ����
//�������� sockets ��¼��һ��������е���ɫ�ֲ���������� sockets[i] ��ʾ�����ӵ���ɫ��š�
//����г���һ��ײɫ��������ӣ�ÿ����ɫ�����Ӿ�����ֻ��
//�����һ��������ʱ�临�Ӷ� O(n)���ռ临�Ӷ�O(1) ���ҵ���˫ײɫ�������ӵ�������ɫ��š�
//
//ʾ�� 1��
//���룺sockets = [4, 5, 2, 4, 6, 6]
//�����[2, 5] ��[5, 2]
//
//ʾ�� 2��
//���룺sockets = [1, 2, 4, 1, 4, 3, 12, 3]
//�����[2, 12] ��[12, 2]
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