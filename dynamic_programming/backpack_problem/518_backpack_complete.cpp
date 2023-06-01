/*
 * @lc app=leetcode.cn id=518 lang=cpp
 *
 * [518] 零钱兑换 II
 */

// @lc code=start
#include <vector>

using namespace std;

/*
 *
 *
 *
 * 完全背包问题：
 * 1. dp[][]的定义：dp[i][j] = x 表示对前 i 个物品，若想凑出来金额 j，有 dp[i][j] 种凑法
 * 背包装满
 * 2. 最终答案是 dp[N][amount] base case为，dp[...][0] = 1 和 dp[0][...] = 0
 * 3. dp 方程
 *      dp[i][j] 如果使用 coins[i-1] 那么转态取决于 dp[i][j-coins[i-1]]
 *               如果不使用 coins[i-1] ，那么转态取决于 dp[i-1][j]
 * 4. 遍历顺序 dp[i][j] i 为[1, n] j[0, sum/2]
 */

class Solution {
public:
    int change(int amount, vector<int> &coins) {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 0));
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= amount; j++) {
                if (j - coins[i - 1] >= 0) {
                    dp[i][j] = dp[i][j - coins[i - 1]] + dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[n][amount];
    }
};
// @lc code=end

