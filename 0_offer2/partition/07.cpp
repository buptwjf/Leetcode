//
// Created by 86188 on 2023/7/30.
//
#include "../include/user.h"
#include "algorithm"

using namespace std;

/*
 * 问题：利用前序遍历和中序遍历构造二叉树
 * 思路：分治算法
 *
 * */


class Solution {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if (preorder.empty()) {
            return nullptr;
        }
        int rootVal = preorder.front();
        TreeNode *root = new TreeNode(rootVal);
        buildNode(root, preorder, inorder, 0, preorder.size());
        return root;
    }

    void buildNode(TreeNode *cur, vector<int> &preorder, vector<int> &inorder, int begin, int end) {
        if (!cur || end - begin == 1) {
            return;
        }
        int left1 = begin;
        int left2 = 0;
        int right1 = 0;
        int right2 = end;
        // 在中序遍历中找到他的左子树和右子树的范围
        for (; left2 < end; left2++) {
            if (inorder[left2] == cur->val) {
                break;
            }
        }
        right1 = min(left2 + 1, end); // right1 不能超过 end
        right2 = end;

        // 在前序遍历中找到左孩子和右孩子
        int leftChildVal = 0;
        int rightChildVal = 0;
        if (left2 > left1) { // 如果有左子树
            // 左孩子就是前序遍历中 cur 后面的一个
            cur->left = new TreeNode(*(find(preorder.begin(), preorder.end(), cur->val) + 1));
            buildNode(cur->left, preorder, inorder, left1, left2);
        }
        if (right2 > right1) { // 如果有右子树
            if (right2 - right1 == 1) {
                cur->right = new TreeNode(inorder[right1]);
                return;
            } else {
                if (left2 > left1) { // 有左子树
                    // 在前序遍历中 找到 Inorder(left2) 后面的那个值 ?  不一定吧？
//                    [3,2,1,4,5]
//                    [1,2,3,4,5]
//                    应该是属于在前序遍历中，所有左子树的点后面的一个。


                    for (int i = 0; i < preorder.size(); i++) {
                        if (preorder[i] == inorder[left2 -1]) {
                            rightChildVal = preorder[i + 1];
                            break;
                        }
                    }
                } else { // 没有左子树
                    // 在 preorder 找到 cur 后面的就是右子树
                    rightChildVal = *(find(preorder.begin(), preorder.end(), cur->val) + 1);
                }

            }
            cur->right = new TreeNode(rightChildVal);
            buildNode(cur->right, preorder, inorder, right1, right2);
        }
    }
};

int main() {
//    vector<int> preOrder = {3, 9, 20, 15, 7};
//    vector<int> inOrder = {9, 3, 15, 20, 7};
//    vector<int> preOrder = {1, 2, 3};
//    vector<int> inOrder = {1, 2, 3};
    vector<int> preOrder = {3, 2, 1, 4, 5};
    vector<int> inOrder = {1, 2, 3, 4, 5};
    Solution s;
    TreeNode *root = s.buildTree(preOrder, inOrder);

    return 0;
}