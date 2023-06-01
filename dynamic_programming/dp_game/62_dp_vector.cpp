/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 */

// @lc code=start

/*
 * 动态规划
 * 1. 定义 dp[] dp[i,j] 表示从起点到 dp[i,j]共有几种
 * 2. 初始化 dp[] dp[m,0]=1，dp[0,n]=1
 * 3. 状态转移方程  dp[i,j] = dp[i-1,j] + dp[i,j-1] 使用二层循环
 */
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        // 采用 一维 的 dp 数组，减少存储空间
        vector<int> dp(n, 0);
        // 初始化 dp 数组
        for (int i = 0; i < n; i++) {
            dp[i] = 1;
        }

        // 从上到下，从左到右遍历
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[j] = dp[j - 1] + dp[j];
            }
        }
        return dp[n - 1];
    }
};
// @lc code=end

