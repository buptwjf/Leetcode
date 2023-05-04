//
// Created by 86188 on 2023/4/26.
//

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *leftChild, TreeNode *rightChild) : val(x), left(leftChild), right(rightChild) {}
};


#include <vector>
#include <queue>
#include <iostream>

namespace test01 {

    /*
     * 通过一个 vector 构造一个树
     */
    TreeNode *creatBinTreeByVector(std::vector<int> vec) {
        if (vec.empty()) {
            return nullptr;
        }
        std::vector < TreeNode * > vecTree;
        for (auto i: vec) {
            TreeNode *cur = new TreeNode(i);
            vecTree.push_back(cur);
        }
        for (int i = 0; 2 * i + 2 < vec.size(); i++) {
            vecTree[i]->left = vecTree[2 * i + 1];
            vecTree[i]->right = vecTree[2 * (i + 1)];
        }
        return vecTree[0];
    }

    void showBytraversalLevel(TreeNode *root) {
        std::queue < TreeNode * > q;
        TreeNode *cur = root;
        q.push(root);

        while (!q.empty()) {
            TreeNode *tmp = q.front();
            std::cout << tmp->val << " ";
            q.pop();
            if (tmp->left) {
                q.push(tmp->left);
            }
            if (tmp->right) {
                q.push(tmp->right);
            }
        }
        std::cout << std::endl;
    }
}


int main() {
    std::vector<int> v = {1, 1, 3, 4, 5};
    TreeNode* root = test01::creatBinTreeByVector(v);
    test01::showBytraversalLevel(root);
    return 0;
}


