/*
 * @lc app=leetcode.cn id=459 lang=cpp
 *
 * [459] 重复的子字符串
 */

// @lc code=start
class Solution {
  public:
    bool repeatedSubstringPattern(string s) {
        if (s.size() == 1) {
            return false;
        }
        int next[s.size()];
        getNext(next, s);
        int len = s.size();
        if (next[len-1] != -1 && (len % (len - next[len - 1] - 1)) == 0) {
            return true;
        } else {
            return false;
        }
    }

    void getNext(int *next, string model) {
        int j = -1;
        next[0] = j;

        // i 为子串的后缀，j 为子串的前缀
        for (int i = 1; i < model.size(); i++) {
            while (j >= 0 && model[i] != model[j + 1]) { // 这里是 while
                j = next[j]; // 这里是 next j
            }
            if (model[i] == model[j + 1]) {
                j++;
            }
            next[i] = j;
        }
    }
};
// @lc code=end
