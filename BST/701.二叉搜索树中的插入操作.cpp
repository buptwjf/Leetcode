/*
 * @lc app=leetcode.cn id=701 lang=cpp
 *
 * [701] 二叉搜索树中的插入操作
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
    二叉搜索树的插入
    思路：
        二叉搜索树插入很简单，直接找到空节点的位置就可以
*/
class Solution {
  public:
    TreeNode *insertIntoBST(TreeNode *root, int val) {
        TreeNode* realRoot = root;
        if (!root) {
            TreeNode *root = new TreeNode(val);
            return root;
        }
        while (true) {
            if (!root->left && val < root->val) {
                root->left = new TreeNode(val);
                break;
            }
            if (!root->right && val > root->val) {
                root->right = new TreeNode(val);
                break;
            }
            if (val < root->val) {
                root = root->left;
            } else {
                root = root->right;
            }
        }
        return realRoot;
    }
};
// @lc code=end
