//
// Created by 86188 on 2023/7/12.
//
#include "../include/user.h"
#include "algorithm"

using namespace std;

/* 用两个栈来模拟队列 */

/*
 * 思路：
 *  1. 入队时候,
 *      st2为空，在st1 push
 *      st2不为空，导入st1，在st1 push
 *  2. 出队时候，
 *      st1为空，在st2 pop
 *      st1不为空，导入到 st2, 在 st2 pop
 * */
class CQueue {
public:
    CQueue() {
    }

    void appendTail(int value) {
        if (st2.empty()) {
            st1.push(value);
        } else {
            while (!st2.empty()) {
                int i = st2.top();
                st1.push(i);
                st2.pop();
            }
            st1.push(value);
        }
    }

    int deleteHead() {
        if (!st2.empty()) {
            int res = st2.top();
            st2.pop();
            return res;
        } else if (!st1.empty()) {
            while (!st1.empty()) {
                int i = st1.top();
                st2.push(i);
                st1.pop();
            }
            int res = st2.top();
            st2.pop();
            return res;
        } else {
            return -1;
        }
    }

private:
    stack<int> st1;
    stack<int> st2;
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */