//
// Created by 86188 on 2023/7/21.
//

#include "../include/user.h"

using namespace std;

/*
 * 本题与113题一致
 * */
class Solution {
private:
    vector<vector<int>> res;
    vector<int> path;
protected:
    void dfs(TreeNode *cur, int target) {
        if (!cur->left && !cur->right && target == 0) {
            res.push_back(path);
            return;
        }
        if (!cur->left && !cur->right) {
            return;
        }
        if (cur->left) {
            path.push_back(cur->left->val);
            target -= cur->left->val;
            dfs(cur->left, target);
            // 回溯
            target += cur->left->val;
            path.pop_back();
        }
        if (cur->right) {
            path.push_back(cur->right->val);
            target -= cur->right->val;
            dfs(cur->right, target);
            // 回溯
            target += cur->right->val;
            path.pop_back();
        }
        return;

    }

public:
    vector<vector<int>> pathSum(TreeNode *root, int target) {
        res.clear();
        path.clear();
        if (!root) {
            return res;
        }
        target -= root->val;
        path.push_back(root->val);
        dfs(root, target);
        return res;
    }
};