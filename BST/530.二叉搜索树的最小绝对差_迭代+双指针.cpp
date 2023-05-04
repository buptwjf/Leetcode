/*
 * @lc app=leetcode.cn id=530 lang=cpp
 *
 * [530] 二叉搜索树的最小绝对差
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

/*
    迭代法 + 双指针 法最清晰

    在迭代的过程中进行判断：
        为什么可以这样，根据中序遍历得到的结果列表，可以知道得到的结果是按照从小到大有序排列的
*/
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
  public:
    int getMinimumDifference(TreeNode *root) {
        stack<TreeNode *> st;
        int result = INT_MAX;
        TreeNode *cur = root;
        TreeNode *pre = nullptr;

        while (true) {
            if (cur) {
                st.push(cur);
                cur = cur->left;
            } // 左孩子一直入栈
            if (st.empty()) {
                break;
            }
            cur = st.top();
            st.pop();
            if (pre != nullptr) {
                result = min(result, cur->val - pre->val);
            }
            pre = cur;
            cur = cur->right;
        }
    };
    // @lc code=end
