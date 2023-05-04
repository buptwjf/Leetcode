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

/*
    思路：
        使用 递归 + 双指针

        递归顺序：中序，再 BST 中，一般都是采用中序遍历
        双指针: pre 和 cur

        使用 递归+双指针 感觉不是很清楚，但是
*/
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {

  private:
    int result = INT_MAX;
    TreeNode *pre = NULL; // 从根节点开始

    void traversalIn(TreeNode *cur) {
        // 递归终止条件
        if (cur == nullptr) {
            return;
        }
        traversalIn(cur->left);
        if (pre != nullptr) {
            result = min(result, cur->val - pre->val);
        }
        pre = cur; // 记录前一个
        traversalIn(cur->right);
    }

  public:
    int getMinimumDifference(TreeNode *root) {
        traversalIn(root);
        return result;
    }


};
// @lc code=end
