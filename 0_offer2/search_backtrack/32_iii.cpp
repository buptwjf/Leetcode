//
// Created by 86188 on 2023/7/19.
//
#include "../include/user.h"
#include "algorithm"

using namespace std;

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int>> res;
        if (root == nullptr) {
            return res;
        }
        queue<TreeNode *> q;
        q.push(root);
        bool flag = true;
        while (!q.empty()) {
            int size = q.size();
//            vector<int> tmpVec;
//            for (int i = 0; i < size; i++) {
//                treenode *tmp = q.front();
//                tmpvec.push_back(tmp->val);
//                q.pop();
//                if (tmp->left) {
//                    q.push(tmp->left);
//                }
//                if (tmp->right) {
//                    q.push(tmp->right);
//                }
//            }
//            if (flag) {
//                res.push_back(tmpvec);
//            } else {
//                reverse(tmpvec.begin(), tmpvec.end());
//                res.push_back(tmpvec);
//            }

            // 另一种写法
            deque<int> tmpVec; // 使用 deque 容器
            for (int i = 0; i < size; i++) {
                TreeNode *tmp = q.front();
                // 通过头插 尾插来控制顺序
                if (flag) {
                    tmpVec.push_back(tmp->val);
                } else {
                    tmpVec.push_front(tmp->val);
                }
            }
            flag = !flag; // 换方向
            // 由于 tmpVec 是 deque 类型，因此需要使用 emplace_back()
            res.emplace_back(vector<int>(tmpVec.begin(), tmpVec.end()));
        }
        return res;
    }
};