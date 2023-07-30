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
        这个对应着是动态规划的思路
*/
class Solution {
public:
    int maxDepth(TreeNode *root) { return getdepth(root); }

    int getdepth(TreeNode *cur) {
        if (!cur) {
            return 0; //必须写在这里，写在主函数里会超时，减少来回的调用
        }
        int depth = 1 + max(getdepth(cur->left), getdepth(cur->right));
        /*
         * 这里实际是后序遍历
         * */
        return depth;
    }
};
// @lc code=end

// 这么写也可以，但是用时会边长
class Solution1 {
public:
    int maxDepth(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        // 利用定义，计算左右子树的最大深度
        int leftMax = maxDepth(root->left);
        int rightMax = maxDepth(root->right);
        // 整棵树的最大深度等于左右子树的最大深度取最大值，
        // 然后再加上根节点自己
        int res = max(leftMax, rightMax) + 1;

        return res;
    }
};