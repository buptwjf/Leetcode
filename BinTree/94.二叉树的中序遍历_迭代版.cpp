/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
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
#include <stack>
#include <vector>
using namespace std;
/*
    中序遍历的迭代版
    关键：
        每个元素入栈时候，一直入到他的所有左孩子，直到左孩子为空
        这时候弹出栈顶元素，然后并访问
        每个元素出栈的时候，他的右孩子入栈
*/
class Solution {
  public:
    void pushAlongeLeftBranch_In(TreeNode *cur, stack<TreeNode *> &st) {
        while (cur) {
            st.push(cur);
            cur = cur->left;
        }
    }

    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> result;

        stack<TreeNode *> st;

        TreeNode *cur = root;
        while (true) {
            pushAlongeLeftBranch_In(cur, st);
            if (st.empty()) {
                break;
            }
            cur = st.top();
            st.pop();
            result.push_back(cur->val);
            cur = cur->right;
        }
        return result;
    }
};
// @lc code=end
