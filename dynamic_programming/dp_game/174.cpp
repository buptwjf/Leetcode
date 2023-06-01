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
 * 1. 定义 dp[][] 从 grid[i][j] 到达终点（右下角）所需的最少生命值是 dp(grid, i, j)。
 * */
class Solution {
private:
    vector<vector<int>> memo;

    int dp(vector<vector<int>> &dungeon, int i, int j) {
        int m = dungeon.size();
        int n = dungeon[0].size();

        if (i == m - 1 && j == n - 1) {
            memo[i][j] = dungeon[i][j] > 0 ? 1 : -dungeon[i][j] + 1;
            return memo[i][j];
        }
        // 避免无限递归
        if (i == m || j == n) {
            return INT32_MAX;
        }
        // 减少递归次数
        if (memo[i][j] != -1) {
            return memo[i][j];
        }
        // 状态转移
        int res = min(dp(dungeon, i, j + 1), dp(dungeon, i + 1, j)) - dungeon[i][j];
        memo[i][j] = res <= 0 ? 1 : res;
        return memo[i][j];
    }

public:
    int calculateMinimumHP(vector<vector<int>> &dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();
        memo = vector<vector<int>>(m, vector<int>(n, -1));
        return dp(dungeon, 0, 0);

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