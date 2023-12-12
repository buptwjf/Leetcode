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
    /* 层序遍历的思路：将根节点入队，然后将队首节点出队，然后他的左右孩子分别入队
     */
    string serialize(TreeNode *root) {
        string res;
        queue<TreeNode *> q;
        if (!root) {
            return "[]";
        }
        q.push(root);
        res += "[";
        while (!q.empty()) {
            TreeNode *cur = q.front();
            q.pop();
            if (cur == nullptr) {
                res += "null";
            } else {
                res += to_string(cur->val);
                q.push(cur->left);
                q.push(cur->right);
            }
            res += ",";
        }
        // 对 string 1,2,3,-1,-1,4,5,-1,-1,-1,-1, 进行处理
        while ("null," == string(res.end() - 5, res.end())) { // null, 长度为 5
            res.erase(res.size() - 6, 5);
        }
        res += "]";
        cout << res << endl;
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data) {
        data = data.substr(1, data.size() - 2);
        if (data.empty()) {
            return nullptr;
        }

        // 使用 std::istringstream 或 std::stringstream 来进行拆分
        istringstream ss(data);

        // 用 ',' 作为分隔符
        queue<std::string> result;
        string token;

        while (std::getline(ss, token, ',')) {
            result.push(token);
            // cout << token << "-";
        }
        // cout << endl;

        string TreeNodeVal = result.front();

        TreeNode *root = new TreeNode(stoi(TreeNodeVal));
        // cout << "root->val : " << root->val << endl;
        result.pop();

        // 父节点的队列
        queue<TreeNode *> q;
        q.push(root);
        while (!result.empty()) {
            TreeNode *cur = q.front();
            q.pop();

            // 从队列中取出左子树的值
            if (result.front() != "null") {
                cur->left = new TreeNode(stoi(result.front()));
                q.push(cur->left);
            } else {
                cur->left = nullptr;
            }
            result.pop();

            if (!result.empty()) {
                // 从队列中取出右子树的值
                if (result.front() != "null") {
                    cur->right = new TreeNode(stoi(result.front()));
                    q.push(cur->right);
                } else {
                    cur->right = nullptr;
                }
                result.pop();
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end
