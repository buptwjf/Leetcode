/*
 * @lc app=leetcode.cn id=1047 lang=cpp
 *
 * [1047] 删除字符串中的所有相邻重复项
 */

// @lc code=start
// class Solution {
//   public:
//     string removeDuplicates(string s) {
//         cout << s << endl;
//         stack<char> st;
//         for (char ch : s) {
//             if (!st.empty() && ch == st.top()) {
//                 st.pop();
//             } else {
//                 st.push(ch);
//             }
//         }

//         string result_string = "";  // 字符串赋值不能使用 str[0] 这种
//         while (!st.empty()) {
//             result_string += st.top();
//             st.pop();
//         }
//         cout << result_string << endl;
//         reverse(result_string.begin(), result_string.end()); //
//         结束后需要再翻转一次 return result_string;
//     }
// };

class Solution {
  public:
    string removeDuplicates(string s) {
        string result_string;
        for (char ch : s) {
            if (result_string.empty() ||  ch != result_string.back()) {
                result_string.push_back(ch);
            } else {
                result_string.pop_back();
            }
        }
        return result_string;
    }
};
// @lc code=end
