/*
 * @lc app=leetcode.cn id=450 lang=cpp
 *
 * [450] 删除二叉搜索树中的节点
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

/*
    二叉搜索树的删除操作
    1. 找到这个节点的以及它的父节点
    2. 删除节点
        1. 如果这个节点是叶节点，删除内存，父节那个分支置空
        2.
   如果这个节点是父节点，可让它的左孩子（右孩子）代替它，然后它的父节点指向它的孩子

*/
// #include "BinTree.hpp"
#include <iostream>
using namespace std;

class Solution {
  public:
    TreeNode *deleteNode(TreeNode *root, int key) {
        // 对当前节点进行处理
        // 1. 情况一 当前节点为空
        if (root == nullptr) {
            return root;
        }
        if (root->val == key) {
            // 情况二：当前节点为叶子节点
            if (root->left == nullptr && root->right == nullptr) {
                delete root;
                return nullptr;
            }
            // 情况三：右孩子为空，左孩子不为空
            else if (root->left != nullptr && root->right == nullptr) {
                TreeNode *retNode = root->left;
                delete root;
                return retNode;
            }
            // 情况四：左孩子为空，右孩子不为空
            else if (root->left == nullptr && root->right != nullptr) {
                TreeNode *retNode = root->right;
                delete root;
                return retNode;
            } else { // 左右节点都为空
                TreeNode *cur = root->right;
                while (cur->left != nullptr) {
                    cur = cur->left;
                }
                cur->left = root->left;
                TreeNode *tmp = root;
                root = root->right;
                delete tmp;
                return root; // ???为什么要这么操作
            }
        }

        // 对左右子树进行处理
        if (root->val > key)
            root->left = deleteNode(root->left, key);
        if (root->val < key)
            root->right = deleteNode(root->right, key);
        return root;
    }
};
// @lc code=end
