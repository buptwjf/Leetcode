/*
 * @lc app=leetcode.cn id=309 lang=cpp
 *
 * [309] 最佳买卖股票时机含冷冻期
 */
/*
 *  * 使用动态规划
 * dp[i][0] 表示第 i 天持有股票
 * dp[i][1] 表示第 i 天不持有股票
 * max(dp[i][1]) 表示 最终结果 要想盈利，必须是 j = 1 也就是卖出了
 * 特点：股票允许交易无数次，但是每买进一个股票，第二天不能卖出
 * 1. base case dp[0][0] = -price[0]，dp[0][1] = 0
 *              dp[1][0] = max(dp[0][0], dp[0][1]-prices[i])
 *              dp[1][1] = dp[0][1]
 * 2. 状态转移方程 dp[i][0] = max(dp[i-1][0], dp[i-1][1]-prices[i])
 *                           第i-1天就持有 或 第 i-1天不持有，到第i天才进行购买
 *                dp[i][1] = max(dp[i-1][1], dp[i-2][0]+price[i])
 * 3.                        第i-1天就没有 或者 第i-2天有，但是第i天卖出去了
 * */
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int m = prices.size();
        if (m == 1) {
            return 0;
        }
        vector<vector<int>> dp(m, vector<int>(2, 0));
        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        dp[1][0] = max(dp[0][0], dp[0][1] - prices[1]);
        dp[1][1] = max(dp[0][1], dp[0][0] + prices[1]);
        for (int i = 2; i < m; i++) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 2][1] - prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
        }
        return dp[m-1][1];
    }
};
// @lc code=end

