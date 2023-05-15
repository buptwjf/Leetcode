/*
 * @lc app=leetcode.cn id=509 lang=cpp
 *
 * [509] 斐波那契数
 */

// @lc code=start
class Solution {
public:
    int fib(int n) {
        if (n < 0) {
            return -1;
        }
        if (n <= 1 && 0 <= n) {
            return n;
        }

        int dp[3];
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            dp[2] = dp[0] + dp[1];
            dp[0] = dp[1];
            dp[1] = dp[2];
        }
        return dp[2];
    }
};
// @lc code=end

int main() {
    Solution s;
    s.fib(0);
    return 0;
}
