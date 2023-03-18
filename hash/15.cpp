/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    vector<vector<int>> threeSum(vector<int> &nums) {

        // 对vector 排序
        sort(nums.begin(), nums.end());
        // 输出得元组列表
        vector<vector<int>> result;
        for (size_t i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                return result; // 一旦第一个数大于0，则无论如何三个数都无法相加得
                               // 0
            }
            // 对 a 去重
            if (i > 0 && nums[i] == nums[i - 1]) { // 针对 -1, -1, 2这种情况
                continue;
            }

            int left = i + 1;            // 从 i 之后
            int right = nums.size() - 1; // 从倒数第一
            while (right > left) {
                if (nums[i] + nums[left] + nums[right] > 0) {
                    right--;
                } else if (nums[i] + nums[left] + nums[right] < 0) {
                    left++;
                } else {
                    // 插入 vector
                    result.push_back(
                        vector<int>{nums[i], nums[left], nums[right]});
                    // 判断是否重复
                    while (right > left && nums[right] == nums[right - 1]) {
                        right--;
                    }
                    while (right > left && nums[left] == nums[left + 1]) {
                        left++;
                    }
                    // 找到答案时，双指针同时收缩
                    right--;
                    left++;
                }
            }
        }
        return result;
    }
};


int main(int argc, char const *argv[])
{
    vector<int> nums = {-1,0,1,2,-1,-4};
    Solution s;
    vector<vector<int>> result = s.threeSum(nums);
    cout << nums[0];
    return 0;
}
