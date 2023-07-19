//
// Created by 86188 on 2023/7/19.
//

/*
 * 问题：输出一个已知二叉树的镜像
 * 思路：采用递归法：使用先序遍历
 * */

#include "../include/user.h"

using namespace std;

class Solution {
public:
    TreeNode *mirrorTree(TreeNode *root) {
        traversal(root);
        return root;
    }

    void traversal(TreeNode *cur) {
        if (cur == nullptr) {
            return;
        }
        TreeNode *tmp = cur->left;
        cur->left = cur->right;
        cur->right = tmp;
        traversal(cur->left);
        traversal(cur->right);
    }
};