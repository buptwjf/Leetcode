/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */

// @lc code=start

/*
 * 最长递增子序列
 * 思路：动态规划
 * 1. 定义 dp[] 数组， dp[i] 表示下标为 i 的子串的最大子
 * 2. 初始化 dp[]，dp[i] = 1
 * 3. 状态转移方程:找出前面小于 nums[i] 的元素，然后选出最大的 max_dp  dp[i] = max_dp
 */
#include <vector>
#include <algorithm>

using namespace std;

class Solution {

public:
    int lengthOfLIS(vector<int> &nums) {
        // 创建并初始化 dp[]
        vector<int> dp(nums.size(), 1);
        for (int i = 0; i < nums.size(); i++) {
            // 找出小于 nums[i] 的元素
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1); // 精髓！！
                }
            }
        }
        return *max_element(dp.begin(), dp.end());

    }
};
// @lc code=end

