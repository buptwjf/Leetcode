//
// Created by 86188 on 2023/12/7.
//
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

#include "../0_offer2/include/user.h"

using namespace std;

// 按顺序返回二叉树的叶子节点
/*
 *  第一次返回所有叶子节点，并从二叉树上删除
 *  第二次返回剩下二叉树的叶子节点，并从二叉树上删除
 *  ......
 *  最终删除根节点
 * */

/*
 * 思路：
 * 1. 先删除的是二叉树上高度为 0 的节点
 * 2. 遍历二叉树，将所有的节点的高度和值存储为 map<int, int>
 * 3. 从小到大访问 map
 * */
#include <map>

class Solution {
public:
    vector<vector<int>> res;
    multimap<int, int> m;
    int maxHeight;

    // 后序遍历整个树，将每个节点的高度和值 作为 pair 存储起来
    int getHeight(TreeNode *root) {
        if (!root) {
            return -1;
        }
        int left = getHeight(root->left);
        int right = getHeight(root->right);
        int cur = max(left, right) + 1;

        maxHeight = max(maxHeight, cur);

        m.insert(make_pair(cur, root->val));
        return cur;
    }

    vector<vector<int>> findLeaves(TreeNode *root) {
        res.clear();
        m.clear();
        maxHeight = -1;
        getHeight(root);
        cout << maxHeight << endl;
        for (int height = 0; height <= maxHeight; height++) {
            auto range = m.equal_range(height); // multi_map 的方法
            // 插入所有结果
            vector<int> v;
            for (auto it = range.first; it != range.second; ++it) {
                v.emplace_back(it->second);
            }
            res.emplace_back(v);
        }
        return res;
    }
};