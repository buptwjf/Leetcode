/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
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
    ListNode *detectCycle(ListNode *head) {
        // 初始化两个指针
        ListNode* fast;
        ListNode* slow;

        fast = head;
        slow = head;

        while (fast != nullptr && fast->next != nullptr && fast->next->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
            if (slow == fast) { // 两个指针重合
                ListNode *cur1 = head;
                ListNode *cur2 = fast;

                while (cur1 != cur2) {
                    cur1 = cur1->next;
                    cur2 = cur2->next;
                }
                return cur2;
            }
        }
        return nullptr;
    }
};
// @lc code=end

