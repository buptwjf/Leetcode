//
// Created by 86188 on 2023/6/24.
//

// 合并两个排序列表
#include "../include/user.h"

using namespace std;

// 合并两个排序好的列表
// 双指针法
class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *dummyHead = new ListNode(-1);
        ListNode *cur = dummyHead;

        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val <= l2->val) {
                ListNode *tmp = new ListNode(l1->val);
                cout << l1->val << endl;
                cur->next = tmp;
                cur = tmp;
                l1 = l1->next;
            } else {
                ListNode *tmp = new ListNode(l2->val);
                cout << l2->val << endl;
                cur->next = tmp;
                cur = tmp;
                l2 = l2->next;
            }
        }

        if (l1 == nullptr) {
            while (l2 != nullptr) {
                ListNode *tmp = new ListNode(l2->val);
                cur->next = tmp;
                l2 = l2->next;
                cur = tmp;
            }
        } else {
            while (l1 != nullptr) {
                ListNode *tmp = new ListNode(l1->val);
                cur->next = tmp;
                l1 = l1->next;
                cur = tmp;
            }
        }
        return dummyHead->next;
    }
};

// 递归法
class Solution1 {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        // 递归终止条件
        if (l1 == nullptr) {
            return l2;
        }
        if (l2 == nullptr) {
            return l1;
        }
        if (l1->val <= l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l1, l2->next);
            return  l2;
        }
    }
};

