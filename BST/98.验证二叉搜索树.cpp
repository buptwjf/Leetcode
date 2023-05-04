/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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
        1. 先将整个树遍历，然后存入一个 vector
        2. 再判断左右子树是否满足
*/

#include <iostream>
#include <vector>
using namespace std;
class Solution {
  public:
    bool isValidBST(TreeNode *root) {
        vector<int> result;
        traversal(root, result);
        cout << "over " << endl;
        cout << result.size() << endl;
        for (int i = 0; i < result.size() - 1; i++) {
            if (result[i] >= result[i + 1]) {
                return false;
            }
        }
        return true;
    }

    void traversal(TreeNode *cur, vector<int> &result) {
        if (!cur) {
            return;
        }
        if (cur->left)
            traversal(cur->left, result);
        result.push_back(cur->val);
        if (cur->right)
            traversal(cur->right, result);
        return;
    }
};
// @lc code=end
