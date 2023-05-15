/*
 * @lc app=leetcode.cn id=382 lang=cpp
 *
 * [382] 链表随机节点
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

#include <vector>
#include <random>

using namespace std;

// struct ListNode {
//     int val;
//     ListNode *next;

//     ListNode() : val(0), next(nullptr) {}

//     ListNode(int x) : val(x), next(nullptr) {}

//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };


// 水塘抽样法
// 从链表头开始，遍历整个链表，对遍历到的第i 个节点，随机选择区间[0,i) 内的一个整数，如果其等于0，
// 则将答案置为该节点值，否则答案不变。
class Solution {
private:
    ListNode *head;
public:
    Solution(ListNode *head) {
        this->head = head;
    }

    int getRandom() {
        int i = 1;
        int ans = 0;
        for (auto cur = head; cur != nullptr; cur = cur->next) {
            if (rand() % i == 0) { // 100% 的概率选中第一个数，然后用其他数对他替换
                ans = cur->val;
            }
            ++i;
        }
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
// @lc code=end

