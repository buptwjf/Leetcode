//
// Created by 86188 on 2023/7/12.
//

#include "../include/user.h"

using namespace std;

/* 目的：为了动态集合中的最值维护问题
 * 思路：采用最大队列维护，最大队列的首个元素是动态集合的最大值，后面以此是动态集合子集合的最大值
 * */
class Solution {

    // 定义最大队列
    class monotonicQueue {
        deque<int> q;
    public:
        // 入队的时候，会删除所有小于自己的元素
        void push(int value) {
            while (!q.empty() && q.back() < value) {
                q.pop_back(); // 需要 pop_back()
            }
            q.push_back(value);
        }

        // pop 元素时，只会删除队首的元素，以此来维护最大队列的稳定性
        void pop(int value) {
            if (value == q.front()) {
                q.pop_front(); // 需要 pop_front()
            }
        }

        int max() {
            return q.front();
        }
    };

public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        vector<int> res;
        monotonicQueue mq;
        for (int i = 0; i < nums.size(); i++) {
            while (i < k - 1) {
                mq.push(nums[i++]);
            }
            mq.push(nums[i]);
            res.push_back(mq.max());
            mq.pop(nums[i - k + 1]);
        }
        return res;
    }
};