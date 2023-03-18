/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution { // 双指针法
public:
    ListNode *reverseList(ListNode *head) {
        ListNode *cur = head;  
        ListNode *pre = nullptr;
        ListNode *tmp;

        // 一直循环到链表末尾
        while (cur != nullptr) {
            tmp = cur->next;
            cur->next = pre;
            
            pre = cur;
            cur = tmp;
        }
        return pre;
    }
};
// @lc code=end

