/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */

// @lc code=start
#include <vector>

using namespace std;

/*
 * 动态规划
 * 1. dp[i] 表示 在到达 i 的时候。最大能偷到多少钱
 * 2. 状态转移方程
 *      dp[i] = max(dp[i-2] + nums[i], dp[i-1])
 * 3. base case
 *      dp[0] = nums[0]
 *      dp[1] = max(nums[0], nums[1])
 * */
class Solution {
public:
    int rob(vector<int> &nums) {
        if (nums.size() < 2) {
            if (nums.size() == 0) {
                return 0;
            } else {
                return nums[0];
            }
        }
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < nums.size(); i++) {
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }
        return dp[nums.size() - 1];
    }
};
// @lc code=end

