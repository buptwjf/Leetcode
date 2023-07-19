//
// Created by 86188 on 2023/7/13.
//

#include "../include/user.h"

using namespace std;

/*
 * 问题：比较压入栈和压出栈是否一致
 * 方法：将 pushed 依次压入一个栈中，每入一次栈对比一下，出栈的元素，如果一样，则 pop 出来
 * */
class Solution {
public:
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped) {
        if (pushed.empty() && popped.empty()) {
            return true;
        }
        stack<int> st;
        int i = 0;
        int j = 0;
        st.push(pushed[i++]);
        while (j < popped.size()) {
            if (!st.empty() && st.top() == popped[j]) {
                st.pop();
                j++;
            } else {
                if (i == pushed.size()) {
                    break;
                }
                st.push(pushed[i++]);
            }
        }
        if (!st.empty()) {
            return false;
        } else {
            return true;
        }
    }
};


int main() {
    vector<int> pushed = {0, 1};
    vector<int> popped = {0, 1};
    Solution s;
    s.validateStackSequences(pushed, popped);
    return 0;
}