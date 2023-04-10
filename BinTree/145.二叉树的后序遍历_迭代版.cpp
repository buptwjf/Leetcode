/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
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
    后序迭代有一个很简单的方法，就是把
        前序的左右子树入栈写反
        再把 result 写反
*/

#include <algorithm>
#include <stack>
#include <vector>
using namespace std;
class Solution {
  public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> result;
        stack<TreeNode *> st;

        if (root == nullptr) {
            return result;
        }

        st.push(root);
        while (!st.empty()) {
            // 访问栈顶元素
            TreeNode *cur = st.top();
            st.pop();
            result.push_back(cur->val);
            // 右节点入栈
            if (cur->left) {
                st.push(cur->left);
            }
            if (cur->right) {
                st.push(cur->right);
            }
        }

        reverse(result.begin(), result.end());
        return result;
    }
};
// @lc code=end
