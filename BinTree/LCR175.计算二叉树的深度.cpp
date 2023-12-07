//
// Created by 86188 on 2023/12/7.
//


/*
 * 思路：采用递归的形式
 * 通过 递归的方式 + 后序遍历
 * */
#include "../0_offer2/include/user.h"
class Solution {
public:
    int calculateDepth(TreeNode *root) { return getDepth(root); }
    int getDepth(TreeNode *cur) {
        if (!cur) {
            return 0; //必须写在这里，写在主函数里会超时，减少来回的调用
        }
        // 这里实际是中后序遍历
        int depth = 1 + std::max(getDepth(cur->left), getDepth(cur->right));
        return depth;
    }
};


// 效率更慢
class Solution1 {
public:
    int calculateDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        return std::max(calculateDepth(root->left), calculateDepth(root->right)) + 1;
    }
};