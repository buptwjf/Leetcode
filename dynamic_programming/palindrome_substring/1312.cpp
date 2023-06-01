/*
 * @lc app=leetcode.cn id=1312 lang=cpp
 *
 * [1312] 让字符串成为回文串的最少插入次数
 */

// @lc code=start
class Solution {
public:
    int minInsertions(string s) {
        vector <vector<int>> dp(s.size(), vector(s.size(), 0));
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

        return s.size() - dp[0][s.size() - 1];  // 其实字符总长度减掉最长回文串的长度就是多余的字符，也就是应该要插入的字符

    }
};
// @lc code=end

