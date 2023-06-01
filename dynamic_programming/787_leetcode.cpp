/*
 * @lc app=leetcode.cn id=787 lang=cpp
 *
 * [787] K 站中转内最便宜的航班
 */

// @lc code=start
#include <vector>
#include <string>

using namespace std;

/*
 * 思路：使用动态规划
 * 1. 定义 dp[i][j] 数组，由于中转数为 K，共有 n 个地点，
 *      dp[i][j] 表示 恰好通过 i 次航班，从出发城市 src 到达城市 j 所需要的最小花费
 *      因此创建一个 K+2 * n 的数组
 * 2. 初始化 base case
 *      dp[0][src] = 0
 *      dp[0][other] = OO
 * 3. 状态转移方程
 *      dp[i][j] = dp[i-1][j之前的城市] + j之前的城市到 j 的花费
 *
 * */
class Solution {
private:
    static constexpr int INF = 10000 * 101 + 1;
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k) {
        vector<vector<int>> dp(k + 2, vector<int>(n, INF));
        // base case
        dp[0][src] = 0;
        for (int i = 1; i <= k + 1; i++) {
            for (auto flight: flights) {
                int m = flight[0];
                int n = flight[1];
                int cost = flight[2];
                dp[i][n] = min(dp[i][n], dp[i - 1][m] + cost);
            }
        }

        int ans = INF;
        for (int i = 1; i <= k + 1; i++) {
            ans = min(ans, dp[i][dst]);
        }
        return ans == INF ? -1 : ans;

    }
};
// @lc code=end

