/*
 * @lc app=leetcode.cn id=455 lang=cpp
 *
 * [455] 分发饼干
 */

// @lc code=start
/*
 * g 是胃口值，s 是饼干的值，返回能满足几个小孩
 * 思路：
 *  1. 排序
 *  2. 双指针法
 *
 *
 * */
#include <vector>
#include <functional>

using namespace std;

class Solution {
public:
    int findContentChildren(vector<int> &g, vector<int> &s) {
        sort(g.begin(), g.end(), greater());  // 从大到小排
        sort(s.begin(), s.end(), greater());  // 从大到小排

        int result = 0;
        int j = 0;
        int i = 0;
        while (i < g.size() && j < s.size()) {
            if (g[i] <= s[j]) { // 饼干满足
                result++;
                i++;
                j++;
            } else {
                i++;
            }
        }
        return result;
    }

};
// @lc code=end

int main() {
    vector<int> g = {1, 2, 3};


    vector<int> s = {1, 2};
    Solution s1;
    s1.findContentChildren(g, s);

    return 0;
}