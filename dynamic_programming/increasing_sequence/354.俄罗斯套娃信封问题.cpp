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

    // 单独写一个二分查找算法的函数，会造成时间开销更大，无法通过，需要直接写如 LIS 中
/*
    int has_pos(int target, vector<int> top) {
        int pos = -1;
        int low = 0;
        int high = top.size();
        // 要找到比 target 大的最小的位置
        while (low < high) {
            int mid = (high + low) / 2;
            if (top[mid] >= target) { // 要去左边寻找
                pos = mid;
                high = mid;
            } else { // 中间的数小于等于 mid
                low = mid + 1;
            }
        }
        return pos;
    }
*/

    int lengthOfLIS(vector<int> &nums) {
        // 创建牌堆
        vector<int> top;
        for (auto &i: nums) {
            if (top.empty()) {
                top.push_back(i);
            } else {
                // 查找是否有合适的位置
                int pos = -1;
                int low = 0;
                int high = top.size();
                // 要找到比 target 大的最小的位置
                while (low < high) {
                    int mid = (high + low) / 2;
                    if (top[mid] >= i) { // 要去左边寻找
                        pos = mid;
                        high = mid;
                    } else { // 中间的数小于等于 mid
                        low = mid + 1;
                    }
                }
                if (pos == -1) { // 没有合适的位置
                    top.push_back(i);
                } else { // 有合适的位置
                    top[pos] = i;
                }
            }
        }
        return top.size();
    }

public:
    int maxEnvelopes(vector<vector<int>> &envelopes) {
        int n = envelopes.size();
        // 按宽度升序排列，如果宽度一样，则按高度降序排列
        sort(envelopes.begin(), envelopes.end(),
             [](vector<int> &a, vector<int> &b) {
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

