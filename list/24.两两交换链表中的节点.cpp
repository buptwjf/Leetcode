/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
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
    ListNode* swapPairs(ListNode* head) {
        
        // 设置虚拟头结点
        ListNode *dummyHead = new ListNode(0);
        dummyHead->next = head;
        // dummyHead = head;

        ListNode *cur = dummyHead;
        // 当链表为空，或者链表只有一个节点
        while (cur->next != nullptr && cur->next->next != nullptr) {
            ListNode *tmp1 = cur->next->next->next;
            ListNode *tmp2 = cur->next;

            
            cur->next = cur->next->next;    // 步骤一
            cur->next->next = tmp2;          // 步骤二
            cur->next->next->next = tmp1;   // 步骤三

            cur = cur->next->next;
        }
        return dummyHead->next;
    }
};
// @lc code=end

