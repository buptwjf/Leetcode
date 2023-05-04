/*
 * @lc app=leetcode.cn id=538 lang=cpp
 *
 * [538] 把二叉搜索树转换为累加树
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
    这个应该采用 右->中->左的遍历方式

    递归终止条件：该节点没有右孩子

    递归式子：
        当前节点有右孩子
        当前节点的值 = 右节点的值 + 自身
        左孩子的值 = 自身的值 + 左孩子的值 ??? 其实是不对得
*/
class Solution {
    int pre = 0;

  public:
    void traversal(TreeNode *cur) {
        if (cur == nullptr) {
            return;
        }
        traversal(cur->right);
        cur->val += pre;
        pre = cur->val;
        traversal(cur->left);
    }
    TreeNode *convertBST(TreeNode *root) {
        pre = 0;
        traversal(root);
        return root;
    }
};
// @lc code=end
