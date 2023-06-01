/*
 * @lc app=leetcode.cn id=516 lang=cpp
 *
 * [516] 最长回文子序列
 */

// @lc code=start
#include <vector>
#include <string>
#include "iostream"

using namespace std;

/*
 * 1. 定义 dp[] 数组，dp[i][j] 表示以 i 为起点 j 为终点
 * 2. 状态转移方程：
 *    dp[i][j] = str[i]==str[j] ? dp[i+1][j-1]+2 : max(dp[i+1][j], dp[i][j-1]);
 * 3. 确定遍历顺序
 *
 * */

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        vector<vector<int>> dp(s.size(), vector(s.size(), 0));
        for (int i = 0; i < s.size(); i++) {
            dp[i][i] = 1;
        }

        for (int j = s.size() - 2; j >= 0; j--) {  // 3 2 1 0
            for (int i = j + 1; i < s.size(); i++) { // 4 3 2 1
                dp[j][i] = s[i] == s[j] ? dp[j + 1][i - 1] + 2 : max(dp[j + 1][i], dp[j][i - 1]);
//                std::cout << dp[j][i] << " "; // 有时输出也会增加时间
            }
//            cout << std::endl;
        }

        return dp[0][s.size() - 1];

    }
};
// @lc code=end

int main() {
    Solution s;
    string str = "bbbab";
    s.longestPalindromeSubseq(str);
    return 0;
}