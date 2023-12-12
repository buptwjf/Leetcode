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

/*
 * 思路：使用层序遍历，序列化和反序列化二叉树
 * */

/*
 * 这里序列化和反序列化的格式不做要求，只要满足转换关系就行，如：
 * 输入：root = [1,2,3,null,null,4,5]
 * 输出：[1,2,3,null,null,4,5]
 * */
class Codec {
  public:
    // Encodes a tree to a single string.
    /* 使用先序遍历将二叉树序列化和反序列化
     */

    queue<std::string> result;

    string serialize(TreeNode *root) {
        string res;
        if (root == nullptr) {
            return "#,";
        }
        res += to_string(root->val);
        res += ',';
        // cout << res << " - " << endl;
        res += serialize(root->left);
        // cout << res << " - " << endl;
        res += serialize(root->right);
        // cout << "*******" << endl;
        cout << res << endl;
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data) {
        if (data.empty()) {
            return nullptr;
        }
        // 使用 std::istringstream 或 std::stringstream 来进行拆分
        istringstream ss(data);
        // 用 ',' 作为分隔符
        string token;

        while (std::getline(ss, token, ',')) {
            result.push(token);
        }

        // 生成根节点
        string rootVal = result.front();
        if(rootVal == "#"){
            return nullptr;
        }
        TreeNode *root = new TreeNode(stoi(rootVal));
        result.pop();

        buildTree(root);
        return root;
    }

    void buildTree(TreeNode *root) {
        // 递归终止条件
        if (result.empty() || root == nullptr) {
            return;
        }
        string leftVal = result.front();
        result.pop();
        if (leftVal != "#") {
            // cout << leftVal << endl;
            root->left = new TreeNode(stoi(leftVal));
            buildTree(root->left);
        } else {
            root->left = nullptr;
        }

        string rightVal = result.front();
        result.pop();
        if (rightVal != "#") {
            // cout << rightVal << endl;
            root->right = new TreeNode(stoi(rightVal));
            buildTree(root->right);
        } else {
            root->right = nullptr;
        }
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end
