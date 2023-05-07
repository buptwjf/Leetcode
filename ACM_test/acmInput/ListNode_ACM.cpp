//
// Created by 86188 on 2023/4/26.
//
//
// Created by 86188 on 2023/4/21.
//

#include <iostream>

struct ListNode {
    int _val;
    ListNode *_next;

    // 默认构造函数
    ListNode() : _val(0), _next(nullptr) {}

    // 有参构造函数
    ListNode(int val) : _val(val), _next(nullptr) {}

    ListNode(int val, ListNode *next) : _val(val), _next(next) {}

    void showListNode();
};


#include <vector>

namespace TestList {

    /*
     * 使用 vector 创建一个 List
     */
    ListNode *creatListByVector(const std::vector<int> &vec) {
        // 使用虚拟头节点，但是对外界来说不知道有这个头结点
        ListNode *dummyHead = new ListNode(-1);
        ListNode *pre = dummyHead;
        for (auto i: vec) {
            ListNode *cur = new ListNode(i);
            pre->_next = cur;
            pre = cur;
        }
        return dummyHead->_next;
    }

    /*
     * 使用 cin 创建一个 List
     * 1 2 3 4 5
     */
    ListNode *creatListByCin() {
        // 使用虚拟头节点，但是对外界来说不知道有这个头结点
        ListNode *dummyHead = new ListNode(-1);
        ListNode *pre = dummyHead;
        int val;
        while (std::cin >> val) {
            ListNode *cur = new ListNode(val);
            pre->_next = cur;
            pre = cur;
            if(getchar() == '\n'){ // getchar() 很重要
                break;
            }
        }
        return dummyHead->_next;
    }

    // 输出显示 List
    void showList(const ListNode *head) {
        while (head->_next) {
            std::cout << head->_val << "->";
            head = head->_next;
        }
        std::cout << head->_val << std::endl;
    }
}


int main() {
    std::vector<int> v = {1, 2, 3, 4};

//    ListNode *L1 = TestList::creatListByVector(v);
    ListNode *L1 = TestList::creatListByCin();
    TestList::showList(L1);

    return 0;
}