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
    int dp(vector<int> &coins, int amount) {
        if (amount == 0) return 0;
        if (amount < 0) return -1;

        int res = INT32_MAX;
        for (int coin: coins) {
            int subProblem = dp(coins, amount - coin);
            if (subProblem == -1) continue;
            res = min(res, subProblem + 1);
        }
        return res == INT32_MAX ? -1 : res;
    }

public:;

    int coinChange(vector<int> &coins, int amount) {
        return dp(coins, amount);
    }
};
// @lc code=end

int main() {
    Solution s;
    vector<int> v = {1, 2, 5};
    s.coinChange(v, 100);
}