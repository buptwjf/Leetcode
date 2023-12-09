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
#include <list>

struct ListNode {
    int val;
    ListNode *next;

    ListNode();

    ListNode(int val) : val(val), next(nullptr) {}


    ListNode(int val, ListNode *next) : val(val), next(next) {}
};


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}

    TreeNode(int val, TreeNode *leftChild, TreeNode *rightChild) : val(val), left(leftChild), right(rightChild) {}

};

class Node {
public:
    int val;
    Node *left;
    Node *right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node *_left, Node *_right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

#endif //LEETCODE_USER_H
