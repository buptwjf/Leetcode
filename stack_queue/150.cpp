#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

/*
    逆波兰表达式求值

    1. 将表达式依次入栈
    2. 当遇到数字时，入栈
    3. 当遇到运算符号时，弹出栈中的两个元素，与运算符进行计算，然后压入栈
*/

class Solution {
  public:
    int evalRPN(vector<string> &tokens) {

        stack<int> stk;
        int op1, op2;
        for (string str : tokens) {
            if (str == "+") {
                op1 = stk.top();
                stk.pop();
                op2 = stk.top();
                stk.pop();
                stk.push(op1 + op2);
                cout << stk.top() << endl;
            } else if (str == "-") {
                op1 = stk.top();
                stk.pop();
                op2 = stk.top();
                stk.pop();
                stk.push(op2 - op1);
                cout << stk.top() << endl;

            } else if (str == "*") {
                op1 = stk.top();
                stk.pop();
                op2 = stk.top();
                stk.pop();
                stk.push(op1 * op2);
                cout << stk.top() << endl;

            } else if (str == "/") {
                op1 = stk.top();
                stk.pop();
                op2 = stk.top();
                stk.pop();
                stk.push(op2 / op1);
                cout << stk.top() << endl;

            } else {
                op1 = stoi(str);
                stk.push(op1);
            }
        }
        return stk.top();
    }
};

int main(int argc, char const *argv[]) {
    Solution s;
    vector<string> v = {"4", "13", "5", "/", "+"};
    cout << s.evalRPN(v);
    return 0;
}