#include <iostream>
using namespace std;
#include "List.hpp"

class Solution {
  public:
    ListNode *reverseList(ListNode *head) {

        // 关键是初始化
        ListNode *cur = head;  
        ListNode *pre = nullptr;
        ListNode *tmp;

        // 以及停止条件
        while (cur != nullptr) {
            tmp = cur->next;
            cur->next = pre;
            
            pre = cur;
            cur = tmp;
        }
        return pre;
    }


    ListNode *reverse(ListNode *pre, ListNode* cur) {
        if(cur == NULL){
            return pre;
        }
        ListNode* tmp = cur->next;
        cur->next = pre;
        return reverse(cur, tmp);
    }

    ListNode *reverseList_r(ListNode *head) {   // 采用递归方法
        return reverse(NULL, head);
    }
};



int main(int argc, char const *argv[]) {
    MyLinkedList list1;
    if (list1._head == NULL) {
        cout << "NULL" << endl;
    } else {
        cout << " 1111" << endl;
    }

    cout << "======== test =========" << endl;
    // list1.addAtHead(1);
    list1.printList();

    // list1.addAtTail(3);
    // list1.printList();

    list1.addAtIndex(0, 10);
    list1.printList();

    list1.addAtIndex(0, 20);
    list1.printList();

    list1.addAtIndex(1, 30);
    list1.printList();
    cout << "======== test =========" << endl;
    list1.get(0);

    return 0;
}
