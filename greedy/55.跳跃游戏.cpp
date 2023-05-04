//
// Created by 86188 on 2023/5/4.
//
/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 *
 */
/* 思路，找到每一步的最大范围，看最大范围能不能到达终点
 *
 * */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    bool canJump(vector<int> &nums) {
        int flag = 0;
        if (nums.size() == 1) return true;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (i > flag) {
                return false;
            }
            flag = max(flag, nums[i] + i);
            if (flag >= nums.size() - 1) {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end

int main() {
    Solution s;
    vector<int> v = {3, 2, 1, 0, 4};
    s.canJump(v);
    return 0;
}

