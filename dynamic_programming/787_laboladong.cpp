/*
 * @lc app=leetcode.cn id=787 lang=cpp
 *
 * [787] K 站中转内最便宜的航班
 */

// @lc code=start
#include <vector>
#include <string>
#include <unordered_map>

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
    // 记录每个航班以及能到达这个航班的 航班以及价格
    unordered_map<int, vector<vector<int>>> memo;
    vector<vector<int>> dp_tab;
    int src;
    int dst;

    // 从 src 出发， k 步内到达 s 的最小成本
    int dp(int s, int k) {
        if (s == src) {
            return 0;
        }
        // 如果步数用尽，就无解
        if (k == 0) {
            return -1;
        }
        // 查找备忘录
        if (dp_tab[s][k] != -888) {
            return dp_tab[s][k];
        }
        // 进行递归
        int res = INT32_MAX;
        if (memo.count(s)) {
            for (auto v: memo[s]) {
                int from = v[0];
                int cost = v[1];

                int subProblem = dp(from, k - 1);
                if (subProblem != -1) {
                    res = min(res, subProblem + cost);
                }
            }
        }
        dp_tab[s][k] = res == INT32_MAX ? -1 : res;
        return dp_tab[s][k];
    }

public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k) {
        // 中转站个数 + 1 就是机票数
        k++;
        this->src = src;
        this->dst = dst;
        dp_tab.resize(n, vector<int>(k + 1, -888));
        // 初始化记录数组
        for (auto f: flights) {
            int from = f[0];
            int to = f[1];
            int cost = f[2];
            memo[to].push_back({from, cost});
        }

        return dp(dst, k);
    }
};
// @lc code=end

