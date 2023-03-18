#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
using namespace std;
/*
    思路:
    1. 将 string 的每个元素不断入栈
    2. 每次入栈时：
        a. 若该元素与栈顶的元素相等，则弹出该元素
        b. 若该元素与栈顶元素不相等，则入栈
    3. 所有 string 遍历过后
        取中栈中的元素，并翻转
*/
class Solution {
  public:
    string removeDuplicates(string s) {
        cout << s << endl;
        stack<char> st;
        for (char ch : s) {
            if (!st.empty() && ch == st.top()) {
                st.pop();
            } else {
                st.push(ch);
            }
        }

        string result_string = ""; // 字符串赋值不能使用 str[0] 这种
        while (!st.empty()) {
            result_string += st.top();
            st.pop();
        }
        cout << result_string << endl;
        reverse(result_string.begin(),
                result_string.end()); // 结束后需要再翻转一次
        return result_string;
    }

    string removeDuplicates_1(string s) {
        string result_string;
        for (char ch : s) {

            if (!result_string.empty() && ch == *result_string.end()) {
                result_string.push_back(ch);
            } else {
                result_string.pop_back();
            }
        }
        return result_string;
    }
};

int main(int argc, char const *argv[]) {

    Solution s;
    cout << s.removeDuplicates("abbaca");
    return 0;
}
