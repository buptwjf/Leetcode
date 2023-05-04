/*
 * @lc app=leetcode.cn id=235 lang=cpp
 *
 * [235] 二叉搜索树的最近公共祖先
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
    由于二叉树具有天然的排序性质，所有 公共节点
        p->val < commonNode->val < q->val

    用迭代法最好
*/
class Solution {
  public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        int pVal = p->val;
        int qVal = q->val;
        int maxVal = max(p->val, q->val);
        while (true) {
            if (root->val > q->val && root->val > p->val) {
                root = root->left;
            } else if (root->val < q->val && root->val < p->val) {
                root = root->right;
            } else {
                return root;
            }
        }
    }
};
// @lc code=end
