//
// Created by 86188 on 2023/6/24.
//
#include "../include/user.h"

using namespace std;
// 此题接近 LeetCode 203 但是简单很多

// 核心在于记录 cur 和 pre
// V.1 版本
class Solution {
public:
    ListNode *deleteNode(ListNode *head, int val) {
        ListNode *cur = head;
        ListNode *pre = nullptr;
        while (cur != nullptr && cur->val != val) {
            pre = cur;
            cur = cur->next;
        }
        // 得到 cur 以及 pre
        pre->next = cur->next;
        return head;
    }
};

// V.1版本，可以但不够优雅
// V.2版本，使用 dummyHead
class Solution1 {
public:
    ListNode *deleteNode(ListNode *head, int val) {
        ListNode *dummyHead = new ListNode(-1);
        ListNode *cur = head;

        ListNode *pre = dummyHead;
        dummyHead->next = cur;
        while (cur != nullptr) {
            if (cur->val == val) {
                break;
            }
            pre = cur;
            cur = cur->next;
        }
        pre->next = cur->next;
        return dummyHead->next;
    }
};


// V.3 版本，使用递归，但不推荐
class Solution2 {
public:
    ListNode *deleteNode(ListNode *head, int val) {
        if (head == nullptr) {
            return nullptr;
        }
        if (head->val == val) {
            return head->next;
        }
        head->next = deleteNode(head->next, val);
        return head;
    }
};
