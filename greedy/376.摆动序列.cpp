/*
 * @lc app=leetcode.cn id=376 lang=cpp
 *
 * [376] 摆动序列
 */

// @lc code=start
#include <vector>

using namespace std;

/*
 * 思路：用一个标记，然后遍历
 * */
class Solution {
public:
    int wiggleMaxLength(vector<int> &nums) {
        // 上涨代表 flag = 1， 下降 flag = -1
        int flag = 0, count = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > nums[i - 1] && (flag == 0 || flag == -1)) {
                flag = 1;
                count++;
            } else if (nums[i] < nums[i - 1] && (flag == 0 || flag == 1)) {
                flag = -1;
                count++;
            }
        }

        return nums.size() == 0 ? 0 : count;
    }
};
// @lc code=end

int main() {
    Solution s;
    vector<int> v = {1, 17, 5, 10, 13, 15, 10, 5, 16, 8};
    s.wiggleMaxLength(v);
    return 0;
}

