/*
 * @lc app=leetcode.cn id=404 lang=cpp
 *
 * [404] 左叶子之和
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
    求所有节点的左叶子之和
    思路：
        采用递归的方式
        1. 停止条件：是左叶子
            左叶子不能自己判断，xu
        2. 遍历顺序为 左右中，因为要最后求中
*/
class Solution {
  public:
    int sumOfLeftLeaves(TreeNode *root) {
        int sum = leftChild(root);
        return sum;
    }

    int leftChild(TreeNode *cur) {
        // // 递归停止条件，节点为空，或者节点为叶节点
        if (!cur) {
            return 0;
        }
        if (!cur->left && !cur->right) { 
            return 0;
        }
        int lc, rc;
        // 如果他的左孩子是左叶节点，可直接得到 lc
        if (cur->left && !cur->left->left && !cur->left->right) {
            lc = cur->left->val;
        } else {
            // 否则就要从左子树中找
            lc = leftChild(cur->left);
        }

        // 从右子树中找
        rc = leftChild(cur->right);
        int sum = lc + rc;
        return sum;
    }
};
// @lc code=end
