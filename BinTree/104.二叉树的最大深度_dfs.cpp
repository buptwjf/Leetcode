//
// Created by 86188 on 2023/7/25.
//

#include "../0_offer2/include/user.h"

using namespace std;

/*
 * 时间复杂度为 O(N) N 为二叉树的节点数
 * 对应着 遍历方式得到整个答案 + dfs写法 的思路
 * */
class Solution {
private:
    int depth;
    int res;
public:
    int maxDepth(TreeNode *root) {
        depth = 0;
        res = 0;
        traversal(root);
        return res;
    }

    void traversal(TreeNode *cur) {
        if (!cur) {
            return;
        }
        depth++;
        if (!cur->left && !cur->right) {
            res = max(depth, res);
        }
        traversal(cur->left);
        traversal(cur->right);
        depth--;
    }

};