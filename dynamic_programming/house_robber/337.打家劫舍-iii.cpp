/*
 * @lc app=leetcode.cn id=337 lang=cpp
 *
 * [337] 打家劫舍 III
 */

// @lc code=start

//struct TreeNode {
//    int val;
//    TreeNode *left;
//    TreeNode *right;
//
//    TreeNode() : val(0), left(nullptr), right(nullptr) {}
//
//    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//
//    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//};

#include <vector>

using namespace std;
/*
 *            3
 *         2    3
 *      null 3 null  1
 * */
class Solution {
private:
    vector<int> dp(TreeNode *root) {
        if (root == nullptr) {
            return {0, 0};
        }
        vector<int> left = dp(root->left);
        vector<int> right = dp(root->right);

        int rob_it = root->val + left[1] + right[1];
        int not_rob = max(left[0], left[1]) + max(right[0], right[1]);
        cout << root->val << "->" <<  "{" << rob_it << ", "<< not_rob << "}\n";
        return {rob_it, not_rob};
    }

public:
    int rob(TreeNode *root) {
        vector<int> result = dp(root);
        return max(result[0], result[1]);
    }
};
// @lc code=end

