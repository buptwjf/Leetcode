/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 */

// @lc code=start
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
            } else if (str == "-") {
                op1 = stk.top();
                stk.pop();
                op2 = stk.top();
                stk.pop();
                stk.push(op2 - op1);

            } else if (str == "*") {
                op1 = stk.top();
                stk.pop();
                op2 = stk.top();
                stk.pop();
                stk.push(op1 * op2);
            } else if (str == "/") {
                op1 = stk.top();
                stk.pop();
                op2 = stk.top();
                stk.pop();
                stk.push(op2 / op1);
            } else {
                op1 = stoi(str);
                stk.push(op1);
            }
        }
        return stk.top();
    }
};
// @lc code=end

