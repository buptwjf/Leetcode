/*
 * @lc app=leetcode.cn id=1143 lang=cpp
 *
 * [1143] 最长公共子序列
 */

// @lc code=start

/*
 * 思路：动态规划
 * 1. 定义 dp[i][j] 表示 text1 i个， text2 j 个数
 * 2. 状态转移方程
 *        dp[i][j] = text[i]==text[j] ?  dp[i-1][j-1]+1 : max(dp[i-1][j],dp[i][j-1]);
 * */
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size() + 1, vector(text2.size() + 1, 0));
        for (int i = 1; i < text1.size() + 1; i++) {
            for (int j = 1; j < text2.size() + 1; ++j) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                }

            }
        }
        return dp[text1.size()][text2.size()];
    }
};
// @lc code=end

