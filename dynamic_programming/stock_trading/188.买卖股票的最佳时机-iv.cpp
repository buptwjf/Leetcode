/*
 * @lc app=leetcode.cn id=188 lang=cpp
 *
 * [188] 买卖股票的最佳时机 IV
 */
#include <string>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
  public:
    int maxProfit(int k, vector<int> &prices) {

        int m = prices.size();
        vector<vector<vector<int>>> dp(
            m, vector<vector<int>>(k + 1, vector<int>(2, 0)));
        // base case
        for (int i = 0; i <= k; i++) {
            dp[0][i][0] = 0;
            if (i == 0) {
                dp[0][i][1] = INT32_MIN;
            } else {
                dp[0][i][1] = -prices[0];
            }
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j <= k; j++) {
                dp[i][j][0] = max(
                    dp[i - 1][j][0],
                    dp[i - 1][j][1] +
                        prices[i]); // max(i-1天不持有 或 i-1天持有，第i天卖出)
                dp[i][j][1] = max(
                    dp[i - 1][j][1],
                    dp[i - 1][j - 1][0] -
                        prices[i]); // max(i-1天不持有 或 i-1天持有，第i天卖出)
            }
        }
        return dp[m - 1][k][0];
    }
};
// @lc code=end
