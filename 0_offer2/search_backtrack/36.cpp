//
// Created by 86188 on 2023/7/21.
//


#include "../include/user.h"

using namespace std;

/*
 * 问题：将一个二叉搜素树，转换成双向列表
 * 思路：
 *      1. 对二叉搜索树进行中序遍历
 *      2. 每次回溯得时候，当前节点指向他回溯后得节点
 * */

class Solution {
private:
    Node *pre;
    Node *head;
public:
    Node *treeToDoublyList(Node *root) {
        traversal(root);
        // 再把首尾连起来
        head->left = pre;
        pre->right = head;
        return head;
    }

    void traversal(Node *cur) {
        if (cur == nullptr) {
            return;
        }
        traversal(cur->left);
        if (pre) {
            pre->right = cur; // 前一个节点指向当前
        } else {
            head = cur; // 最左下角的节点就是第一个节点
        }
        cur->left = pre; // 当前节点指向前一个节点
        pre = cur;
        traversal(cur->right);
    }
};