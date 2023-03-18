#include "List.hpp"

class Solution {
  public:
    ListNode *detectCycle(ListNode *head) {
        // 初始化两个指针
        ListNode *fast;
        ListNode *slow;

        fast = head;
        slow = head;

        while (fast->next != nullptr && fast->next->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
            if (slow == fast) { // 两个指针重合
                ListNode *cur1 = head;
                ListNode *cur2 = fast;

                while (cur1 != cur2) {
                    cur1 = cur1->next;
                    cur2 = cur2->next;
                }
                return cur2;
            }
        }
        return nullptr;
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
    ListNode *head1 =
        s.getIntersectionNode(list1._head->next, list2._head->next);

    printList(head1);
    return 0;
}
