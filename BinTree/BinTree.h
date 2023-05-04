#include "TreeNode.h"
#include "queue"
#include <vector>
using namespace std;
#include <iostream>

class BinTree {
  public:
    TreeNode *_root;
    BinTree(queue<int> nums);
    ~BinTree();
    void showBinTree() const;
};

TreeNode *taversalGetBinTree(queue<int> &nums) {
    if (nums.empty()) {
        return nullptr;
    }

    if (nums.front() == 0) {
        return nullptr;
    }
    TreeNode *root = new TreeNode();
    root->val = nums.front();
    nums.pop();

    root->left = taversalGetBinTree(nums);
    root->left = taversalGetBinTree(nums);
    return root;
}

inline void BinTree::showBinTree() const {
    // 进行层序遍历，输出节点
    queue<TreeNode *> q;
    TreeNode *cur = _root;
    if (cur == nullptr) {
        std::cout << "BinTree is NULL" << endl;
    }
    q.push(cur);
    while (!q.empty()) {
        TreeNode *cur = q.front();
        std::cout << "-val" << cur->val << "-";
        q.pop();
        if (cur->left) {
            q.push(cur->left);
        }
        if (cur->right) {
            q.push(cur->right);
        }
    }
}

inline BinTree::BinTree(queue<int> nums) { _root = taversalGetBinTree(nums); }

BinTree::~BinTree() {}
