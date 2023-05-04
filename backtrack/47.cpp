/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

// @lc code=start
//#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;

    void backtracking(vector<int> &nums, vector<bool> used) {
        if (path.size() == nums.size()) {
            result.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1] || used[i] != false) {
                continue;
            }
  
            path.push_back(nums[i]);
            used[i] = true;
            backtracking(nums, used);
            path.pop_back();
            used[i] = false;
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int> &nums) {
        result.clear();
        path.clear();
        vector<bool> used(nums.size(), false);

        sort(nums.begin(), nums.end());
        backtracking(nums, used);
        return result;
    }
};


// @lc code=end

int main() {
    Solution s;
    vector<int> vec = {1, 1, 2};
    s.permuteUnique(vec);
    return 0;
}