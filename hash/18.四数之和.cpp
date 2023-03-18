/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */

// @lc code=start
class Solution {
  public:
    vector<vector<int>> fourSum(vector<int> &nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        // 首先判断提前退出的条件
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > target && nums[i] >= 0) {
                break;
            }
            // 对 i进行去重
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            for (int j = i + 1; j < nums.size(); j++) {
                // 判断提前退出的条件
                if (nums[i]+nums[j]>=0 && nums[j] + nums[i] > target) {
                    break;
                }
                // 对 j 去重
                if (j > i+1 && nums[j] == nums[j-1]) { // 针对 -1, -1, 2这种情况
                    continue;
                }

                int left = j + 1;
                int right = nums.size() - 1;
                while (right > left) {
                    if (target  < (long)nums[i] + nums[j] + nums[right] + nums[left]) {
                        right--;
                    } else if (target > (long)nums[i] + nums[j] + nums[right] + nums[left]) {
                        left++;
                    } else {
                        result.push_back(vector<int>{nums[i], nums[j],
                                                     nums[left], nums[right]});
                        while (right > left && nums[right] == nums[right-1]) {
                            right--;
                        }
                        while (right > left && nums[left] == nums[left+1]) {
                            left++;
                        }
                        right--;
                        left++;
                    }
                }
            }
        }
        return result;
    }
};
// @lc code=end
