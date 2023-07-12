//
// Created by 86188 on 2023/6/23.
//

#ifndef LEETCODE_USER_H
#define LEETCODE_USER_H
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <deque>
#include <queue>
struct ListNode {
    int val;
    ListNode *next;

    ListNode();

    ListNode(int val) : val(val), next(nullptr) {}

    ListNode(int val, ListNode *next) : val(val), next(next) {}
};
#endif //LEETCODE_USER_H
