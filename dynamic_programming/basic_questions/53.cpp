/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */

// @lc code=start
#include <vector>
#include <algorithm>

using namespace std;

/*
 * 动态规划
 * 1. 定义 dp[]：dp[i]表示以 i号结尾的子串，的最大和
 * 2. 状态转移方程：dp[i] = (dp[i-1]+nums[i], nums[i])
 * 3. 最终结果为遍历 dp[] 数组找出最大的数
 * */
class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
        }
        return *max_element(dp.begin(), dp.end());
    }
};
// @lc code=end

