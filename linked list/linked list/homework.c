#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

//203. �Ƴ�����Ԫ��
//https://leetcode.cn/problems/remove-linked-list-elements/description/
//Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};
 
//***��һ��***
struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode* prev = NULL, * cur = head;
    //curָ��ͷ�ڵ㣬prevָ��ͷ���ǰһ���ڵ㣬��ʼֵΪ��
    while (cur) {        
        if (cur->val == val) {//���ͨ��cur�ҵ���val��ɾ��
            if (prev) {
                //����prev�жϣ��Ƿ�ɾ������ͷ��㣬
                // prev��ΪNULL��ɾ���ýڵ�
                prev->next = cur->next;//prev��nextָ��ɾ���ڵ����һ���ڵ�
                free(cur);//�ͷ�ɾ���ڵ�Ŀռ�
                cur = prev->next;//curָ��prev��һ���ڵ�
            }
            else {//ɾ��ͷ�ڵ�
                cur = head->next;//curָ��ͷ�ڵ��һ���ڵ�
                free(head);//ɾ��ͷ���
                head = cur;//����ͷ���
            }
        }
        else {//�Ҳ�����prev��cur����ƶ�
            prev = cur;
            cur = cur->next;
        }
    }
    return head;
}


////***�ڶ���***
struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode* cur = head;        // ��ǰ�����ڵ�
    struct ListNode* newhead = NULL;    // �������ͷ�ڵ�
    struct ListNode* tail = NULL;      // �������β�ڵ�

    while (cur) {
        if (cur->val != val) { // ��ǰ�ڵ��ֵ������Ҫɾ����ֵ
            if (tail == NULL) { // ��һ�β���
                newhead = tail = cur; // �����������ͷ��β
            }
            else {
                tail->next = cur; // ����ǰ�ڵ����ӵ��������β��
                tail = tail->next; // �����������β�ڵ�
            }
            cur = cur->next;     // �ƶ�����һ���ڵ�
            tail->next = NULL;  // �Ͽ��������β�ڵ�����
        }
        else {
            struct ListNode* del = cur; // ������Ҫɾ���Ľڵ�
            cur = cur->next;           // �ƶ�����һ���ڵ�
            free(del);                // �ͷ���Ҫɾ���Ľڵ���ڴ�
        }
    }

    return newhead; // �����������ͷ�ڵ㣬���Ƴ�����ֵΪ val �Ľڵ�
}



//876. ������м���
//https://leetcode.cn/problems/middle-of-the-linked-list/description/
 struct ListNode {
     int val;
     struct ListNode *next;
 };

struct ListNode* middleNode(struct ListNode* head) {
    struct ListNode* fast = head, * slow = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}



////21. �ϲ�������������
 //Definition for singly-linked list.
 struct ListNode {
     int val;
      struct ListNode *next;
 };
 
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    if (list1 == NULL)
        return list2;
    if (list2 == NULL)
        return list1;

    struct ListNode* tail = NULL, * head = NULL; 
//����������ָ�� tail �� head���������ڹ����ϲ��������
//head ���ڸ����������ͷ����tail ���ڸ����������β��
        
    while (list1 && list2) {
        /*�Ƚ� list1 �� list2 ��ǰ�ڵ��ֵ��
��� list1 �ĵ�ǰ�ڵ�ֵС�� list2 �ĵ�ǰ�ڵ�ֵ���� list1 �Ľڵ���ӵ��ϲ���������С�
��� list2 �ĵ�ǰ�ڵ�ֵС�ڵ��� list1 �ĵ�ǰ�ڵ�ֵ���� list2 �Ľڵ���ӵ��ϲ���������С�*/
        if (list1->val < list2->val) {
            /*����ϲ���������ӽڵ�ʱ����Ҫ��� tail �Ƿ�Ϊ NULL��
            ����ǣ�˵�����ǵ�һ���ڵ㣬���ͬʱ���� head �� tail��
            ����ֻ�轫�½ڵ����ӵ� tail �� next ���� tail ����Ϊ�½ڵ㡣*/
            if (tail == NULL) {
                head = tail = list1;
            }
            else {
                tail->next = list1;
                tail = tail->next;
            }
            list1 = list1->next;
        }
        else {
            if (tail == NULL) {
                head = tail = list2;
            }
            else {
                tail->next = list2;
                tail = tail->next;
            }
            list2 = list2->next;
        }
    }
    if (list1)
        tail->next = list1;
    if (list2)
        tail->next = list2;
    return head;
}



//206. ��ת����
// https://leetcode.cn/problems/reverse-linked-list/description/
//Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};
 

struct ListNode* reverseList(struct ListNode* head) {
    if (head == NULL)
        return NULL;
    struct ListNode* n1 = NULL;
    struct ListNode* n2 = head;
    struct ListNode* n3 = n2->next;
    while (n2) {
        n2->next = n1;
        n1 = n2;
        n2 = n3;
        if (n3)//n3��Ϊ��ʱ����ָ����һ���ڵ�
            n3 = n3->next;
    }
    return n1;
}

