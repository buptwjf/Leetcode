/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */
#include <vector>

using namespace std;
/*
 * 使用贪心算法
 * 得到每天相对于前一天的差，然后将所有差为正数的相加
 *
 * */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int m = prices.size();
        vector<int> profit;
        for (int i = 1; i < m; i++) {
            profit.push_back(prices[i] - prices[i - 1]);
        }
        int res = 0;
        for (auto i: profit) {
            if (i > 0) {
                res += i;
            }
        }
        return res;
    }
};
// @lc code=end

