//
// Created by 86188 on 2023/7/19.
//


#include "../include/user.h"

using namespace std;

/*
 * 按照层数打印二叉树
 *
 * 思路：while 控制层序遍历 + for 循环控制每一行
 * */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int>> res;
        if (root == nullptr) {
            return res;
        }
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            vector<int> tmpVec;
            for (int i = 0; i < size; i++) {
                TreeNode *tmp = q.front();
                tmpVec.push_back(tmp->val);
                q.pop();
                if (tmp->left) {
                    q.push(tmp->left);
                }
                if (tmp->right) {
                    q.push(tmp->right);
                }
            }
            res.push_back(tmpVec);
        }
        return res;
    }
};