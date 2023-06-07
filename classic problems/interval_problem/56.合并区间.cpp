/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

// @lc code=start
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
  public:
    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        if (intervals.size() == 0) {
            return {};
        }
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end(),
             [](vector<int> &a, vector<int> &b) { return a[0] < b[0]; });
        int left = intervals[0][0];
        int right = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] <= right && intervals[i][1] >= right) {
                right = intervals[i][1]; // 区间重叠
                continue;
            }
            if (intervals[i][0] >= right) { // 完全不重叠
                res.push_back({left, right});
                left = intervals[i][0];
                right = intervals[i][1];
            }
        }
        // 将最后一个区间加入结果集合
        res.push_back({left, right});
        return res;
    }
};
// @lc code=end
