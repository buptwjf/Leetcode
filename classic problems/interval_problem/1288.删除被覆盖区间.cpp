/*
 * @lc app=leetcode.cn id=1288 lang=cpp
 *
 * [1288] 删除被覆盖区间
 */

// @lc code=start
/*
    思路：
    1. 将各个区间进行排序，根据区间左边，从小到大排列
    2. 三种情况
        2.1 b[0] >= a[0] b[1] > a[1] 合并区间
        2.2 b[0] >= a[0] b[1] <= a[1] 删除区间
        2.3 b[0] > a[1] 完全不想交，更新区间

 */
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
  public:
    int removeCoveredIntervals(vector<vector<int>> &intervals) {
        sort(intervals.begin(), intervals.end(),
             [](vector<int> &a, vector<int> &b) {
                 return a[0] == b[0] ? b[1] < a[1] : a[0] < b[0];
             });
        vector<int> res;
        res.push_back(intervals[0][0]);
        res.push_back(intervals[0][1]);

        int sub = 0;
        for (int i = 1; i < intervals.size(); i++) {
            // 这个要先写
            if (intervals[i][0] >= res[0] && intervals[i][1] <= res[1]) {
                sub++;
            } else if (intervals[i][0] <= res[1] &&
                       intervals[i][1] > res[1]) { // 合并区间
                res[1] = intervals[i][1];           // 更新区间右边
            } else {
                res[0] = intervals[i][0];
                res[1] = intervals[i][1];
            }
        }
        return intervals.size() - sub;
    }
};
// @lc code=end
