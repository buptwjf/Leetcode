/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] 将有序数组转换为二叉搜索树
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
    将有序数组转化为平衡二叉树

    你对数组进行平均分，想要不平衡很难
*/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
  public:
    TreeNode *sortedArrayToBST(vector<int> &nums) {
        cout << "---" << endl;
        TreeNode *root;
        root = traversal(nums);
        return root;
    }

    TreeNode *traversal(vector<int> nums) {
        if (nums.empty()) {
            return nullptr;
        }
        cout << "---" << endl;
        TreeNode*cur = new TreeNode(nums[nums.size() / 2]);
        cout << "---" << endl;

        cout << cur->val << endl;
        vector<int> leftnum(nums.begin(), nums.begin() + (nums.size() / 2));
        cur->left = traversal(leftnum);
        vector<int> rightnum(nums.begin() + (nums.size() / 2 + 1), nums.end());

        cur->right = traversal(rightnum);
        return cur;
    }
};
// @lc code=end
