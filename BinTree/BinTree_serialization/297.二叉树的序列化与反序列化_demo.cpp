/*
 * @lc app=leetcode.cn id=297 lang=cpp
 *
 * [297] 二叉树的序列化与反序列化
 */
#include "../../include/user.h"
#include <sstream>

using namespace std;
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/* 总的思路：采用 递归的思路 + 前序 */
class Codec {
  public:
    // Encodes a tree to a single string.
    string SEP = ",";
    string NULL_ = "#";

    /* 主函数，将二叉树序列化为字符串 */
    string serialize(TreeNode *root) {
        string str;
        serialize(root, str);
        return str;
    }

    /* 辅助函数，将二叉树存入 string */
    // 注意！加 SEP 的时机
    void serialize(TreeNode *root, string &str) {
        if (root == nullptr) {
            str += NULL_ + SEP;
            return;
        }

        /* 前序位置 */
        str += to_string(root->val) + SEP;

        serialize(root->left, str); // 这里不加
        serialize(root->right, str);
    }



    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data) {
        // 将字符串转化成列表
        cout << data << endl;
        vector<string> nodes;
        stringstream ssin(data);
        string val;
        while (getline(ssin, val, ','))
            nodes.push_back(val);
        reverse(nodes.begin(), nodes.end());
        return deserialize(nodes);
    }

    /* 辅助函数，通过 nodes 列表构造二叉树 */
    // 辅助函数这种写法可以借鉴
    TreeNode *deserialize(vector<string> &nodes) {
        if (nodes.empty())
            return nullptr;

        /****** 前序位置 ******/
        // 列表最左侧就是根节点
        string first = nodes.back();
        nodes.pop_back();
        if (first == "#")
            return nullptr;

        TreeNode *root = new TreeNode(stoi(first));

        /***********************/
        root->left = deserialize(nodes);
        root->right = deserialize(nodes);

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end
