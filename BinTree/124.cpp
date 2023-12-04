/*
 * @lc app=leetcode.cn id=124 lang=cpp
 *
 * [124] 二叉树中的最大路径和
 */

#include "../0_offer2/include/user.h"

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



/*
 * 二叉树的最大路径，思路：
 * 从根节点开始：
 *  分别计算，包含左孩子的最大路径
 *           包含右孩子的最大路径
 *
 *
 * */
using namespace std;

class Solution {
public:
    int res = INT32_MIN;

    int maxPathSum(TreeNode* root){
        maxGain(root);
        return res;
    }
    
    int maxGain(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        int left =  max(0, maxGain(root->left));
        int right =  max(0, maxGain(root->right));

        // 更新答案，比较 res 与 当前节点作为最大路径的根节点时的路径和
        res = max(res, left +  right + root->val);

        // 该根节点作为子节点能贡献的最大值
        return max(left, right) + root->val;
    }
};
// @lc code=end

