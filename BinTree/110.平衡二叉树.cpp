/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
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
    判断二叉树是否是平衡二叉树
        1. 先判断左边是否平衡，再判断右边是否平衡
        2. 判断左右树的高度差是否差 一
*/
class Solution {
  public:
    bool isBalanced(TreeNode *root) {
        if (!root) {
            return true;
        }
        if (isBalanced(root->left) && isBalanced(root->right)) {
            if (abs(getDepth(root->left) - getDepth(root->right)) <= 1) {
                return true;
            } else {
                return false;
            }
        } else {
            return false;
        }
    }

    int getDepth(TreeNode *cur) {
        if (!cur) {
            return 0;
        }
        int leftdDepth = getDepth(cur->left);
        int rightDepth = getDepth(cur->right);
        int depth = max(leftdDepth, rightDepth) + 1;
        return depth;
    }
};
// @lc code=end
