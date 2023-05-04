/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */

// @lc code=start

/*
 * 将股票价格分解成连续两天的局部利润，用局部利润来计算全局利润
 * 只收集正利润
 * */
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        vector<int> p;
        for (int i = 0; i < prices.size() - 1; ++i) {
            p.push_back(prices[i + 1] - prices[i]);
        }
        // 对 p 计算最大数组和
        int sum = 0;
        for (int i: p) {
            if (i > 0)
                sum += i;
        }
        return sum;
    }
};
// @lc code=end

int main() {
    Solution s;
    vector<int> v = {7, 1, 5, 3, 6, 4};
    s.maxProfit(v);
    return 0;
}

