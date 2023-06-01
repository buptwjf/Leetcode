/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] 不同路径 II
 */

// @lc code=start

/*
 * 动态规划
 * 1. 定义 dp[] dp[i,j] 表示从起点到 dp[i,j]共有几种
 * 2. 初始化 dp[] dp[m,0]=1，dp[0,n]=1
 * 3. 状态转移方程  dp[i,j] = dp[i-1,j] + dp[i,j-1] 使用二层循环
 * 4. 如果有障碍物的话，就让障碍物处的 do[i,j]=0;
 */

#include <vector>

using namespace std;
class Solution {
  public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));

        bool flagY = false;
        for (int i = 0; i < m; i++) {
            if (obstacleGrid[i][0] == 1 || flagY) {
                dp[i][0] = 0;
                flagY = true;
            } else {
                dp[i][0] = 1;
            }
        }

        bool flagX = false;

        for (int j = 0; j < n; j++) {
            if (obstacleGrid[0][j] == 1 || flagX) {
                dp[0][j] = 0;
                flagX = true;
            } else {
                dp[0][j] = 1;
            }
        }

        // 从上到下，从左到右遍历
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                } else {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};
// @lc code=end
