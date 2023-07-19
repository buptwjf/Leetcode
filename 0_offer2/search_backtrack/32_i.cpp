//
// Created by 86188 on 2023/7/19.
//
#include "../include/user.h"

using namespace std;

/*
 * 问题：从上到下打印二叉树
 * 思路：层序遍历，用辅助队列
 * */

class Solution {
public:
    vector<int> levelOrder(TreeNode *root) {
        vector<int> res;
        if (root == nullptr) {
            return res;
        }
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode *tmp = q.front();
            res.push_back(tmp->val);
            q.pop();
            if (tmp->left) {
                q.push(tmp->left);
            }
            if (tmp->right) {
                q.push(tmp->right);
            }
        }
        return res;
    }
};