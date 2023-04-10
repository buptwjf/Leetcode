/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
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
    这个原理和求最大深度相同

        根节点的最新深度 = 1 + 左右子树的最小深度

        特别的：当一个节点只有一个孩子，那么该节点的深度不能当做 1 + 0

*/
class Solution {
  public:
    int minDepth(TreeNode *root) { return getDepth(root); }

    int getDepth(TreeNode *cur) {
        // 1. 迭代的停止条件
        if (!cur) {
            return 0;
        }

        int depth;
        // 特殊处理，左右子树只有一个的情况
        if (!cur->left && cur->right) {
            depth = 1 + getDepth(cur->right);
        } else if (cur->left && !cur->right) {
            depth = 1 + getDepth(cur->left);
        } else {
            depth = 1 + min(getDepth(cur->left),getDepth(cur->right));  // 遍历顺序 左、右、中 或者右，中，左
        }
        return depth;
    }
};
// @lc code=end
