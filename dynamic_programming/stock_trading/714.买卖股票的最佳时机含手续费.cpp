/*
 * @lc app=leetcode.cn id=714 lang=cpp
 *
 * [714] 买卖股票的最佳时机含手续费
 */
/*
 *  * 使用动态规划
 * dp[i][0] 表示第 i 天持有股票
 * dp[i][1] 表示第 i 天不持有股票
 * max(dp[i][1]) 表示 最终结果 要想盈利，必须是 j = 1 也就是卖出了
 * 特点：股票只允许交易一次
 * 1. base case dp[0][0] = -price[0]，dp[0][1] = 0
 * 2. 状态转移方程 dp[i][0] = max(dp[i-1][0], dp[i-1][1]-prices[i])
 *                           第i-1天就持有 或 第 i-1天不持有，到第i天才进行购买
 *                dp[i][1] = max(dp[i-1][1], dp[i-1][0]+price[i]-fee)
 * 3.                        第i-1天就没有 或者 第i-1天有，但是第i天卖出去了
 * */
// @lc code=start
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int> &prices, int fee) {
        int m = prices.size();
        vector<vector<int>> dp(m, vector<int>(2, 0));
        // base case
        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        int res = 0;
        for (int i = 1; i < m; i++) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i] -fee);
            res = res > dp[i][1] ? res : dp[i][1];
        }
        return res;
    }
};
// @lc code=end

