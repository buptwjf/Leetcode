#include "List.hpp"
class Solution {
  public:
    ListNode *removeNthFromStart(ListNode *head, int n) {
        // 需要两个指针
        ListNode *dummyHead = new ListNode();
        dummyHead->next = head;
        ListNode *cur = dummyHead;

        ListNode *before = new ListNode(0);
        while (n--) {
            before = cur;
            cur = cur->next;
        }
        before->next = cur->next;
        delete cur;

        return dummyHead->next;
    }

    // 双指针法 先让 fast 多走 n 步，然后 fast 和 slow 再同时走
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // 虚拟头节点
        ListNode *dummyHead = new ListNode();
        dummyHead->next = head;
        ListNode *fast = dummyHead;
        ListNode *slow = dummyHead;
        while (n--) { // 先让  fast 走 n 步
            fast = fast->next;
        }
        while (fast->next != nullptr) { // 直到 fast 的结尾
            fast = fast->next; // 再一起让fast 和 slow走
            slow = slow->next;
        }
        ListNode* tmp = slow->next;
        slow->next = tmp->next;
        delete tmp;
        return dummyHead->next;
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

    list1.addAtIndex(0, 1);
    list1.printList();

    list1.addAtIndex(1, 2);
    list1.printList();

    list1.addAtIndex(2, 3);
    list1.printList();

    list1.addAtIndex(3, 4);
    list1.printList();

    cout << "======== test =========" << endl;

    Solution s;
    ListNode *head1 = s.removeNthFromEnd(list1._head->next, 2);

    printList(head1);
    return 0;
}
