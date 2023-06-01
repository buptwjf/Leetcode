/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start

#include <vector>

using namespace std;

/*
 * 使用动态规划：
 *  1. 定义 dp[] 数组，dp[i] 爬 i 层 楼梯有几种爬法 dp[1] = 1，dp[2] = 2 dp[3] = 3
 *  2. 状态转移方程 dp[i] = dp[i-1] + dp[i-2]
 */
class Solution {

public:
   int climbStairs(int n) {
       if (n <= 1) {  
           //  dp[0]=0 dp[1]=1, dp[0]=1 虽然不满足dp[0]+dp[1]=dp[2]，但是dp[0]实际上就是0
           // 实际上不用考虑 dp[0]
           return n;
       }
       vector<int> dp(n + 1);
       dp[1] = 1;
       dp[2] = 2;
       for (int i = 3; i <= n; i++) {
           dp[i] = dp[i - 1] + dp[i - 2];
       }
       return dp[n];
   }
};



// 内存优化版本

/* class Solution {

public:
    int climbStairs(int n) {
        if (n <= 1) {  //  dp[0]=0 dp[1]=1
            return n;
        }
        vector<int> dp(3);
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++) {
            dp[3] = dp[1] + dp[2];
            dp[1] = dp[2];
            dp[2] = dp[3];
        }
        return dp[2];
    }
}; */
// @lc code=end

