#include <iostream>
#include <queue>
using namespace std;

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
            false;
        }
    }
};