//
// Created by 86188 on 2023/7/19.
//

/*
 * 问题：判断 B 是不是 A 的子树
 * 思路：递归法，这个需要记忆+背诵
 * */

#include "../include/user.h"

using namespace std;

class Solution {
public:
    // 用来判断 B 是不是 A　的子树（不一定从A开始）
    bool isSubStructure(TreeNode *A, TreeNode *B) {
        if (B == NULL || A == NULL)
            return false;
        //遍历A中每个节点，A树中任一节点包含B就能返回true
        return iscontain(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B);
    }

    //包含：以A为根的数是否包含B（必须从A开始）
    bool iscontain(TreeNode *A, TreeNode *B) {
        if (B == NULL) // B 不存在那么 B 就是 A 的子树
            return true;
        if (A == NULL || A->val != B->val) // A 不存在，
            return false;
        return iscontain(A->left, B->left) && iscontain(A->right, B->right);
    }
};