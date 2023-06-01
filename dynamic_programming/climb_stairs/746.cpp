/*
 * @lc app=leetcode.cn id=746 lang=cpp
 *
 * [746] 使用最小花费爬楼梯
 */

// @lc code=start
#include <vector>

using namespace std;

/*
 * 采用动态规划的思路
 *  1. dp[i] 表示爬上 i 层台阶上到楼顶，需要花费的体力
 *  2. dp[i] = min(dp[i-1]+cost[i-1], dp[i-2]+cost[i-2])
 * */
//class Solution {
//public:
//    int minCostClimbingStairs(vector<int> &cost) {
//        // 初始化 dp[]
//        vector<int> dp(cost.size() + 1);
//        dp[0] = 0;
//        dp[1] = 0;
//        for (int i = 2; i <= cost.size(); i++) {
//            dp[i] = min(dp[i - 1] + cost[i-1], dp[i - 2] + cost[i - 2]);
//        }
//        return dp[cost.size()];
//    }
//};


class Solution {
public:
    int minCostClimbingStairs(vector<int> &cost) {
        // 初始化 dp[]
        vector<int> dp(3);
        dp[0] = 0;
        dp[1] = 0;
        for (int i = 2; i <= cost.size(); i++) {
            dp[2] = min(dp[0] + cost[i-2], dp[1] + cost[i - 1]);
            dp[0] = dp[1];
            dp[1] = dp[2];
        }
        return dp[1];
    }
};
// @lc code=end

