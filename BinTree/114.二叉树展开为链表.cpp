/*
 * @lc app=leetcode.cn id=114 lang=cpp
 *
 * [114] 二叉树展开为链表
 */
#include "../0_offer2/include/user.h"

using namespace std;
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

/* 将二叉树，按照前序遍历的方式生成一个链表
 * 问题：要求不占用额外空间，在原地改变每个节点的指针
 * 思路：分解为子问题，采用递归法
 * 1. 对于一个三个节点的二叉树，先把左孩子展平，在把右孩子展平
 * 2. 再把左右孩子一次连接到父节点上
 * */

class Solution {
public:
    void flatten(TreeNode *root) {
        if (!root) {
            return;
        }
        flatten(root->left);
        flatten(root->right);

        TreeNode *left = root->left;
        TreeNode *right = root->right;

        root->left = nullptr;
        root->right = left;

        TreeNode *p = root;
        // 找到展开的左子树的最后一个节点
        while (p->right != nullptr) {
            p = p->right;
        }
        p->right = right;
    }
};
// @lc code=end

