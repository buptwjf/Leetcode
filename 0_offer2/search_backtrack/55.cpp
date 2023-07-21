//
// Created by 86188 on 2023/7/21.
//
#include "../include/user.h"

using namespace std;
class Solution {
public:
    int maxDepth(TreeNode *root) {
        queue<TreeNode *> q;
        if (!root) {
            return 0;
        }
        int deep = 0;

        q.push(root);
        // 元素入栈
        while (!q.empty()) {
            // 在最开始的时候记录一下当前队列里元素的数量
            int size = q.size(); // 这个是必须要做的，每次 while 循环对应 二叉树的一层
            deep++;
            for (int i = 0; i < size; i++) {
                TreeNode *cur = q.front();
                q.pop();
                if (cur->left) {
                    q.push(cur->left);
                }
                if (cur->right) {
                    q.push(cur->right);
                }
            }
        }
        return deep;
    }
};