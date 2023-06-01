/*
 * @lc app=leetcode.cn id=494 lang=cpp
 *
 * [494] 目标和
 */

// @lc code=start
#include <vector>
#include <math.h>

using namespace std;

/*
 *  A 代表前面是 + 的数，B 代表是 - 的数
 *  sum(A) - sum(B) = target
    sum(A) = target + sum(B)
    sum(A) + sum(A) = target + sum(B) + sum(A)
    2 * sum(A) = target + sum(nums)

    nums 中存在几个子集 A，使得 A 中的元素和为 （target + sum(nums))/2
 * */
class Solution {
    int subsets(vector<int> &nums, int sum) {
        int n = nums.size();
        // dp[][] 为  n+1 * sum+1
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));
        // 因为本题中 nums[i] 有可能为 0，所以dp[i][0] 不能设置为 1
//        for (int i = 0; i <= n; i++) {
//            dp[i][0] = 1;
//        }
//        for (int j = 1; j <= sum; j++) {
//            dp[0][j] = 0;
//        }
        dp[0][0] = 1;
        // dp[i][j] 表示只在前 i 个数中选择，总和为 j 的话有 dp[i][j] 的方法恰好可以装满背包


        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= sum; j++) { // 注意遍历从哪开始
                if (j - nums[i - 1] < 0) {
                    dp[i][j] = dp[i - 1][j]; // 容量不足，不能装入第 i 个物品
                } else {
                    // 装入或者不装入背包
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i - 1]];
                }
            }
        }
        return dp[n][sum];
    }

public:
    int findTargetSumWays(vector<int> &nums, int target) {
        int sum = 0;
        for (auto &i: nums) {
            sum += i;
        }
        if (sum < abs(target) || (sum + target) % 2 == 1) {
            return 0;
        }
        return subsets(nums, (sum + target) / 2);
    }

};
// @lc code=end

