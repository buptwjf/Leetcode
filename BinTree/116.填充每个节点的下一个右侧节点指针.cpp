/*
 * @lc app=leetcode.cn id=116 lang=cpp
 *
 * [116] 填充每个节点的下一个右侧节点指针
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/


/*
 * 给定一个 完美二叉树 ，其所有叶子节点都在同一层，每个父节点都有两个子节点。二叉树定义如下：
    struct Node {
        int val;
        Node *left;
        Node *right;
        Node *next;
    }
填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL。
 *
*/
#include "../0_offer2/include/user.h"

using namespace std;
/*
 * 将一个节点的左右孩子看成一个节点, 这样完全二叉树就是一个三叉树，对三叉树进行遍历
*/
class Solution {
public:
    Node *connect(Node *root) {
        if (!root) {
            return nullptr;
        }
        traversal(root->left, root->right);
        return root;
    }

    void traversal(Node *left, Node *right) { // 将 left 和 right 看成一个节点
        if (!left || !right) {
            return;
        }
        left->next = right; // 完成连接
        // 对三叉树进行遍历
        traversal(left->left, left->right);
        traversal(right->left, right->right);
        traversal(left->right, right->left);
    }
};
// @lc code=end

