/*
 * @lc app=leetcode.cn id=501 lang=cpp
 *
 * [501] 二叉搜索树中的众数
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
    二叉搜索树中的众数

    思路：
        1.
   由于二叉树是有序的，所有只要比较前一个和后一个是否相同，因此采用中序遍历
        2. 由于众数可能有多个，因此当 count > Maxcount 的时候，就要将 result
   中的全部删除
        3. 比较前后的时候采用双指针
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {

  private:
    TreeNode *pre = nullptr;
    int maxCount = 0;
    int count = 0;

    void traversal(TreeNode *cur, vector<int> &result) {
        if (cur) {
            return;
        }
        traversal(cur->left, result);
        if (pre == nullptr) {
            count = 1; // 第一个节点
        } else {
            if (cur->val == pre->val) {
                count++;
            } else {
                count = 1;
            }

            if (count == maxCount) {
                result.push_back(cur->val);
            }
            if (count > maxCount) {
                result.clear();
                cout << "update" << endl;
                result.push_back(cur->val);
            }
        }

        pre = cur;
        traversal(cur->right, result);
    }

  public:
    vector<int> findMode(TreeNode *root) {
        vector<int> result;
        traversal(root, result);
        cout << result.size() << endl;
        return result;
    }
};
// @lc code=end
