/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 */

// @lc code=start
#include <vector>

using namespace std;

/*
 * 转化为背包问题：是都存在一个载重为 sum/2 的背包，和 nums.size() 个物品，每个物品重量为 nums[i]
 * 是否有一种方法，能够恰好将背包装满
 *
 * 背包问题：
 * 1. dp[][]的定义：dp[i][j] = x 表示对前 i 个物品，当前背包容量为 j 时，若 x 为ture，则说明恰好可以将背包装满，若 x 为false，则说明不能恰好将
 * 背包装满
 * 2. 最终答案是 dp[N][sum/2] base case为，dp[...][0] = true 和 dp[0][...] = false
 * 3. dp 方程
 *      dp[i][j] 如果把 nums[i] 算入子集，那么转态取决于 dp[i-1][j-nums[i-1]]
 *               如果不把 nums[i] 算入子集，那么转态取决于 dp[i-1][j]
 * 4. 遍历顺序 dp[i][j] i 为[1, n] j[0, sum/2]
 */
class Solution {
public:
    bool canPartition(vector<int> &nums) {
        int sum = 0;
        for (int &i: nums) {
            sum += i;
        }

        if (sum % 2 != 0) { // 和为奇数
            return false;
        }
        // 设定背包容量
        sum = sum / 2;
        int n = nums.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));
        for (int i = 0; i <= n; i++) {
            dp[i][0] = true;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= sum; j++) {
                if (j - nums[i - 1] < 0) {
                    dp[i][j] = dp[i - 1][j]; // 容量不足，不能装入第 i 个物品
                } else {
                    // 装入或者不装入背包
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
                }
            }
        }
        return dp[n][sum];
    }
};
// @lc code=end

