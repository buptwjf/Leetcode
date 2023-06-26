//
// Created by 86188 on 2023/6/25.
//
// 两个链表的第一个公共节点


/*
 * 思路：
 * 1. 统计两个链表的长度
 * 2. 根据长度差采用双指针
 * 3. 指针连续后移
 *
 * 时间 O(n)， 空间 O(1)
 * */

#include "../include/user.h"

using namespace std;

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int len_A = 0;
        int len_B = 0;
        // 必须有两个临时的指针代表 headA headB
        ListNode* curA = headA;
        ListNode* curB = headB;
        while (curA) {
            curA = curA->next;
            len_A++;
        }
        while (curB) {
            curB = curB->next;
            len_B++;
        }
        int diff = abs(len_A - len_B);
        if (len_A > len_B) {
            while (diff--) {
                headA = headA->next;
            }
        } else {
            while (diff--) {
                headB = headB->next;
            }
        }

        // 同时后移
        while (headA && headB) {
            if (headA == headB) {
                break;
            }
            headA = headA->next;
            headB = headB->next;
        }
        return headA;
    }
};