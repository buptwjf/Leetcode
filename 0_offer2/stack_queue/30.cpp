//
// Created by 86188 on 2023/7/12.
//
#include "../include/user.h"

using namespace std;


/*
 * 分析： 这个问题的难度在于，这个元素是当前最小的元素，并且它出栈时，如何找到栈中剩下的元素，最小的值
 * 思路： 需要有另外一个与之形状相同的栈来记录当前元素入栈时候，这个栈中最小的元素
 * 执行用时：有改进空间
 *
 *
 * 本题的核心其实是一个最小栈问题：
 * 最小栈和最小队列都类似，最小栈的 top 是最值， 最大队列的 front 是最值
 * */
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int x) {
        if (st.empty()) {
            stMin.push(x);
            st.push(x);
        } else {
            int ele = x <= stMin.top() ? x : stMin.top();
            st.push(x);
            stMin.push(ele);
        }
    }

    void pop() {
        if (st.empty()) {
            exit(-1);
        } else {
            st.pop();
            stMin.pop();
        }

    }

    int top() {
        return st.top();
    }

    int min() {
        return stMin.top();
    }

private:
    stack<int> st;
    stack<int> stMin; // 记录当前栈中最小的元素
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */