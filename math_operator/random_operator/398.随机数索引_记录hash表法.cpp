/*
 * @lc app=leetcode.cn id=398 lang=cpp
 *
 * [398] 随机数索引
 */

// @lc code=start
#include <vector>
#include <random>
#include <unordered_map>

using namespace std;

class Solution {
    // 由于数组含有重复数组
    unordered_map<int, vector<int>> pos;

public:
    Solution(vector<int> &nums) {
        for (int i = 0; i < nums.size(); ++i) {
            pos[nums[i]].push_back(i);
        }
    }

    int pick(int target) {
        auto &indices = pos[target];
        return indices[rand() % indices.size()];
    }
};


/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
// @lc code=end

