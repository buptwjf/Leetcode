//
// Created by 86188 on 2023/7/22.
//


#include "../include/user.h"

using namespace std;

/*
 * 问题：判断一个二叉树是否是平衡二叉树
 * 思路：
 *      1. 肯定要进行 dfs
 *      2. 一个节点作为根节点的子树是平衡二叉树的充要条件：
 *          1. 自身左子树和右子树的高度差小于 1
 *          2. 左子树和右子树都是平衡二叉树
 * */
class Solution {
public:
    bool bfs(TreeNode *cur) {
        if (cur == nullptr) {
            return true;
        }
        int leftDepth = getDepth(cur->left);
        int rightDepth = getDepth(cur->right);
        if (abs(leftDepth - rightDepth) > 1 || !bfs(cur->left) || !bfs(cur->right)) {
            return false;
        }
        return true;
    }

    int getDepth(TreeNode *cur) {
        if (cur == nullptr) {
            return 0;
        } else {
            return max(getDepth(cur->left), getDepth(cur->right));
        }
    }

    bool isBalanced(TreeNode *root) {
        return bfs(root);
    }
};