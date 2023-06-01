/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 */

// @lc code=start
#include <vector>

using namespace std;

/*
 * 首位相连的环型村庄
 * 单独考虑不包括首节点
 * 单独考虑不包括尾节点
 * */
class Solution {
private:
    int rob_sub(vector<int> &nums) {
        if (nums.size() < 2) {
            if (nums.size() == 0) {
                return 0;
            } else {
                return nums[0];
            }
        }
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < nums.size(); i++) {
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }
        return dp[nums.size() - 1];
    }

public:
    int rob(vector<int> &nums) {
        if(nums.size() == 1){
            return nums[0];
        }
        vector<int> v1(nums.begin(), nums.end() - 1);
        vector<int> v2(nums.begin() + 1, nums.end());
        int result1 = rob_sub(v1);
        int result2 = rob_sub(v2);
        int result = max(result1, result2);
        return result;

    }
};
// @lc code=end

