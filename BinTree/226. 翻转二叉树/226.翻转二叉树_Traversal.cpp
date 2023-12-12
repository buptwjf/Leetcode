/*
 * @lc app=leetcode.cn id=226 lang=cpp
 *
 * [226] 226. 翻转二叉树
 */

#include "../../0_offer2/include/user.h"

using namespace std;
// @lc code=start


/*
    翻转二叉树的思路: 采用 traversal写法，前序或后序遍历，同时交换左右节点
*/

// 采用后续遍历的递归法
class Solution {

public:
    void traversal(TreeNode *root) {
        if (!root) {
            return;
        }
        TreeNode *temp = root->left;
        root->left = root->right;
        root->right = temp;
        traversal(root->left);
        traversal(root->right);
    }

    TreeNode *invertTree(TreeNode *root) {
        traversal(root);
        return root;
    }
};



// @lc code=end
