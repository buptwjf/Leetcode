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
        找不到：
            a. 如果此树为空，则返回空
            b. 如果 key 不存在，则返回
        找到
            1. 如果这个节点是叶节点，删除内存，父节那个分支置空
            2. 如果这个节点是根节点，
                1. 没有左右孩子，直接删除它，并返回空
                2. 有右孩子，没有左孩子，右孩子代替它
                3. 有左孩子，没有右孩子，左孩子代替它
                4.
   左右孩子都有，右孩子代替它，然后左子树接到右孩子的最左边的位置

                返回右孩子作为根节点

            3. 如果这个节点有父节点
                1. 没有左右孩子，直接删除它，并返回空
                2. 有右孩子，没有左孩子，右孩子代替它
                3. 有左孩子，没有右孩子，左孩子代替它
                4.
   左右孩子都有，右孩子代替它，然后左子树接到右孩子的最左边的位置

                返回根节点

*/
// #include "BinTree.hpp"
#include <iostream>
using namespace std;

class Solution {
  public:
    TreeNode *deleteNode(TreeNode *root, int key) {
        TreeNode *parent = nullptr;
        TreeNode *cur = root;

        // 没找到的情况
        // 情况 1， 树为空
        if (cur == nullptr) {
            return root;
        }
        // 得到 cur 和 parent

        bool flag = false;
        while (!flag) {
            if (cur->val == key) {
                flag = true;
            } else if (cur->val < key) {
                parent = cur;
                cur = cur->right;
            } else {
                parent = cur;
                cur = cur->left;
            }
        }

        // 情况 2
        if (flag == false) {
            return root;
        }
        cout << "parent->val = " << parent->val << endl;
        cout << "parent->left->val = " << parent->left->val << endl;
        cout << "parent->left = " << parent->left << endl;

        cout << "cur->val = " << cur->val << endl;
        cout << "cur = " << cur << endl;

        // 1. 当前节点是叶子节点
        if (!cur->left && !cur->right && parent) {
            if (cur->val < parent->val) {
                parent->left = nullptr;
            } else {
                parent->right = nullptr;
            }
            delete cur;
            cout << "--1--" << endl;
            return root;
        }
        // 2. 当前节点是根节点
        else if (parent == nullptr) {
            if (!cur->left && !cur->right) {
                delete cur;
                return nullptr;
            } else if (cur->left && !cur->right) {
                TreeNode *newRoot = cur->left;
                delete cur;
                return newRoot;
            } else if (!cur->left && cur->right) {
                TreeNode *newRoot = cur->right;
                delete cur;
                return newRoot;
            } else {
                TreeNode *minInRight = cur->right; // 找右子树最左面的节点
                while (minInRight != nullptr) {
                    minInRight = minInRight->left;
                }
                minInRight->left = cur->left;
                TreeNode *newRoot = cur->right;
                delete cur;
                return newRoot;

                TreeNode *tmp = cur;
                cur = cur->right;
                delete tmp;
                return newRoot;
            }
        } else { // cur 有父节点
            if (!cur->left && !cur->right) {
                delete cur;
                return root;
            } else if (cur->left && !cur->right) {
                TreeNode *tmp = cur;
                cout << tmp << endl;
                cur = cur->left;
                delete tmp;
                return root;
            } else if (!cur->left && cur->right) {
                TreeNode *tmp = cur;
                cout << tmp << endl;
                cur = cur->right;
                // delete tmp;
                return root;
            } else {
                TreeNode *minInRight = cur->right; // 找右子树最左面的节点
                while (minInRight != nullptr) {
                    minInRight = minInRight->left;
                }
                minInRight->left = cur->left;
                TreeNode *tmp = cur;
                cur = cur->right;
                // delete tmp;
                return root;
            }
        }
    }
};
// @lc code=end
