/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
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
  路径总和 递归 + 回溯
  1. 递归
    a. 递归顺序
    b. 递归终止条件
  2. 回溯
    a. 回溯和递归在一起
*/
class Solution {
  public:
    bool hasPathSum(TreeNode *root, int targetSum) {
        int count = targetSum;
        if (!root) {
            return false;
        }
        count -= root->val;
        return traversal(root, count);
    }

  private:
    bool traversal(TreeNode *cur, int &count) {
        // 递归停止条件
        // 到达叶子节点，并且总和为 targetSum
        if (!cur->left && !cur->right && count == 0) {
            return true;
        }
        if (!cur->left && !cur->right) {
            return false;
        }

        // 递归入口
        if (cur->left) { // 对左子树递归
            count -= cur->left->val;
            if (traversal(cur->left, count)) {
                return true; // 如果成功，直接返回
            } else {
                count += cur->left->val; // 否则要进行回溯，切换到右子树
            }
        }
        if (cur->right) { // 对右子树递归
            count -= cur->right->val;
            if (traversal(cur->right, count)) {
                return true; // 如果成功直接返回
            } else {
                count += cur->right->val; // 否则要进行回溯，切换到右子树
            }
        }

        return false;
    }
};
// @lc code=end
