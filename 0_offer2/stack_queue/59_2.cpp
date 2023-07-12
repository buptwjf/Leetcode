//
// Created by 86188 on 2023/7/12.
//

#include "../include/user.h"

using namespace std;

/* 目的：设计一个数据结构，得到队列里的最大值，要求函数max_value、push_back 和 pop_front 的均摊时间复杂度都是O(1)。
 * 思路：
 * 内部包含一个 queue，负责正常的入队出队操作， 一个 deque 负责维护最大值
 * */

// 定义最大队列
class MaxQueue {
private:
    queue<int> q;
    deque<int> q_max;
public:
    MaxQueue() {

    }

    int max_value() {
        return q_max.front();
    }

    void push_back(int value) {
        if (q.empty() || (value > q_max.front())) {
            q_max.clear();
            q_max.push_back(value);
        } else {
            while (q_max.back() >= value) {
                q_max.pop_back();
            }
        }
        q.push(value);

    }

    int pop_front() {
        if (q.empty()) {
            return -1;
        } else {
            if (q.front() == q_max.front()) {
                q_max.pop_front();
            }
            int front = q.front();
            q.pop();
            cout << "pop" << endl;
            return front;
        }
    }
};