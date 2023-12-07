/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
 */

#include "../0_offer2/include/user.h"

using namespace std;
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
class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> result;
        Traversal(root, result);
        return result;
    }

    void Traversal(TreeNode *cur, vector<int> &result) {
        if (cur == nullptr) {
            return;
        }
        result.push_back(cur->val);
        Traversal(cur->left, result);
        Traversal(cur->right, result);
    }
};
// @lc code=end
