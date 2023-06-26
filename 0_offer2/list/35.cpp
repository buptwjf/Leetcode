//
// Created by 86188 on 2023/6/24.
//
#include "../include/user.h"

using namespace std;

class Node {
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

// 使用 hash，空间复杂度 O(n)，时间复杂度 O(n)
class Solution {
public:
    Node *copyRandomList(Node *head) {
        unordered_map<Node *, Node *> unorderedMap;
        // 第一个Node* 指向原始的 Node*，第二个Node* 指向新创建的 Node*
        // 第一边遍历，先遍历所有节点
        for (Node *cur = head; cur != nullptr; cur++) {
            if(unorderedMap.find(cur)!=unorderedMap.end()){ // 防止重复创建节点
                unorderedMap[cur] = new Node(cur->val);
            }
        }
        for (Node *cur = head; cur != nullptr; cur++) {
            // 建立对应关系
            if (cur->next != nullptr) {
                unorderedMap[cur]->next = unorderedMap[cur->next];
            }
            if (cur->random != nullptr) {
                unorderedMap[cur]->random = unorderedMap[cur->random];
            }
        }
        return unorderedMap[head];
    }
};