/*
 * @lc app=leetcode.cn id=654 lang=cpp
 *
 * [654] 最大二叉树
 */
#include "../../0_offer2/include/user.h"
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

#include <iostream>
#include <vector>

using namespace std;

/*
    思路：
        1. 递归（由于是构造二叉树，因此要采用 中 左 右的顺序）
            先找到最大的节点，以它作为根节点，构造二叉树
            以最大的节点作为分割点，然后进行划分左右子树
            a. 递归停止的条件：数组为空


*/
class Solution {
public:
    TreeNode *constructMaximumBinaryTree(vector<int> &nums) {
        return traversal(nums);
    }

private:
    TreeNode *traversal(vector<int> curNums) {
        int curMax = -1;
        int index = -1;
        // 递归终止条件
        if (curNums.empty()) {
            return nullptr;
        }
        // 找到最大的元素和他的位置
        for (int i = 0; i < curNums.size(); i++) {
            if (curNums[i] > curMax) {
                curMax = curNums[i];
                index = i;
            }
        }
        vector<int> leftVec = vector(curNums.begin(), curNums.begin() + index);
        vector<int> rightVec = vector(curNums.begin() + index + 1, curNums.end());

        // 创建 root 节点
        TreeNode *root = new TreeNode(curMax);

        root->left = traversal(leftVec);
        root->right = traversal(rightVec);

        return root;
    }
};
// @lc code=end
