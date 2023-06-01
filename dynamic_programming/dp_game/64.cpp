/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 */

// @lc code=start
#include <vector>
#include <iostream>

using namespace std;

/*
 * 使用动态规划：
 * 1. dp[i][j] 表示到 grid[i][j] 的最小距离
 * 2. dp 初始化 dp[0,...] 和 dp[...,0]
 * 3. 状态转移方程 dp[i][j]=min(dp[i-1][j],dp[i][j-1])+grid[i-1][j-1]
 *
 */
class Solution {
public:
    int minPathSum(vector<vector<int>> &grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        //初始化
        dp[0][0] = grid[0][0];
        for (int i = 1; i < n; i++) {
            dp[0][i] = dp[0][i - 1] + grid[0][i];
        }
        for (int j = 1; j < m; j++) {
            dp[j][0] = dp[j - 1][0] + grid[j][0];
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        return dp[m - 1][n - 1];
    }
};


//1 3 1
//1 5 1
//4 2 1
//
//
//1 4 5
//2 7 6
//6 8 7

// @lc code=end

int main() {
    Solution s;
    vector<vector<int>> v = {{1, 2, 3},
                             {4, 5, 6}};
    s.minPathSum(v);
    return 0;
}
