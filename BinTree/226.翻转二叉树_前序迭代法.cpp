/*
 * @lc app=leetcode.cn id=226 lang=cpp
 *
 * [226] 翻转二叉树
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
    翻转二叉树的思路
        采用前序或后序遍历，同时交换左右节点
*/

// 采用后续遍历的递归法
class Solution {
  public:
    TreeNode *invertTree(TreeNode *root) {
        // 创建结果数组
        vector<int> result;
        if (root == nullptr) {
            return root;
        }
        // 建立辅助栈
        stack<TreeNode *> st;
        st.push(root);
        while (!st.empty()) {
            TreeNode *cur = st.top();
            swap(cur->left, cur->right);
            st.pop();
            if (cur->right) {
                st.push(cur->right);
            }
            if (cur->left) {
                st.push(cur->left);
            }
        }
        return root;
    }
};

// @lc code=end
