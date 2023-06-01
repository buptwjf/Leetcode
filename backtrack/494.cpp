/*
 * @lc app=leetcode.cn id=494 lang=cpp
 *
 * [494] 目标和
 */

// @lc code=start

/*
 * 使用回溯算法，一般情况下无法通过时间的限制，需要对算法进行优化
 * */
#include <vector>

using namespace std;

class Solution {
private:
    int sum = 0;
    int result = 0;
    void backtrack(vector<int> &nums, int startIndex, int target) {
        if (startIndex == nums.size()) { // 走到最后，且总和满足
            if (sum == target) {
                result++;
            }
            return;
        }
        sum += nums[startIndex];
        backtrack(nums, startIndex + 1, target);
        sum -= nums[startIndex];

        sum -= nums[startIndex];
        backtrack(nums, startIndex + 1, target);
        sum += nums[startIndex];

    }


public:

    int findTargetSumWays(vector<int> &nums, int target) {
        if (nums.size() == 0) {
            return 0;
        }

        backtrack(nums, 0, target);
        return result;

    }

};
// @lc code=end

