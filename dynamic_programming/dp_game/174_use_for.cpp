/*
 * @lc app=leetcode.cn id=174 lang=cpp
 *
 * [174] 地下城游戏
 */

// @lc code=start
#include <vector>
#include <cstdint>

using namespace std;


/*
 * 1. 定义 dp[][] 从 grid[i][j] 到达终点（右下角）所需的最少生命值是 dp[i][j]。
 * 2. base case 可以初始化最后一行以及最后一列的数
 * */
class Solution {

public:
    int calculateMinimumHP(vector<vector<int>> &dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();
        // 创建 dp 数组
        vector<vector<int>> dp(m, vector<int>(n, -1));
        // base case
        // 对 最后一行 进行 初始化
        for (int i = n - 1; i >= 0; i--) {
            if (i == n - 1) {
                dp[m - 1][i] = dungeon[m - 1][i] > 0 ? 1 : -dungeon[m - 1][i] + 1;
            } else {
                int res = dp[m - 1][i + 1] - dungeon[m - 1][i];
                dp[m - 1][i] = res <= 0 ? 1 : res;
            }
        }
        // 对 最后一列 进行 初始化
        for (int j = m - 1; j >= 0; j--) {
            if (j == m - 1) {
                dp[j][n - 1] = dungeon[j][n - 1] > 0 ? 1 : -dungeon[j][n - 1] + 1;
            } else {
                int res = dp[j + 1][n - 1] - dungeon[j][n - 1];
                dp[j][n - 1] = res <= 0 ? 1 : res;
            }
        }

        // 遍历得到整个 dp tab
        for (int i = m - 2; i >= 0; i--) {
            for (int j = n - 2; j >= 0; j--) {
                int tmp = min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j];
                dp[i][j] = tmp <= 0 ? 1 : tmp;
            }
        }

        return dp[0][0];

    }
};
// @lc code=end

int main() {
    Solution s;
    vector<vector<int>> v = {{-2, -3,  3},
                             {-5, -10, 1},
                             {10, 30,  -5}};
    s.calculateMinimumHP(v);
    return 0;
}