//
// Created by 86188 on 2023/6/24.
//
#include "../include/user.h"

using namespace std;

// 普通方法，使用栈
// 时间 O(n) 空间O(n)
class Solution {
public:
    vector<int> reversePrint(ListNode *head) {
        stack<int> st;
        vector<int> res;
        while (head->val) {
            st.push(head->val);
            head = head->next;
        }
        while (!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }
        return res;
    }
};

// 使用递归栈
// 时间 O(n) 空间 O(1) 只使用系统自身的空间，当数据过大时，不行
class Solution1 {
    vector<int> res;

    void travers(ListNode *head) {
        if (head == nullptr) {
            return;
        }
        travers(head->next);
        res.push_back(head->val);
    }

public:
    vector<int> reversePrint(ListNode *head) {
        res.clear();
        travers(head);
        return res;
    }
};