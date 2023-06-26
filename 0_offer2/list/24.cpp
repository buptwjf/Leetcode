//
// Created by 86188 on 2023/6/24.
//
#include "../include/user.h"

using namespace std;

class Solution {
public:
    // 使用双指针法
    ListNode *reverseList(ListNode *head) {
        // 从头到尾重新生成一个链表，对新的链表一直使用头插法
        ListNode *cur = head;
        ListNode *pre = nullptr;
        ListNode *tmp;
        while (cur != nullptr) { // 具体来说就是把 cur 一直向 pre 上接
            tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        return cur;
    }
};


// 递归法很重要
class Solution1 {
public:
    ListNode *reverse(ListNode *cur, ListNode *pre) {
        if (cur == nullptr) {
            return pre;
        }
        ListNode *tmp = cur->next;
        cur->next = pre;
        return reverse(tmp, cur);
    }

    // 使用双指针 + 递归法
    ListNode *reverseList(ListNode *head) {
        return reverse(head, nullptr);
    }
};