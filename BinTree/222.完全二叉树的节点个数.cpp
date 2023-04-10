/*
 * @lc app=leetcode.cn id=222 lang=cpp
 *
 * [222] 完全二叉树的节点个数
 */

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

/*
    普通二叉树的节点个数：
        递归方法：左右中进行递归遍历即可
        迭代方法：使用层序遍历，在遍历的过程中进行记录即可

    完全二叉树的节点个数
        如果这个二叉树是满树：直接用公式法计算
        如果这个二叉树不是满树：可以用左右子树相加进行计算
*/

class Solution {
  public:
    int countNodes(TreeNode *root) {
        int numNodes = 0;
        if (!root) {
            return 0;
        }
        TreeNode *leftNode = root->left;
        TreeNode *rightNode = root->right;

        int leftDepth = 0;
        int rightDepth = 0;
        while (leftNode) {
            leftDepth++;
            leftNode = leftNode->left;
        }
        while (rightNode) {
            rightDepth++;
            rightNode = rightNode->right;
        }
        cout << leftDepth;
        cout << rightDepth;
        if (leftDepth == rightDepth) {
            numNodes = (2 << leftDepth) - 1; // 注意(2<<1) 相当于2^2，所以leftDepth初始为0
        } else {
            numNodes = countNodes(root->left) + countNodes(root->right) + 1;
        }
        return numNodes;
    }
};
// @lc code=end
