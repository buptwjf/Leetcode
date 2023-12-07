//
// Created by 86188 on 2023/12/7.
//
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

#include "../0_offer2/include/user.h"

using namespace std;

// ��˳�򷵻ض�������Ҷ�ӽڵ�
/*
 *  ��һ�η�������Ҷ�ӽڵ㣬���Ӷ�������ɾ��
 *  �ڶ��η���ʣ�¶�������Ҷ�ӽڵ㣬���Ӷ�������ɾ��
 *  ......
 *  ����ɾ�����ڵ�
 * */

/*
 * ˼·��
 * 1. ��ɾ�����Ƕ������ϸ߶�Ϊ 0 �Ľڵ�
 * 2. �����������������еĽڵ�ĸ߶Ⱥ�ֵ�洢Ϊ map<int, int>
 * 3. ��С������� map
 * */
#include <map>

class Solution {
public:
    vector<vector<int>> res;
    multimap<int, int> m;
    int maxHeight;

    // �����������������ÿ���ڵ�ĸ߶Ⱥ�ֵ ��Ϊ pair �洢����
    int getHeight(TreeNode *root) {
        if (!root) {
            return -1;
        }
        int left = getHeight(root->left);
        int right = getHeight(root->right);
        int cur = max(left, right) + 1;

        maxHeight = max(maxHeight, cur);

        m.insert(make_pair(cur, root->val));
        return cur;
    }

    vector<vector<int>> findLeaves(TreeNode *root) {
        res.clear();
        m.clear();
        maxHeight = -1;
        getHeight(root);
        cout << maxHeight << endl;
        for (int height = 0; height <= maxHeight; height++) {
            auto range = m.equal_range(height); // multi_map �ķ���
            // �������н��
            vector<int> v;
            for (auto it = range.first; it != range.second; ++it) {
                v.emplace_back(it->second);
            }
            res.emplace_back(v);
        }
        return res;
    }
};