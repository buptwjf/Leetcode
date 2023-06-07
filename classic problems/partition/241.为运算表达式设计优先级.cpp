/*
 * @lc app=leetcode.cn id=241 lang=cpp
 *
 * [241] 为运算表达式设计优先级
 */

// @lc code=start
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> res;
        for (int i = 0; i < expression.size(); i++) {
            char c = expression[i];
            if (c == '+' || c == '-' || c == '*') {
                vector<int> left = diffWaysToCompute(expression.substr(0, i));
                vector<int> right = diffWaysToCompute(expression.substr(i + 1));
                // 治
                for (int a: left) {
                    for (int b: right) {
                        if (c == '+') {
                            res.push_back(a + b);
                        } else if (c == '-') {
                            res.push_back(a - b);
                        } else {
                            res.push_back(a * b);
                        }
                    }
                }
            }
        }
        // 关键 base case
        if (res.empty()) {
            res.push_back(stoi(expression));
        }
        return res;
    }
};
// @lc code=end

