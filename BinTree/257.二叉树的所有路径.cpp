/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
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
    返回所有从根节点到叶子节点的路径
        思路：
            递归停止条件：碰到叶子节点时停止，得到一组结果，return
            
            递归开始：若该节点时父节点，该 push 该节点入 path；
                        以左右中的顺序，开始递归，每完成一次完整的路径，进行回溯
                    注意回溯的位置！
                    回溯和递归是一一对应的，有一个递归，就要有一个回溯
*/
#include <string>
#include <vector>
using namespace std;
class Solution {
  public:
    vector<string> binaryTreePaths(TreeNode *root) {
        vector<int> path;
        vector<string> result;
        if (!root) {
            return result;
        }

        Traversal(root, path, result);
        return result;
    }

    void Traversal(TreeNode *cur, vector<int> &path, vector<string> &result) {
        if (!cur->left && !cur->right) { // 已经到达了叶子节点，得到一个结果
            // 将 path 中的元素组成一组结果
            string sresult;
            path.push_back(cur->val);
            for (int i = 0; i < path.size() - 1; i++) {
                sresult += to_string(path[i]);
                sresult += "->";
            }
            sresult += to_string(path[path.size() - 1]);
            result.push_back(sresult);
            return;
        }
        path.push_back(cur->val);
        if (cur->left) { // 如果该节点有左孩子
            Traversal(cur->left, path, result);
            path.pop_back();  // 注意回溯的位置
        }
        if (cur->right) { // 如果该节点有左孩子
            Traversal(cur->right, path, result);
            path.pop_back(); // 注意回溯的位置
        }
    }
};
// @lc code=end
