//
// Created by 86188 on 2023/7/22.
//
#include "../include/user.h"

using namespace std;

/*
 * 问题：给定一个二叉搜索树，找到指定两节点的公共祖先
 * 分析：由于 BST 的自身固有属性，所以公共祖先一定满足
 *         p < res < q
 * */

class Solution {
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        while (true) {
            if (root == nullptr) {
                return nullptr;
            }
            if ((root->val - p->val) * (root->val - q->val) <= 0) {
                return root;
            } else if (root->val > p->val && root->val > q->val) {
                root = root->left;
            } else {
                root = root->right;
            }
        }
    }
};