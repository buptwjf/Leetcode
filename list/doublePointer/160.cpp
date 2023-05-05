#include "..\List.hpp"
#include <cmath>

class Solution {
  public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // 分别计算两个链表的长度
        int sizeA = 0;
        int sizeB = 0;

        ListNode *curA = headA;
        ListNode *curB = headB;
        while (curA!= nullptr) {
            sizeA++;
            curA = curA->next;
        }
        cout << "sizeA" << sizeA << endl;

        while (curB != nullptr) {
            sizeB++;
            curB = curB->next;
        }
        cout << "sizeB" << sizeB << endl;


        curA = headA;
        curB = headB;
        int diff = sizeA - sizeB;
        int diff_abs = abs(diff);
        cout << "diff_abs" << diff_abs << endl;
        if (diff >= 0) { // A 大
            while (diff_abs--) {
                curA = curA->next;
            }
        } else {
            while (diff_abs--) {
                curB = curB->next;
            }
        }

        // 一起走
        while (curA != nullptr) {
            if (curA == curB) {
                return curA;
            }
            curA = curA->next;
            curB = curB->next;
        }
        return NULL;
    }
};

int main(int argc, char const *argv[]) {
    MyLinkedList list1;

    cout << "======== test =========" << endl;
    list1.addAtIndex(0, 1);
    list1.addAtIndex(1, 2);
    list1.addAtIndex(2, 3);
    list1.addAtIndex(3, 4);
    list1.addAtIndex(4, 5);
    list1.printList();


    MyLinkedList list2;
    cout << "======== test =========" << endl;
    list2.addAtIndex(0, 1);
    list2.addAtIndex(1, 2);
    list2.addAtIndex(2, 3);
    list2.printList();
    cout << "======== test =========" << endl;

    Solution s;
    ListNode *head1 = s.getIntersectionNode(list1._head->next, list2._head->next);

    printList(head1);
    return 0;
}