//
// Created by 86188 on 2023/7/19.
//

#include "../include/user.h"

using namespace std;

/*
 * 问题：判断一个二叉树是不是对称的
 * 思路：采用递归法，采用先序遍历
 * */
class Solution {
public:
    bool compare(TreeNode *left, TreeNode *right) {
        if (left == nullptr && right == nullptr) {
            return true;
        } else if (left == nullptr && right != nullptr) {
            return false;
        } else if (left != nullptr && right == nullptr) {
            return false;
        } else if (left->val != right->val) {
            return false;
        } else {
            return compare(left->left, right->right) && compare(left->right, right->left);
        }
    }

    bool isSymmetric(TreeNode *root) {
        if (!root) {
            return true;
        }
        return compare(root->left, root->right);
    }
};