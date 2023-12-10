/*
 * @lc app=leetcode.cn id=652 lang=cpp
 *
 * [652] 寻找重复的子树
 */

#include "../include/user.h"

using namespace std;
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

/* 问题：寻找重复的子树 */
/* 思路：
 * 1. 要找到自己为根的子树长啥样，以及以其他节点为根的子树长啥样
 * 2. 将所有的子树序列化，然后存入 map<string, int> 容器中
 * 3. 由于不同的规则有很多种序列化方法，此题由于是后序遍历，我们定义 左子树 + 右子树 + 根节点*/


class Solution {
private:
    vector<TreeNode *> res;
    map<string, int> childTree;
public:
    vector<TreeNode *> findDuplicateSubtrees(TreeNode *root) {
        res.clear();
        childTree.clear();
        serialize(root);
        return res;
    }

    string serialize(TreeNode *root) {
        if (!root) {
            return "#";
        }
        string left = serialize(root->left);
        string right = serialize(root->right);

        // 该节点序列化完成
        string rootString = left + "," + right + "," + to_string(root->val);

        // 该子树已经存在至少一个，那么将该子树的根节点加入结果集合中
        if (childTree[rootString] == 1) {
            res.emplace_back(root);
            childTree[rootString]++;
        } else {
            childTree[rootString]++;
        }
        return rootString;
    }
};
// @lc code=end

