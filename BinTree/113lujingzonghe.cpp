//
// Created by 86188 on 2023/7/21.
//

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
 * 问题：找到所有从根节点到叶子节点路径和为 target 的所有路径
 * 思路：采用 dfs + 回溯
 *      1. 从根节点开始遍历，一直到叶节点
 *      2. 因为要得到所有路径，dfs 不需要返回值
 *
 * 剪枝思路：如果这些数都为正数，那么只要大于 target 了就可以返回
 * */
class Solution {
private:
    vector<vector<int>> res;
    vector<int> path;

public:
    void dfs(TreeNode *cur, int &count) {
        // 到了叶节点并且满target
        if (!cur->left && !cur->right && count == 0) {
            res.push_back(path);
            return;
        }
        // 到了叶节点但不满足
        if (!cur->left && !cur->right) {
            return;
        }
        if (cur->left) {
            count -= cur->left->val;
            path.push_back(cur->left->val);
            dfs(cur->left, count);
            // 在这里进行回溯
            count += cur->left->val;
            path.pop_back();
        }
        if (cur->right) {
            count -= cur->right->val;
            path.push_back(cur->right->val);
            dfs(cur->right, count);
            // 在这里进行回溯
            count += cur->right->val;
            path.pop_back();
        }
    }

    vector<vector<int>> pathSum(TreeNode *root, int targetSum) {
        res.clear();
        path.clear();
        int count = targetSum;
        if (root == nullptr) {
            return res;
        }
        path.push_back(root->val);
        count -= root->val;
        dfs(root, count);
        return res;
    }
};