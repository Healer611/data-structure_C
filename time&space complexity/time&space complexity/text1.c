#define _CRT_SECURE_NO_WARNINGS 1

//��ʧ������

//����nums������0��n������������������ȱ��һ�������д�����ҳ��Ǹ�ȱʧ�����������а취��O(n)ʱ���������
//ʾ�� 1��
//
//���룺[3, 0, 1]
//�����2
//
//
//ʾ�� 2��
//
//���룺[9, 6, 4, 2, 3, 5, 7, 0, 1]
//�����8
//���
int missingNumber(int* nums, int numsSize) {
    int x = 0;
    for (int i = 0; i < numsSize; i++)
        x ^= nums[i];
    for (int i = 0; i < numsSize + 1; i++)
        x ^= i;
    return x;
}
//�Ȳʽ
//int missingNumber(int* nums, int numsSize) {
//    int x = (1 + numsSize) * numsSize / 2;
//    for (int i = 0; i < numsSize; i++)
//        x -= nums[i];
//    return x;
//}
