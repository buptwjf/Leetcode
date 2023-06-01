/*
 * @lc app=leetcode.cn id=72 lang=cpp
 *
 * [72] 编辑距离
 */

// @lc code=start

/*
    word1 = "horse", word2 = "ros"
    输出 3
    输入距离

    示例：
    s1 =   rad
    s2 = apple
    as
    使用动态规划：
    1. 定义 dp[]][]


 */

#include <string>
#include <vector>

using namespace std;

class Solution {
  private:
    int min(int a, int b, int c) { return ::min(::min(a, b), c); }

  public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        // dp[i][j] 表示 str1[0, i-1] 和 str[0, j-1]
        // 初始化 dp 数组
        for (int i = 0; i <= m; i++) {
            dp[i][0] = i;
        }
        for (int j = 0; j <= n; j++) {
            dp[0][j] = j;
        }

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1]; // 不需要增加操作数
                } else {
                    // 对 i 进行删除，那么需要比较 s1[i-1] 和 s2[j]
                    // 对 i 进行插入，那么需要比较 s[i] 和 s2[j-1]
                    // 对 i 进行替换，比较 s[i-1] 和 s2[j-1])
                    dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j - 1] + 1,
                                   dp[i - 1][j - 1] + 1);
                }
            }
        }
        return dp[m][n];
    }
};
// @lc code=end
