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
private:
    vector<int> memo;

    int dp(vector<int> &coins, int amount) {
        if (amount == 0) return 0;
        if (amount < 0) return -1;
        if (memo[amount] != -666) { return memo[amount]; }

        int res = INT32_MAX;
        for (int coin: coins) {
            int subProblem = dp(coins, amount - coin);
            if (subProblem == -1) continue;
            res = min(res, subProblem + 1);
        }
        memo[amount] = res == INT32_MAX ? -1 : res;
        return memo[amount];
    }

public:;

    int coinChange(vector<int> &coins, int amount) {
        memo = vector<int>(amount + 1, -666);  // 0 ~ amount
        return dp(coins, amount);
    }
};
// @lc code=end

int main() {
    Solution s;
    vector<int> v = {1, 2, 5};
    s.coinChange(v, 100);
}