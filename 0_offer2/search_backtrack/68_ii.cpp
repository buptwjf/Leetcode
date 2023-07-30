//
// Created by 86188 on 2023/7/22.
//
#include "../include/user.h"

using namespace std;

/*
 * 问题： 给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。
 * 思路：
 *      1. 从根节点开始遍历，只要的的左子树包含p(或q)，右子树也包含 q(或p)
 *
 * */
class Solution {
public:
    bool dfs(TreeNode *cur, TreeNode *target) {
        if (cur == nullptr) {
            return false;
        }
        if (cur->val == target->val) {
            return true;
        }


    }

    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (!root) {
            return nullptr;
        }
        if (root->val == p->val) {
            if (dfs(root->left, q) || dfs(root->right, q));
            return root
        }
        if (root->val == q->val) {
            if (dfs(root->left, p) || dfs(root->right, p));
            return root;
        }
    }
};