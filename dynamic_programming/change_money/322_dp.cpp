/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */
#include <vector>
#include <cstdint>

using namespace std;

// @lc code=start
class Solution {
    // dp 数组的定义：当目标金额为 i 时，至少需要 dp[i] 枚硬币凑出。
public:;

    int coinChange(vector<int> &coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        // 数组大小为 amount+1，初始值为 amount+1
        dp[0] = 0;

        for (int i = 0; i < dp.size(); i++) {
            for (int coin: coins) {
                // 子问题无解
                if (i - coin < 0) {
                    continue;
                }
                dp[i] = min(dp[i], 1 + dp[i - coin]);
            }
        }
        return (dp[amount] == amount + 1) ? -1 : dp[amount];
    }
};
// @lc code=end

int main() {
    Solution s;
    vector<int> v = {1, 2, 5};
    s.coinChange(v, 100);
}