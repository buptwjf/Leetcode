/*
 * @lc app=leetcode.cn id=543 lang=cpp
 *
 * [543] 二叉树的直径
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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
 #include "../0_offer2/include/user.h"

using namespace std;
/*
 * 找出二叉树中最长的路径
 * 思路：进行后序遍历
 * */
class Solution {
private:
    int res;
public:
    int diameterOfBinaryTree(TreeNode *root) {
        res = 0;
        getDepth(root);
        return res;
    }

    int getDepth(TreeNode *cur) {
        if (!cur) {
            return 0;
        }
        int leftDepth = getDepth(cur->left);
        int rightDepth = getDepth(cur->right);
        int MaxD = leftDepth + rightDepth;
        res = max(res, MaxD);
        return max(leftDepth, rightDepth) + 1;
    }
};
// @lc code=end

