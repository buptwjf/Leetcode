/*
 * @lc app=leetcode.cn id=669 lang=cpp
 *
 * [669] 修剪二叉搜索树
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
    修剪二叉搜索树，使用迭代法
    1. 首先将根节点置于 (low, high)之间
    2. 再将左孩子置于 (low, high)之间
    3. 再将右孩子置于 (low, high)之间
*/
class Solution {
  public:
    TreeNode *trimBST(TreeNode *root, int low, int high) {
        if (root == nullptr) {
            return nullptr;
        }
        while (root != nullptr && (root->val < low || root->val > high)) {
            if (root->val < low) {
                root = root->right;
            }
            if (root->val > high) {
                root = root->left;
            }
        }
        TreeNode *cur = root;
        while (cur != nullptr) {
            while (cur->left != nullptr && cur->left->val < low) {
                cur->left = cur->left->right;
            }
            cur = cur->left;
        }

        cur = root;
        while (cur != nullptr) {
            while (cur->right != nullptr && cur->right->val > high) {
                cur->right = cur->right->left;
            }
            cur = cur->right;
        }
        return root;
    }
};
// @lc code=end
