/*
 * @lc app=leetcode.cn id=541 lang=cpp
 *
 * [541] 反转字符串 II
 */

// @lc code=start
class Solution {
  public:
    string reverseStr(string s, int k) {
        // 隔 2k 翻转
        for (int i = 0; i < s.size(); i += 2 * k) {
            // 1. 每 2k 个字符，对前 k 个字符进行反转
            // 2. 剩余字符小于 2k 但是大于 k
            if (i + k < s.size()) {
                reverse(s.begin() + i, s.begin() + i + k);
            }else{ // 对剩下的所有字符进行反转
                reverse(s.begin()+i, s.end());
            }
        }
        return s;
    }
};
// @lc code=end

