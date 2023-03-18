#include <iostream>
#include <stack>
using namespace std;

/*
    用栈实现队列，至少需要两个栈
    1. 一个入栈，一个出栈
    2. 当队列出队的时候，
        1. 如果出栈为空，将所有入栈的元素转移到出栈中，在出栈
        2. 如果出栈不为空，则弹出出栈栈顶的元素
*/
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

int main(int argc, char const *argv[]) {
    /* code */
    return 0;
}
