/*
 * @lc app=leetcode.cn id=977 lang=cpp
 *
 * [977] 有序数组的平方
 */

// @lc code=start

#include <cmath>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int> &nums) {
        int left = 0;
        int right = nums.size() - 1;
        int n = nums.size() - 1;
        vector<int> temp_nums(nums.size(), 0);
        while (left <= right) {
            if (abs(nums[left]) >= abs(nums[right])) {
                temp_nums[n--] = nums[left] * nums[left];
                left++;
            } else {
                temp_nums[n--] = nums[right] * nums[right];
                right--;
            }
        }
        return temp_nums;
    }
};
// @lc code=end
