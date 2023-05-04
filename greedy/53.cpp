/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */

// @lc code=start

/*
 * 请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和
 * 思路：
 *      1. 只要是正的，就有用，只要是负的的，就跳过
 *
 * */
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        int sum = INT32_MIN;
        int curSum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (curSum < 0) {
                curSum = 0;
            }

            curSum += nums[i];
            sum = std::max(sum, curSum);
        }
        return sum;
    }
};
// @lc code=end

int main() {
    Solution s;
    vector<int> v = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    s.maxSubArray(v);
    return 0;
}

