#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

//203. 移除链表元素
//https://leetcode.cn/problems/remove-linked-list-elements/description/
//Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

//***第一种***
struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode* prev = NULL, * cur = head;
    //cur指向头节点，prev指向头结点前一个节点，初始值为空
    while (cur) {        
        if (cur->val == val) {//如果通过cur找到了val则删除
            if (prev) {
                //借助prev判断，是否删除的是头结点，
                // prev不为NULL，删除该节点
                prev->next = cur->next;//prev的next指向删除节点的下一个节点
                free(cur);//释放删除节点的空间
                cur = prev->next;//cur指向prev后一个节点
            }
            else {//删除头节点
                cur = head->next;//cur指向头节点后一个节点
                free(head);//删除头结点
                head = cur;//更新头结点
            }
        }
        else {//找不到则prev和cur向后移动
            prev = cur;
            cur = cur->next;
        }
    }
    return head;
}


////***第二种***
struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode* cur = head;        // 当前遍历节点
    struct ListNode* newhead = NULL;    // 新链表的头节点
    struct ListNode* tail = NULL;      // 新链表的尾节点

    while (cur) {
        if (cur->val != val) { // 当前节点的值不等于要删除的值
            if (tail == NULL) { // 第一次插入
                newhead = tail = cur; // 设置新链表的头和尾
            }
            else {
                tail->next = cur; // 将当前节点连接到新链表的尾部
                tail = tail->next; // 更新新链表的尾节点
            }
            cur = cur->next;     // 移动到下一个节点
            tail->next = NULL;  // 断开新链表的尾节点连接
        }
        else {
            struct ListNode* del = cur; // 保存需要删除的节点
            cur = cur->next;           // 移动到下一个节点
            free(del);                // 释放需要删除的节点的内存
        }
    }

    return newhead; // 返回新链表的头节点，已移除所有值为 val 的节点
}



//876. 链表的中间结点
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




////21. 合并两个有序链表
// https://leetcode.cn/problems/merge-two-sorted-lists/description/
 //Definition for singly-linked list.
 struct ListNode {
     int val;
      struct ListNode *next;
 };
 //尾插
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    if (list1 == NULL)
        return list2;
    if (list2 == NULL)
        return list1;

    struct ListNode* tail = NULL, * head = NULL; 
//定义了两个指针 tail 和 head，它们用于构建合并后的链表。
//head 用于跟踪新链表的头部，tail 用于跟踪新链表的尾部
        
    while (list1 && list2) {
        /*比较 list1 和 list2 当前节点的值。
如果 list1 的当前节点值小于 list2 的当前节点值，将 list1 的节点添加到合并后的链表中。
如果 list2 的当前节点值小于等于 list1 的当前节点值，将 list2 的节点添加到合并后的链表中。*/
        if (list1->val < list2->val) {
            /*在向合并链表中添加节点时，需要检查 tail 是否为 NULL，
            如果是，说明这是第一个节点，因此同时更新 head 和 tail。
            否则，只需将新节点连接到 tail 的 next 并将 tail 更新为新节点。*/
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


//206. 反转链表
// https://leetcode.cn/problems/reverse-linked-list/description/
//Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};
 //第一种调转链表方向
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
        if (n3)//n3不为空时才能指向下一个节点
            n3 = n3->next;
    }
    return n1;
}
//第二种头插
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


//链表中倒数第k个结点
//https://www.nowcoder.com/practice/529d3ae5a407492994ad2a246518148a?tpId=13&&tqId=11167&rp=2&ru=/activity/oj&qru=/ta/coding-interviews/question-ranking
struct ListNode* FindKthToTail(struct ListNode* pListHead, int k) {
    struct ListNode* slow = pListHead, * fast = pListHead;
    int n = 0;
    while (k) {
        if (fast == NULL)//k大于链表长度也就是fast为空时
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


//CM11 链表分割
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


//OR36 链表的回文结构
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


//160. 相交链表
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
//141. 环形链表
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

//142. 环形链表 II
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