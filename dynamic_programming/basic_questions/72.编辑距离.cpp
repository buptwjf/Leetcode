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
    s1 = rad
    s2 = apple
    as
    使用动态规划：
    1. 定义 dp[]][]


 */

#include <string>
#include <vector>
using namespace std;

class Solution {
  public:
    int min(int a, int b, int c) { return ::min(::min(a, b), c); }

    // 定义：返回 s1[0..i] 和 s2[0..j] 的最小编辑距离
    int dp(string s1, int i, string s2, int j) {
        // base case
        if (i == -1)
            return j + 1;
        if (j == -1)
            return i + 1;

        if (s1[i] == s2[j]) {
            return dp(s1, i - 1, s2, j - 1); // 啥都不做
        }
        return min(dp(s1, i, s2, j - 1) + 1,    // 插入
                   dp(s1, i - 1, s2, j) + 1,    // 删除
                   dp(s1, i - 1, s2, j - 1) + 1 // 替换
        );
    }

    int minDistance(string s1, string s2) {
        int m = s1.length(), n = s2.length();
        // i，j 初始化指向最后一个索引
        return dp(s1, m - 1, s2, n - 1);
    }
};
// @lc code=end
