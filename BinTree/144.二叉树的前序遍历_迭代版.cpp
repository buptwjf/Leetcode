/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
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
    思路：
        中间节点先入栈

        栈不为空时：
            访问栈顶节点
                -> 右孩子入栈
                -> 左孩子入栈
*/
#include <stack>
#include <vector>
using namespace std;
class Solution {
  public:
    vector<int> preorderTraversal(TreeNode *root) {
        // 创建结果数组
        vector<int> result;
        if (root == nullptr) {
            return result;
        }
        // 建立辅助栈
        stack<TreeNode *> st;
        st.push(root);
        while (!st.empty()) {
            TreeNode *cur = st.top();
            result.push_back(cur->val);
            st.pop();
            if (cur->right) {
                st.push(cur->right);
            }
            if (cur->left) {
                st.push(cur->left);
            }
        }
        return result;
    }
};
// @lc code=end
