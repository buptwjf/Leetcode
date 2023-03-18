/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] 用栈实现队列
 */

// @lc code=start
class MyQueue {
  public:
    stack<int> stIn;
    stack<int> stOut;
    MyQueue() {}

    void push(int x) { stIn.push(x); }

    int pop() {
        // 如果出栈为空，将所有入栈的元素转移到出栈中，再出栈
        if (stIn.empty() && stOut.empty()) {
            return -1;
        } else {
            if (stOut.empty()) {
                int temp;
                while (!stIn.empty()) {
                    temp = stIn.top();
                    stIn.pop();
                    stOut.push(temp);
                }
                temp = stOut.top();
                stOut.pop();
                return temp;
            } else {
                int temp = stOut.top();
                stOut.pop();
                return temp;
            }
        }
    }

    int peek() {
        int temp = this->pop();
        stOut.push(temp);
        return temp;
    }

    bool empty() {
        if (stIn.empty() && stOut.empty()) {
            return true;
        } else {
            return false;
        }
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end

