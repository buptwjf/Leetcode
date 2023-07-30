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

#include "../0_offer2/include/user.h"

using namespace std;

class Solution {
public:
    Node *connect(Node *root) {
        if (!root) {
            return nullptr;
        }
        traversal(root->left, root->right);
        return rootl
    }

    void traversal(Node *left, Node *right) {
        if (!left || !right) {
            return;
        }
        left->next = right;
        traversal(left->left, left->right);
        traversal(right->left, right->right);
        traversal(left->right, right->left);


    }
};
// @lc code=end

