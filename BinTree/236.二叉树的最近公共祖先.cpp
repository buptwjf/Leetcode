/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/*
    二叉树的公共祖先：

    思路：
        从一个节点遍历自己的子树寻找 p 和 q：
            如果一个节点的左右子树都为 true 那么这个节点就是 p 和 q 的公共祖先


*/
class Solution {
  public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {

        // 递归终止条件 找到 p 或 q 或者 节点为空
        if (root == q || root == p || !root) {
            return root;
        }

        // 左 右 中 遍历
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);

        // 对中间的节点进行判定
        if (left && right) {
            return root;
        }

        if (!left && right) {
            return right;
        } else if (left && !right) {
            return left;
        } else { //(!left && !right)
            return nullptr;
        }
    }
};
// @lc code=end
