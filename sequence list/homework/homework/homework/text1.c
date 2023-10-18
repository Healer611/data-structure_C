#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//����һ������ nums ��һ��ֵ val������Ҫԭ���Ƴ�������������ֵ����val��Ԫ�أ��������Ƴ���������³��ȡ�
//��Ҫʹ�ö��������ռ䣬������ʹ�� O(1) ����ռ䲢 ԭ�� �޸��������顣
//Ԫ�ص�˳����Ըı䡣�㲻��Ҫ���������г����³��Ⱥ����Ԫ�ء�
//https://leetcode.cn/problems/remove-element/
//ʾ�� 1��
//
//���룺nums = [3, 2, 2, 3], val = 3
//�����2
//���ͣ�����Ӧ�÷����µĳ��� 2, ���� nums �е�ǰ����Ԫ�ؾ�Ϊ 2��
//�㲻��Ҫ���������г����³��Ⱥ����Ԫ�ء����磬�������ص��³���Ϊ 2 ��
//�� nums = [2, 2, 3, 3] �� nums = [2, 2, 0, 0]��Ҳ�ᱻ������ȷ�𰸡�
//
//ʾ�� 2��
//
//���룺nums = [0, 1, 2, 2, 3, 0, 4, 2], val = 2
//�����5
//���ͣ�����Ӧ�÷����µĳ��� 5, ���� nums �е�ǰ���Ԫ��Ϊ 0, 1, 3, 0, 4��
//ע�������Ԫ�ؿ�Ϊ����˳���㲻��Ҫ���������г����³��Ⱥ����Ԫ�ء�
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
    ����1
    ����˼·��
        1. ��ǰ�������nums���ҵ�val��һ�γ��ֵ�λ��
        2. ��val֮�������Ԫ��������ǰ���ƣ���ɾ����val
        3. nums����ЧԪ�ظ�������һ��
    ѭ����������������ֱ��nums������ֵΪval��Ԫ��ȫ��ɾ����
    ʱ�临�Ӷ�:O(N^2)  �ռ临�Ӷ�:O(1)
*/
#if 0
int removeElement(int* nums, int numsSize, int val) {
    // 
    while (1)
    {
        // 1. ��nums����val���ֵ�λ��
        int pos = 0;
        for (; pos < numsSize; ++pos)
        {
            if (nums[pos] == val)
            {
                break;
            }
        }


        // 2. ����Ƿ��ҵ�
        if (pos == numsSize)
            break;


        // 3. �ҵ�ֵΪvalue��Ԫ��--����ɾ��
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
    ����2��
    ����˼·:
        1. ����һ��������nums��ͬ������temp
        2. ����nums����nums��������val��ͬ��Ԫ�ذ��Ƶ�temp��
        3. ��temp������Ԫ�ؿ�����nums��
       ʱ�临�Ӷ�: O(N)  �ռ临�Ӷ�: O(N)
*/
int removeElement(int* nums, int numsSize, int val) {
    // 1. ����numSize��Ԫ�ص��¿ռ�
    int* temp = (int*)malloc(sizeof(int) * numsSize);
    if (NULL == temp)
    {
        return 0;
    }


    // 2. ��nums�з�value��Ԫ�ذ��Ƶ�temp��---β�嵽temp��
    int count = 0;
    for (int i = 0; i < numsSize; ++i)
    {
        if (nums[i] != val)
        {
            temp[count] = nums[i];
            ++count;
        }
    }


    // 3. ��temp��ɾ��val֮�������Ԫ�ؿ�����nums��
    memcpy(nums, temp, sizeof(int) * count);
    free(temp);
    return count;
}
#endif


#if 0
/*
    ����2�Ż���
    ����˼·:
    ��Ϊ��Ŀ˵�ˣ�������Ԫ�ظ������Ϊ100�����Բ��ö�̬���룬����������100��Ԫ�����鼴��
        1. ����һ��100��Ԫ�ص���������temp
        2. ����nums����nums��������val��ͬ��Ԫ�ذ��Ƶ�temp��
        3. ��temp������Ԫ�ؿ�����nums��
       ʱ�临�Ӷ�: O(N)  �ռ临�Ӷ�: O(N)
*/
int removeElement(int* nums, int numsSize, int val) {
    // 1. ����numSize��Ԫ�ص��¿ռ�
    int temp[100];


    // 2. ��nums�з�value��Ԫ�ذ��Ƶ�temp��---β�嵽temp��
    int count = 0;
    for (int i = 0; i < numsSize; ++i)
    {
        if (nums[i] != val)
        {
            temp[count] = nums[i];
            ++count;
        }
    }


    // 3. ��temp��ɾ��val֮�������Ԫ�ؿ�����nums��
    memcpy(nums, temp, sizeof(int) * count);
    return count;
}
#endif


#if 1
/*
    ����˼·:
        1. ����һ������count��������¼nums��ֵ����val��Ԫ�صĸ���
        2. ����nums���飬����ÿ��Ԫ�ؽ������²�����
            a. ���num[i]����val��˵��ֵΪval��Ԫ�س�����һ�Σ�count++
            b. ���nums[i]������Ԫ�أ���nums[i]��ǰ����count��λ��
                ��Ϊnums[i]Ԫ��֮ǰ���ֹ�count��ֵ����val��Ԫ�أ��Ѿ���ɾ����
                ��˴�����Ҫ��nums[i]��ǰ����
        3. ����ɾ��֮������������ЧԪ�ظ���

    ʱ�临�Ӷȣ�O(N)   �ռ临�Ӷȣ�O(1)
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