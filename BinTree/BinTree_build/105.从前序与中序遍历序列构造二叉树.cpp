/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
 */
#include "../../include/user.h"
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
using namespace std;

/*
 * 思路：采用递归的方法，建立一个子树
 * rootInorderIndex 其实就是左子树的长度 ！！！！
 * 通过这样可以划分 前序序列 和 中序序列中的各个部分
 * */

class Solution {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        return build(preorder, inorder);
    }

    TreeNode *build(vector<int> &preorder, vector<int> &inorder) {
        if (preorder.empty()) {
            return nullptr;
        }
        // 前序遍历的第一个点是根节点
        TreeNode *root = new TreeNode(preorder[0]);
        int rootVal = preorder[0];

        // root节点在中序遍历之前的值，他在前序遍历的后一个是右孩子
        int rootInorderIndex = 0; // 中序中根节点的位置

        // 找到 根节点 在中序遍历的位置
        for (int i = 1; i < inorder.size(); i++) {
            if (inorder[i] == rootVal) {
                rootInorderIndex = i; // （可能 = 0）
                break;
            }
        }

        // rootInorderIndex 其实就是左子树的长度 ！！！！
        vector<int> leftPreorder = vector(preorder.begin() + 1, preorder.begin() + rootInorderIndex + 1);
        vector<int> leftInorder = vector(inorder.begin(), inorder.begin() + rootInorderIndex);
        root->left = buildTree(leftPreorder, leftInorder);

        vector<int> rightPreorder = vector(preorder.begin() + rootInorderIndex + 1, preorder.end());
        vector<int> rightInorder = vector(inorder.begin() + rootInorderIndex + 1, inorder.end());
        root->right = buildTree(rightPreorder, rightInorder);


        return root;
    }
};
// @lc code=end

