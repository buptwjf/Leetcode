/*
 * @lc app=leetcode.cn id=986 lang=cpp
 *
 * [986] 区间列表的交集
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
  public:
    vector<vector<int>> intervalIntersection(vector<vector<int>> &firstList,
                                             vector<vector<int>> &secondList) {
        if (firstList.empty() || secondList.empty()) {
            return {};
        }

        vector<vector<int>> res;
        int i = 0;
        int j = 0; // 指向两个列表的指针
        while (i < firstList.size() && j < secondList.size()) {
            vector<int> A = firstList[i];
            vector<int> B = secondList[j];
            int a0 = A[0];
            int a1 = A[1];
            int b0 = B[0];
            int b1 = B[1];
            /* 
                由于不存在交集的情况为
                b1 < a0 || b0 > a1 
                对此取反则是存在交集的情况
                b1 >= a0 && b0 <= a1
             */
            if (b1 >= a0 && b0 <= a1) { // 存在交集的情况
                int left = max(a0, b0);
                int right = min(a1, b1);
                res.push_back({left, right});
            }
            if (b1 >= a1) {
                i++;
            } else {
                j++;
            }
        }
        return res;
    }
};
// @lc code=end
