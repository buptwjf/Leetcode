/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
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
    思路：
        当前节点的高度 = 1 + 左右子树的最大高度
*/
class Solution {
  public:
    int maxDepth(TreeNode *root) { return getdepth(root); }

    int getdepth(TreeNode *cur) {
        if (!cur) {
            return 0; //必须写在这里，写在主函数里会超时，减少来回的调用
        }
        int depth = 1 + max(getdepth(cur->left),getdepth(cur->right));
        /*
         * 这里实际是中序遍历
         * max1 =
         * */
        return depth;
    }
};
// @lc code=end
