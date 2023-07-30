//
// Created by 86188 on 2023/7/22.
//
#include "../include/user.h"

using namespace std;

/*
 * 问题：序列化和反序列化二叉树
 * 思路：
 * 1. 对二叉树进行层序遍历，进行序列化
 * 2. 利用完全二叉树的性质，进行反序列化
 *
 * */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode *root) {
        string res;
        queue<TreeNode *> q;
        if (root == nullptr) {
            return res;
        }
        q.push(root);

        // 采用层序遍历将二叉树转化为序列
        /*
         * 1. 将队头元素的 val 转化为string 加入 res
         * 2. 将队头元素的左孩子、右孩子入队
         * 3. 如果左右孩子为 nullptr 也要入队
         * 4. 如果队头元素为 nullptr, 则 res 加上 None
         * */
        while (!q.empty()) {
            TreeNode *tmp = q.front();
            if (tmp == nullptr) {
                res += ",";
                res += "None";
            } else {
                res += ",";
                res += to_string(tmp->val);
            }
            q.pop();

            // 这里不一样，如果 tmp 没有左孩子，那么也要往队列里加入 nullptr
            if (tmp != nullptr) {
                if (tmp->left) {
                    q.push(tmp->left);
                } else {
                    q.push(nullptr);
                }

                if (tmp->right) {
                    q.push(tmp->right);
                } else {
                    q.push(nullptr);
                }
            }
        }
        res = res.substr(1, res.size());
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data) {
        // 将 string 分解
        // 使用 list 避免频繁扩充空间
        string s;
        if (data.empty()) {
            return nullptr;
        }
        list<string> l;
        data += ',';
        for (auto ch: data) {
            if (ch != ',') {
                s += ch;
            } else {
                l.push_back(s);
                s.clear();
            }
        }
        // 通过层序遍历重建二叉树
        TreeNode *root = new TreeNode(stoi(l.front()));
        l.pop_front();
        // 用层序遍历重建二叉树
        /*
         * 1. 每次拿出队头的元素，然后从 列表中拿出2个元素作为他的左右孩子
         * 2. 拿出的 2 个元素依次入队
         * 3. 如果队头的元素为 nullptr，那么直接出队
         * */
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            while (q.front() == nullptr) {
                q.pop();
            }
            TreeNode *cur = q.front();
            if (l.front() == "None") {
                cur->left = nullptr;
            } else {
                TreeNode *left = new TreeNode(stoi(l.front()));
                q.push(left);
                cur->left = left;
            }
            l.pop_front();
            if (l.front() == "None") {
                cur->right = nullptr;
            } else {
                TreeNode *right = new TreeNode(stoi(l.front()));
                q.push(right);
                cur->right = right;
            }
            l.pop_front();
            q.pop();
        }
        return root;
    }
};


int main() {
    Codec C;
    TreeNode *a = new TreeNode(1);
    TreeNode *b = new TreeNode(2);
    TreeNode *c = new TreeNode(3);
    a->left = b;
    a->right = c;
//    cout << C.serialize(a) << endl;
    string s = "1,2,3,None,None,None,None";
    TreeNode *root = C.deserialize(s);
    cout << root->left->val;
    return 0;
}