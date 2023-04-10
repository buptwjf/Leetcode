/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
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
    二叉树的层序遍历思路

    思路：
        创建辅助队列
        当前节点入队
        左右子树也入队
*/

#include <queue>
#include <vector>
using namespace std;

class Solution {
  public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        // 创建辅助队列
        queue<TreeNode *> q;
        vector<vector<int>> result;
        if (!root) {
            return result;
        }

        q.push(root);
        // 元素入栈
        while (!q.empty()) {

            // 在最开始的时候记录一下当前队列里元素的数量
            int size = q.size(); // 1, 2, 4
            vector<int> v;
            for (int i = 0; i < size; i++) {
                TreeNode *cur = q.front();
                q.pop();
                v.push_back(cur->val);
                if (cur->left) {
                    q.push(cur->left);
                }
                if (cur->right) {
                    q.push(cur->right);
                }
            }
            result.push_back(v);
        }
        return result;
    }
};
// @lc code=end
