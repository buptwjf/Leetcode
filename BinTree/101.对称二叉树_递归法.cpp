/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
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
    对称二叉树递归法
    思路：
        从左子树，右子树开始递归
            1.
   判断左右子树是否对称，然后递归判断左右子树的各自左右子树是否都存在
*/
class Solution {
  public:
    bool compare(TreeNode *left, TreeNode *right) {
        // 左右子树都不存在
        if (!left && !right) {
            return true;
        } else if (left && !right) {
            return false;
        } else if (!left && right) {
            return false;
        } else if (left->val != right->val) {
            return false;
        } else {
            bool isSymmertic_1 = compare(left->left, right->right);
            bool isSymmertic_2 = compare(left->right, right->left);
            return isSymmertic_1 && isSymmertic_2;
        }
        // 右有左没有
        // 左右不相等
    }
    bool isSymmetric(TreeNode *root) {
        if (!root) {
            return true;
        }
        return compare(root->left, root->right);
    }
};
// @lc code=end
