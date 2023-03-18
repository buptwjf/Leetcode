#include <iostream>
#include <stack>
#include <string>
using namespace std;

/*
    思路：
    1. 每遇到左括号则入栈
    2. 没遇到右括号的时候，判断匹不匹配，
        a. 若匹配则出栈
        b. 若不匹配，或者栈
        为空则失败
*/
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

int main(int argc, char const *argv[])
{
    string s1 = "[]{}()[]";
    cout << s1[0] << endl;
    Solution s;
    cout << s.isValid(s1);
    return 0;
}
