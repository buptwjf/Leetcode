/*
 * @lc app=leetcode.cn id=2560 lang=cpp
 *
 * [2560] 打家劫舍 IV
 */

// @lc code=start
#include <vector>
/*
    0 1 3 3 2 1 1 0.5  k = 2
    1 3  3
    3 2  2
    1 1  1
    2 1  2
    0 0.5 0.5
    有 k
*/
#include <string>

using namespace std;

/*
 * 这个题不能用动态规划
 * 要得到最小能力 min_cab，从左往右遍历房屋，如果小于min_cab则打劫，并跳过下一间房屋。
 * 如果可以打劫到k个房屋则成功则 nums 中有 >=k 个数小于 min_cab
 * 而且 min_cab 可能有多个，需要找出最小的一个
 * */
class Solution {
private:
    int min_cap = INT32_MAX;
public:
    int minCapability(vector<int> &nums, int k) {
        for (auto i: nums) {
            // min_cab
            int count = 0;
            int j;
            for (j = 0; j < nums.size(); j++) {
                if (nums[j] <= i) {
                    count++;
                    j++; // 跳过后一个
                }
            }
            if (count >= k) {
                min_cap = min(min_cap, i);
            }
        }
        return min_cap;
    }
};
// @lc code=end

