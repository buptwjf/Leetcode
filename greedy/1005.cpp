/*
 * @lc app=leetcode.cn id=1005 lang=cpp
 *
 * [1005] K 次取反后最大化的数组和
 */

/**
 * 思路：
 *  1. 当次数还没用完时，将负数全部转为正数，次数减一
 *  2. 当全部转换完，但是次数还没有用完，再对最小的正数翻转多次
 */

#include <vector>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    int largestSumAfterKNegations(vector<int> &nums, int k) {
        vector<int> v = nums;
        std::sort(v.begin(), v.end());
        for (auto &i: v) {
            if (k == 0) {
                break;
            }
            if (i <= 0) {
                i = -i;
                k--;
            }
        }

        if (k != 0) {
            std::sort(v.begin(), v.end());
            for (int i = k; i > 0; i--) {
                *v.begin() = -*v.begin();
            }
        }
        int sum = 0;
        for (auto i: v) {
            sum += i;
        }
        return sum;
    }
};
// @lc code=end

int main() {
    Solution s;
    vector<int> v = {4, 2, 3};
    s.largestSumAfterKNegations(v, 1);
    return 0;
}