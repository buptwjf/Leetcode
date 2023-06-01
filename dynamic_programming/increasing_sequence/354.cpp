/*
 * @lc app=leetcode.cn id=354 lang=cpp
 *
 * [354] 俄罗斯套娃信封问题
 */

// @lc code=start
/*
 * 思路：最长递增子序列
 * 首先根据 W，从小到大排序，然后对相同 W 的 H 按照从大到小排列
 */

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
private:
    int lengthOfLIS(vector<int> &nums) {
        // 创建并初始化 dp[]
        vector<int> dp(nums.size(), 1);
        for (int i = 0; i < nums.size(); i++) {
            // 找出小于 nums[i] 的元素
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1); // 精髓！！
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }

public:
    int maxEnvelopes(vector<vector<int>> &envelopes) {
        int n = envelopes.size();
        // 按宽度升序排列，如果宽度一样，则按高度降序排列
        sort(envelopes.begin(), envelopes.end(),
             [](vector<int>& a, vector<int>& b) {
                 return a[0] == b[0] ?
                        b[1] < a[1] : a[0] < b[0];
             });
        // 对高度数组寻找 LIS
        vector<int> height(n);
        for (int i = 0; i < n; i++)
            height[i] = envelopes[i][1];

        return lengthOfLIS(height);
    }

};
// @lc code=end
int main() {
    Solution s;
    vector<vector<int>> v = {{{5, 4}, {6, 4}, {6, 7}, {2, 3}}};
    s.maxEnvelopes(v);
}
