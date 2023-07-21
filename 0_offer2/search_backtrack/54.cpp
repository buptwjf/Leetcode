//
// Created by 86188 on 2023/7/21.
//

#include "../include/user.h"

using namespace std;

/*
 * 问题：找出二叉搜索树中第 K 大的数
 * 思路：中序遍历，先遍历右子树，再遍历左子树
 * */
class Solution {
private:
    int k_value;
    int count;
public:
    int kthLargest(TreeNode *root, int k) {
        if (root == nullptr) {
            return -1;
        }
        count = k;
        traversal(root);
        return k_value;
    }

    void traversal(TreeNode *cur) {
        if (cur == nullptr) {
            return;
        }
        traversal(cur->right);
        count--;
        if (count == 0) {
            k_value = cur->val;
            return; // 找到之后立即返回
        }
        traversal(cur->left);
    }
};