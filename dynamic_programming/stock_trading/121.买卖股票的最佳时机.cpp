/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */
/*
 * 使用动态规划
 * dp[i][0] 表示第 i 天持有股票
 * dp[i][1] 表示第 i 天不持有股票
 * max(dp[i][1]) 表示 最终结果 要想盈利，必须是 j = 1 也就是卖出了
 * 特点：股票只允许交易一次
 * 1. base case dp[0][0] = -price[0]，dp[0][1] = 0
 * 2. 状态转移方程 dp[i][0] = max(dp[i-1][0], -prices[i])
 *                           第i-1天就持有 或 第i天才进行购买，由于只需要买一次所以为 -prices[i]
 *                dp[i][1] = max(dp[i-1][1], dp[i-1][0]+price[i])
 * 3.                        第i-1天就没有 或者 第i-1天有，但是第i天卖出去了
 * */
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int m = prices.size();
        vector<vector<int>> dp(m, vector<int>(2, 0));
        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        int res = 0;
        for (int i = 1; i < m; i++) {
            dp[i][0] = max(dp[i - 1][0], -prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
            res = res > dp[i][1] ? res : dp[i][1];
        }
        return res;

    }
};
// @lc code=end