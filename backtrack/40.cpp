/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */

// @lc code=start

/*
 * 采用回溯
 * 首先是不能重复，来确定如何剪枝
 *
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;

    void traversal(vector<int> &candidates, int target, int startIndex, int sum, vector<bool> &used) {
        // 递归终止条件
        if (sum == target) {
            result.push_back(path);
        }
        if (sum > target) {
            return;
        }


        for (int i = startIndex; i < candidates.size(); i++) {
            // 如果 i 已经使用过，则跳过这次循环
            int cur = candidates[i];
            if (i > 0 && candidates[i] == candidates[i - 1] && used[i - 1] == false) {
                continue;
            }
            used.push_back(cur);
            path.push_back(cur);
            sum += cur;
            used[i] = true;
            traversal(candidates, target, i + 1, sum, used);
            used[i] = false;
            path.pop_back();
            sum -= cur;
        }
    }

public:

    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        result.clear();
        path.clear();
        vector<bool> used(candidates.size(), false);
        sort(candidates.begin(), candidates.end());
        traversal(candidates, target, 0, 0, used);
        return result;
    }

};
// @lc code=end

int main() {
    Solution s;
    vector<int> v = {10, 1, 2, 7, 6, 1, 5};
    s.combinationSum2(v, 8);
}
