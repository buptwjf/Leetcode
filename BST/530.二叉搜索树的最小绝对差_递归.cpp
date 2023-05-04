/*
 * @lc app=leetcode.cn id=530 lang=cpp
 *
 * [530] 二叉搜索树的最小绝对差
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
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
  public:
    int getMinimumDifference(TreeNode *root) {
        vector<int> result;
        traversalIn(root, result);
        for (auto i : result) {
            cout << i << " ";
        }
        cout << endl;

        int minDiff = result[1]-result[0];
        for (int i = 0; i < result.size() - 1; i++) {
            int curDiff = result[i + 1] - result[i];
            minDiff = minDiff < curDiff ? minDiff : curDiff;
        }
        return minDiff;
    }

    void traversalIn(TreeNode *root, vector<int> &result) {
        stack<TreeNode *> st;

        if (!root) {
            return;
        }
        while (true) {
            while (root) {
                st.push(root);
                root = root->left;
            }
            if (st.empty()) {
                break;
            }
            // int val = st.top()->val; ???迭代器不能这么使用？
            root = st.top();
            result.push_back(root->val);
            st.pop();
            root = root->right;
        }
    }
};
// @lc code=end
