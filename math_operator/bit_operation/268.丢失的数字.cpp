/*
 * @lc app=leetcode.cn id=268 lang=cpp
 *
 * [268] 丢失的数字
 */

// @lc code=start
/*
    由于异或具有结合律
    如：1 ^ 1 ^ 2 ^ 0 ^ 3 ^ 3 ^ 4 ^ 4 = 2
*/
#include <vector>
using namespace std;
class Solution {
  public:
    int missingNumber(vector<int> &nums) {
        int res = 0;
        int size = nums.size(); // 共有 n 个数
        // 先把标号 0 和 n 异或
        res ^= size;
        for (int i = 0; i < size; i++) {
            res ^= i ^ nums[i];
            // res ^= i ^= nums[i]; ?? 为啥不同
        }
        return res;
    }
};
// @lc code=end
