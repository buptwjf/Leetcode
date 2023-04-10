/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
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
    构造二叉树
    中序 [9,3,15,20,7]
    后序 [9,15,7,20,3]

    思路：从后序中取出最后一个元素，然后用这个元素对中序列表进行切分，再对后序列表进行切分
    [9,<3>,15,20,7]
    [<9>,<15,7,20>3]

    第一步：如果数组大小为零的话，说明是空节点了。
    第二步：如果不为空，那么取后序数组最后一个元素作为节点元素。
    第三步：找到后序数组最后一个元素在中序数组的位置，作为切割点
    第四步：切割中序数组，切成中序左数组和中序右数组
   （顺序别搞反了，一定是先切中序数组）
    第五步：切割后序数组，切成后序左数组和后序右数组
    第六步：递归处理左区间和右区间

*/

#include <vector>
using namespace std;
class Solution {
  public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        return traversal(inorder, postorder);
    }

    TreeNode *traversal(vector<int> &inorder, vector<int> &postorder) {
        // 第一步 递归终止条件
        if (inorder.size() == 0) {
            return nullptr;
        }
        // 第二步 找到分割点的值
        int split = postorder[postorder.size() - 1];
        cout << "split << " << split << endl;
        // 创建新节点，作为根节点
        TreeNode *root = new TreeNode(split);

        // 第三步 根据分割点的值找到分割位置
        int flag = 0; // 中序列表的分割位置
        for (int i = 0; i < inorder.size(); i++) {
            if (split == inorder[i]) {
                flag = i;
                cout << "falg = " << flag << endl;
                break;
            }
        }

        // 第四步 分割中序列表
        // 注意赋值的时候都是左闭右开
        vector<int> leftInorder(inorder.begin(), inorder.begin() + flag);
        vector<int> rightInorder(inorder.begin() + flag + 1, inorder.end());
        // 第五步 分割后序列表
        int lengthLeftInorder = leftInorder.size();
        int lengthRightInorder = rightInorder.size();
        vector<int> leftpostorder(postorder.begin(),
                                  postorder.begin() + lengthLeftInorder);
        vector<int> rightpostorder(postorder.begin() + lengthLeftInorder,
                                   postorder.begin() + lengthLeftInorder +
                                       lengthRightInorder);
        // 递归得到左子树，和右子树
        root->left = traversal(leftInorder, leftpostorder);
        root->right = traversal(rightInorder, rightpostorder);

        return root;
    }
};
// @lc code=end
