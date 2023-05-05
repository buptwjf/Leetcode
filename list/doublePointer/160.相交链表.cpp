/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // 分别计算两个链表的长度
        int sizeA = 0;
        int sizeB = 0;

        ListNode *curA = headA;
        ListNode *curB = headB;
        while (curA!= nullptr) {
            sizeA++;
            curA = curA->next;
        }
        cout << "sizeA" << sizeA << endl;

        while (curB != nullptr) {
            sizeB++;
            curB = curB->next;
        }
        cout << "sizeB" << sizeB << endl;


        curA = headA;
        curB = headB;
        int diff = sizeA - sizeB;
        int diff_abs = abs(diff);
        cout << "diff_abs" << diff_abs << endl;
        if (diff >= 0) { // A 大
            while (diff_abs--) {
                curA = curA->next;
            }
        } else {
            while (diff_abs--) {
                curB = curB->next;
            }
        }

        // 一起走
        while (curA != nullptr) {
            if (curA == curB) {
                return curA;
            }
            curA = curA->next;
            curB = curB->next;
        }
        return NULL;
    }
};
// @lc code=end

