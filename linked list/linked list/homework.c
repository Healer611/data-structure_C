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
// https://leetcode.cn/problems/merge-two-sorted-lists/description/
 //Definition for singly-linked list.
 struct ListNode {
     int val;
      struct ListNode *next;
 };
 //β��
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
 //��һ�ֵ�ת������
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
//�ڶ���ͷ��
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* cur = head;
    struct ListNode* rhead = NULL;
    while (cur) {
        struct ListNode* next = cur->next;
        cur->next = rhead;
        rhead = cur;
        cur = next;
    }
    return rhead;
}


//�����е�����k�����
//https://www.nowcoder.com/practice/529d3ae5a407492994ad2a246518148a?tpId=13&&tqId=11167&rp=2&ru=/activity/oj&qru=/ta/coding-interviews/question-ranking
struct ListNode* FindKthToTail(struct ListNode* pListHead, int k) {
    struct ListNode* slow = pListHead, * fast = pListHead;
    int n = 0;
    while (k) {
        if (fast == NULL)//k����������Ҳ����fastΪ��ʱ
            return 0;
        fast = fast->next;
        k--;
    }

    while (fast) {
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
}


//CM11 ����ָ�
//https://www.nowcoder.com/practice/0e27e0b064de4eacac178676ef9c9d70?tpId=8&&tqId=11004&rp=2&ru=/activity/oj&qru=/ta/cracking-the-coding-interview/question-ranking
struct ListNode {
    int val;
    struct ListNode *next;

};
class Partition {
public:
    ListNode* partition(ListNode* pHead, int x) {
        struct ListNode* lesshead, * lesstail, * greaterhead, * greatertail;

        lesshead = lesstail = (struct ListNode*)malloc(sizeof(struct ListNode));
        greaterhead = greatertail = (struct ListNode*)malloc(sizeof(struct ListNode));

        struct ListNode* cur = pHead;
        while (cur) {
            if (cur->val < x) {
                lesstail->next = cur;
                lesstail = lesstail->next;
            }
            else {
                greatertail->next = cur;
                greatertail = greatertail->next;
            }
            cur = cur->next;
        }

        lesstail->next = greaterhead->next;
        greatertail->next = NULL;
        pHead = lesshead->next;

        free(lesshead);
        free(greaterhead);

        return pHead;
    }
};


//OR36 ����Ļ��Ľṹ
//https://www.nowcoder.com/practice/d281619e4b3e4a60a2cc66ea32855bfa?tpId=49&&tqId=29370&rp=1&ru=/activity/oj&qru=/ta/2016test/question-ranking
class PalindromeList {
public:
    struct ListNode* middleNode(struct ListNode* head) {
        struct ListNode* slow = head;
        struct ListNode* fast = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    struct ListNode* reverseList(struct ListNode* head) {
        struct ListNode* cur = head, * rhead = NULL;
        while (cur) {
            struct ListNode* next = cur->next;
            cur->next = rhead;
            rhead = cur;
            cur = next;
        }
        return rhead;
    }
    bool chkPalindrome(ListNode* head) {
        struct ListNode* mid = middleNode(head);
        struct ListNode* rmid = reverseList(mid);
        while (rmid) {
            if (rmid->val == head->val) {
                rmid = rmid->next;
                head = head->next;
            }
            else {
                return false;
            }
        }
        return true;
    }
};


//160. �ཻ����
//https://leetcode.cn/problems/intersection-of-two-linked-lists/description/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB) {
    struct ListNode* tailA = headA;
    struct ListNode* tailB = headB;
    int lenA = 1, lenB = 1;
    while (tailA->next) {
        tailA = tailA->next;
        lenA++;
    }
    while (tailB->next) {
        tailB = tailB->next;
        lenB++;
    }
    if (tailA != tailB) {
        return NULL;
    }
    int gap = abs(lenA - lenB);
    struct ListNode* longList = headA;
    struct ListNode* shortList = headB;
    if (lenA < lenB) {
        longList = headB;
        shortList = headA;
    }
    while (gap--) {
        longList = longList->next;
    }
    while (longList != shortList) {
        longList = longList->next;
        shortList = shortList->next;
    }
    return longList;
}


#include <stdbool.h>
//141. ��������
//https://leetcode.cn/problems/linked-list-cycle/description/
bool hasCycle(struct ListNode* head) {
    struct ListNode* fast = head;
    struct ListNode* slow = head;
    while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
            return true;
    }
    return false;
}

//142. �������� II
//https://leetcode.cn/problems/linked-list-cycle-ii/description/

struct ListNode* detectCycle(struct ListNode* head) {
    struct ListNode* fast = head;
    struct ListNode* slow = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow) {
            struct ListNode* meet = slow;
            while (head != meet) {
                head = head->next;
                meet = meet->next;
            }
            return meet;
        }
    }
    return NULL;
}


struct ListNode* detectCycle(struct ListNode* head) {
    struct ListNode* fast = head;
    struct ListNode* slow = head;
    if (head == NULL || head->next == NULL) {
        return NULL;
    }
    while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
            break;
    }
    if (fast != slow) {
        return NULL;
    }
    struct ListNode* cur = head;
    while (cur != slow) {
        slow = slow->next;
        cur = cur->next;
    }
    return cur;
}