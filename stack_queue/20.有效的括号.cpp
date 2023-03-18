/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution {
  public:
    bool isValid(string s) {
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '{' || s[i] == '[' || s[i] == '(') {
                st.push(s[i]);
            } else {
                if (st.empty()) {
                    return false;
                } else {
                    if (s[i] == '}' && st.top() == '{') {
                        st.pop();
                        continue;
                    } else if (s[i] == ']' && st.top() == '[') {
                        st.pop();
                        continue;
                    } else if (s[i] == ')' && st.top() == '(') {
                        st.pop();
                        continue;
                    } else {
                        return false;
                    }
                }
            }
        }
        return st.empty() ? true : false;
    }
};
// @lc code=end
