#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
  public:
    vector<vector<int>> fourSum(vector<int> &nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        // 首先判断提前退出的条件
        for (int i = 0; i < nums.size() - 3; i++) {
            for (int j = i + 1; j < nums.size() - 2; j++) {
                // 判断提前退出的条件
                if ((nums[i] > 0 && target <= 0) ||
                    (nums[j] + nums[i] > target)) {
                    return result;
                }
                // 对 j 去重
                if (nums[j] == nums[j + 1]) { // 针对 -1, -1, 2这种情况
                    continue;
                }

                int left = j + 1;
                int right = nums.size() - 1;
                int temp = nums[i] + nums[j];
                while (right > left) {
                    if (target - temp < 0) {
                        left++;
                    } else if (target - temp > 0) {
                        right--;
                    } else {
                        result.push_back(vector<int>{nums[i], nums[j],
                                                     nums[left], nums[right]});
                        while (right > left && nums[right] == nums[right--]) {
                            right--;
                        }
                        while (right > left && nums[left] == nums[left++]) {
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
