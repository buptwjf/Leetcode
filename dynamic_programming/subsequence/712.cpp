/*
 * @lc app=leetcode.cn id=712 lang=cpp
 *
 * [712] 两个字符串的最小ASCII删除和
 */

// @lc code=start
/*
 * 思路：动态规划
 * 1. 定义 dp[i][j] 表示 text1 i个， text2 j 个数
 * 2. 状态转移方程
 *        dp[i][j] = nums[i-1]==nums[j-1] ? dp[i-1][j-1] : min(dp[i-1][j]+ascii(text1[i]), dp[i][j-1]+ascii(text2[j]));
 * */

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        vector<vector<int>> dp(s1.size() + 1, vector(s2.size() + 1, 0));
        // 初始化 第一个行
        dp[0][0] = 0;
        for (int i = 1; i < s2.size() + 1; i++) {
            (*dp.begin())[i] = (*dp.begin())[i - 1] + int(s2[i - 1]);
        }
        for (int j = 1; j < s1.size() + 1; j++) {
            *dp[j].begin() = *dp[j - 1].begin() + int(s1[j - 1]);
        }

        for (int i = 1; i < s1.size() + 1; i++) {
            for (int j = 1; j < s2.size() + 1; ++j) {
                int tmp = min(dp[i - 1][j] + int(s1[i-1]), dp[i][j - 1] + int(s2[j-1]));
                dp[i][j] = s1[i - 1] == s2[j - 1] ? dp[i - 1][j - 1] : tmp;
                cout << tmp << endl;
            }
        }
        for (auto i: dp) {
            for (auto j: i) {
                cout << j << "  ";
            }
            cout << endl;
        }

        return dp[s1.size()][s2.size()];
    }
};
// @lc code=end

int main() {
    string s1 = "sea";
    string s2 = "eat";
    Solution s;
    s.minimumDeleteSum(s1, s2);
    return 0;
}