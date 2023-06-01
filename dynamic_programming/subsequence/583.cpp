/*
 * @lc app=leetcode.cn id=583 lang=cpp
 *
 * [583] 两个字符串的删除操作
 */
/*
 * 思路：动态规划
 * 1. dp[i][j] 表示以 nums[i-1] nums[j-1]结尾的子串，需要减少的次数
 * 2. 状态转移矩阵
 *      dp[i][j] = nums[i-1]==nums[j-1] ? dp[i-1][j-1] : min(dp[i-1][j]+1, dp[i][j-1]+1);
 */

#include <vector>
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size() + 1, vector(word2.size() + 1, 0));
        // 初始化 第一个行
        for (int i = 0; i < word2.size() + 1; i++) {
            (*dp.begin())[i] = i;
        }
        for (int j = 0; j < word1.size() + 1; j++) {
            *dp[j].begin() = j;
        }

        for (int i = 1; i < word1.size() + 1; i++) {
            for (int j = 1; j < word2.size() + 1; ++j) {
                dp[i][j] = word1[i - 1] == word2[j - 1] ?
                           dp[i - 1][j - 1] : min(dp[i - 1][j] + 1, dp[i][j - 1] + 1);
            }
        }
        return dp[word1.size()][word2.size()];
    }
};
// @lc code=end

int main() {
    string s1 = "sea";
    string s2 = "eat";
    Solution s;
    s.minDistance(s1, s2);
    return 0;
}