/*
 * @lc app=leetcode.cn id=226 lang=cpp
 *
 * [226] 226. 翻转二叉树
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
    翻转二叉树的思路, 采用递归的方式，对于单独一个节点来说，先交换他的左右孩子，然后对左右节点作为根进行翻转
*/

// 采用 递归 + 后续遍历的递归法
class Solution {
  public:
    TreeNode *invertTree(TreeNode *root) {
        if (root) {
            TreeNode *cur = root;
            invertTree(cur->left);
            invertTree(cur->right);
            swap(cur->left, cur->right);
            return root;
        }
        return root;
    }
};

// 采用先序遍历的递归法
class Solution1 {
  public:
    TreeNode *invertTree(TreeNode *root) {
        if (root) {
            TreeNode *cur = root;
            swap(cur->left, cur->right);
            invertTree(cur->left);
            invertTree(cur->right);
            return root;
        }
        return root;
    }
};
// @lc code=end
