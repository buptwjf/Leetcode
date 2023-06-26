//
// Created by 86188 on 2023/6/24.
//
// 删除列表中倒数第 k 个节点

#include "../include/user.h"

using namespace std;

class Solution {
public:
    ListNode *getKthFromEnd(ListNode *head, int k) {
        // 双指针
        ListNode *latter; // 后指针
        latter = head;
        ListNode *former; // 前指针个指针
        former = head;
        while (k > 0) { //
            if (former != nullptr) {
                former = former->next;
                k--;
            } else {
                return nullptr;
            }
        }

        while(former!= nullptr){
            former = former->next;
            latter = latter->next;
        }
        return latter;
    }
};