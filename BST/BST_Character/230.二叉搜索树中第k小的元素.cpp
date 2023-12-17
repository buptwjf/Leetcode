
/*
 * @lc app=leetcode.cn id=230 lang=cpp
 *
 * [230] 二叉搜索树中第K小的元素
 */

#include "../../include/user.h"
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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
/* 思路：
    暴力遍历：
        1. 对 BST 进行中序遍历的递归法，然后在结果数组里找到第 K 个元素
        2. 对 BST 进行中序遍历的迭代法，这样可以找打答案后停止

    如果需要频繁进行该操作该怎么办？
    查找排名为 k 的元素，当前节点知道自己排名第 m，那么我可以比较 m 和 k
   的大小： 1、如果 m == k，显然就是找到了第 k 个元素，返回当前节点就行了。
    2、如果 k < m，那说明排名第 k 的元素在左子树，所以可以去左子树搜索第 k
   个元素。 3、如果 k > m，那说明排名第 k 的元素在右子树，所以可以去右子树搜索第
   k - m - 1 个元素。 这样就可以将时间复杂度降到 O(logN) 了。

    具体操作：
    1. 将每个 节点的孩子书存在树的节点中
    2. 利用 哈希表记录 unordered_map<TreeNode*, int>

    1. 如果 node 的左子树的结点数 left 小于k−1，则第 k 小的元素一定在 node的右子树中，令
        node 等于其的右子结点，k 等于 k−left−1，并继续搜索；
    2. 如果 node的左子树的结点数 left等于k−1，则第 kkk 小的元素即为 node，结束搜索并返回node 即可；
    3. 如果 node 的左子树的结点数 left 大于k−1，则第 k 小的元素一定在 node的左子树中,令
        nodenode 等于其左子结点，并继续搜索。
 */

class Solution {
  private:
    unordered_map<TreeNode *, int> nodeNum;

  public:
    int kthSmallest(TreeNode *root, int k) {
        getBstNum(root);
        cout << "get Tree num" << endl;
        TreeNode *node = root;
        while (root!= nullptr) { // 这里可以写成 while(true) 因为所给的算例，第k小的元素一定存在
            int left = getNodeNum(node->left);
            cout << left << endl;
            if (left < k - 1) { // 不在左子树
                node = node->right;
                k -= left + 1; // 以右孩子为根节点，寻找该子树的 k-left-1 小的值
            } else if (left == k - 1) {
                break;
            } else {
                node = node->left;
            }
        }
        return node->val;
    }

    int countNodeNum(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        nodeNum[root] = 1 + countNodeNum(root->left) + countNodeNum(root->right);
        cout << root->val << ": " << nodeNum[root] << endl;
        return nodeNum[root];
    }

    void getBstNum(TreeNode *root) {
        countNodeNum(root);
        cout << "All node Num:" << nodeNum[root] << endl;
    }

    // 获取以 root 为根节点的子节点数目
    int getNodeNum(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        return nodeNum[root];
    }
};
// @lc code=end
