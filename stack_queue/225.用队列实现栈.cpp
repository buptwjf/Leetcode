/*
 * @lc app=leetcode.cn id=225 lang=cpp
 *
 * [225] 用队列实现栈
 */

// @lc code=start
class MyStack {
  public:
    queue<int> q;
    MyStack() {}

    void push(int x) { q.push(x); }

    int pop() {
        int temp;
        for (int i = 0; i < q.size() - 1; i++) {
            temp = q.front();
            q.pop();
            q.push(temp);
        }
        temp = q.front();
        q.pop();
        return temp;
    }

    int top() {
        int top = this->pop();
        this->push(top);
        return top;
    }

    bool empty() {
        if (q.empty()) {
            return true;
        } else {
            return false;
        }
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end

