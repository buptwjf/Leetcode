/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
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
class Solution {
  public:
    ListNode *removeElements(ListNode *head, int val) { // 没有虚拟tou
        while (head != NULL && head->val == val) {
            ListNode *tmp = head;
            head = head->next;
            delete tmp; // 删除内存
        }
        // 删除非头节点 不要从 ListNode* cur = head->next开始
        ListNode *cur = head;
        // 当连链表长度 >= 2 时
        while (cur != NULL && cur->next != NULL) // 一定要确保访问链表有值
        {
            if (cur->next->val == val) {
                ListNode *tmp = cur->next;
                cur->next = cur->next->next;
                delete tmp; // 删除内存
            } else {
                cur = cur->next;
            }
        }
        return head;
    }
};
// @lc code=end

class Solution1 {
  public:
    ListNode *removeElements(ListNode *head, int val) {

        while (head != NULL && head->val == val) {
            ListNode *tmp = head;
            head = head->next;
            delete tmp; // 删除内存
        }
        // 删除非头节点 不要从 ListNode* cur = head->next开始
        ListNode *cur = head;
        // 当连链表长度 >= 2 时
        while (cur != NULL && cur->next != NULL) // 一定要确保访问链表有值
        {
            if (cur->next->val == val) {
                ListNode *tmp = cur->next;
                cur->next = cur->next->next;
                delete tmp; // 删除内存
            } else {
                cur = cur->next;
            }
        }
        return head;
    }
};