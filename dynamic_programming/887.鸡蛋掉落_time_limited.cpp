/*
 * @lc app=leetcode.cn id=887 lang=cpp
 *
 * [887] 鸡蛋掉落
 */
/*
 * 使用动态规划
 * 定义：dp[i][j]表示当前状态有 K 个鸡蛋，对面有 N 个楼
 * */
// @lc code=start
#include <vector>
#include <climits>
#include <string>
using namespace std;

class Solution {
private:
    vector<vector<int>> memo;

    int dp(int k, int n) { // k 个鸡蛋，面对 n 层
        // base case
        int res = INT32_MAX;
        if (k == 1) {
            return n;
        }
        if (n == 0) {
            return 0;
        }
        if (memo[k][n] != -1) {
            return memo[k][n];
        }

        for (int i = 1; i <= n; i++) {
            // 最坏的情况下最少得扔鸡蛋次数
            res = min(res, max(dp(k - 1, i - 1), // 鸡蛋碎了
                               dp(k, n - i)) // 鸡蛋没碎
                           + 1); // 在第 i 楼扔了一次
        }
        memo[k][n] = res;
        return res;
    }

public:
    int superEggDrop(int k, int n) {
        memo = vector<vector<int>>(k + 1, vector<int>(n + 1, -1));
        return dp(k, n);
    }
};
// @lc code=end

