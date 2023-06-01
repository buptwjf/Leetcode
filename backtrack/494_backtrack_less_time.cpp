/*
 * @lc app=leetcode.cn id=494 lang=cpp
 *
 * [494] 目标和
 */

// @lc code=start

/*
 * 使用回溯算法，一般情况下无法通过时间的限制，需要对算法进行优化
    这里运用了一个思路：就是把加 target 改为 从 target 减到 0

    时间复杂度为 O(2^N)
 * */
#include <vector>

using namespace std;

class Solution {
private:
    int result = 0;
    void backtrack(vector<int> &nums, int startIndex, int remain) {
        if (startIndex == nums.size()) { // 走到最后，且总和满足
            if (remain == 0) {
                result++;
            }
            return;
        }
        // 选择 - 号
        remain += nums[startIndex];
        backtrack(nums, startIndex + 1, remain);
        remain -= nums[startIndex];
        // 选择 + 号

        remain -= nums[startIndex];
        backtrack(nums, startIndex + 1, remain);
        remain += nums[startIndex];
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

