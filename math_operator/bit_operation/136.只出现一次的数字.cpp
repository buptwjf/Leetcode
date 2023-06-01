/*
 * @lc app=leetcode.cn id=136 lang=cpp
 *
 * [136] 只出现一次的数字
 */

// @lc code=start
#include <vector>
using namespace std;

/*
    思路：异或 任何数 a ^ a = 0;
                a ^ 0 = a;
*/
class Solution {
  public:
    int singleNumber(vector<int> &nums) {
        int res = 0;
        for (auto &i : nums) {
            res ^= i;
        }
        return res;
    }
};
// @lc code=end
