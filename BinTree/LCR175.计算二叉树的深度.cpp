//
// Created by 86188 on 2023/12/7.
//


/*
 * ˼·�����õݹ����ʽ
 * ͨ�� �ݹ�ķ�ʽ + �������
 * */
#include "../0_offer2/include/user.h"
class Solution {
public:
    int calculateDepth(TreeNode *root) { return getDepth(root); }
    int getDepth(TreeNode *cur) {
        if (!cur) {
            return 0; //����д�����д����������ᳬʱ���������صĵ���
        }
        // ����ʵ�����к������
        int depth = 1 + std::max(getDepth(cur->left), getDepth(cur->right));
        return depth;
    }
};


// Ч�ʸ���
class Solution1 {
public:
    int calculateDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        return std::max(calculateDepth(root->left), calculateDepth(root->right)) + 1;
    }
};