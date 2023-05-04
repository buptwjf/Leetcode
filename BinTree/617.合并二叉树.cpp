/*
 * @lc app=leetcode.cn id=617 lang=cpp
 *
 * [617] 合并二叉树
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
    思路： 中，左，右
    递归：
        1.递归停止条件：两个树节点都为空
        2. 从根节点开始，如果两个节点都有值，那么合并，让后从左节点，右节点开始
*/
class Solution {
  public:
    TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2) {
        return traversal(root1, root2);
    }

    TreeNode *traversal(TreeNode *cur1, TreeNode *cur2) {
        // 递归终止条件
        if (!cur1 && !cur2) {
            return nullptr;
        }
        if (cur1 && cur2) {
            TreeNode *root = new TreeNode(cur1->val + cur2->val);
            root->left = traversal(cur1->left, cur2->left);
            root->right = traversal(cur1->right, cur2->right);
            return root;
        } else if (cur1 && !cur2) {
            TreeNode *root = new TreeNode(cur1->val);
            root->left = traversal(cur1->left, nullptr);
            root->right = traversal(cur1->right, nullptr);
            return root;
        } else { // (!cur1 && cur2)
            TreeNode *root = new TreeNode(cur2->val);
            root->left = traversal(nullptr, cur2->left);
            root->right = traversal(nullptr, cur2->right);
            return root;
        }
    }
};
// @lc code=end
