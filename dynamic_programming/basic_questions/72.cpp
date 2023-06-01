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

    int dp(string s1, int i, string s2, int j) {
        // base case 当一个字符串遍历结束只有，返回另一个字符串剩余的长度
        if (i == -1) {
            return j + 1;
        }
        if (j == -1) {
            return i + 1;
        }
        if (s1[i] == s2[j]) {
            return dp(s1, i - 1, s2, j - 1); // 不需要增加操作数
        } else {
            // 对 i 进行删除，那么需要比较 s1[i-1] 和 s2[j]
            // 对 i 进行插入，那么需要比较 s[i] 和 s2[j-1]
            // 对 i 进行替换，比较 s[i-1] 和 s2[j-1])
            return min(dp(s1, i - 1, s2, j) + 1, dp(s1, i, s2, j - 1) + 1,
                       dp(s1, i - 1, s2, j - 1) + 1);
        }
    }

  public:
    int minDistance(string word1, string word2) {
        int m = word1.size() - 1;
        int n = word2.size() - 1;
        return dp(word1, m, word2, n);
    }
};
// @lc code=end
