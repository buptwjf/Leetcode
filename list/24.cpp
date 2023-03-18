#include "List.hpp"

class Solution {
  public:
    ListNode *swapPairs(ListNode *head) {

        // 设置虚拟头结点
        ListNode *dummyHead = new ListNode(0);
        dummyHead->next = head;
        // dummyHead = head;

        ListNode *cur = dummyHead;
        // 当链表为空，或者链表只有一个节点
        while (cur->next != nullptr && cur->next->next != nullptr) {
            ListNode *tmp1 = cur->next->next->next;
            ListNode *tmp2 = cur->next;

            
            cur->next = cur->next->next;    // 步骤一
            cur->next->next = tmp2;          // 步骤二
            cur->next->next->next = tmp1;   // 步骤三

            cur = cur->next->next;
        }
        return dummyHead->next;
    }
};


void printList(ListNode* head){
    ListNode* cur = head;
    while (cur!=nullptr)
    {
        cout << "->" << cur->val << " ";
        cur = cur->next;
    }
    cout << "\n";    
}


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
    ListNode* head1 = s.swapPairs(list1._head->next);

    printList(head1);
    return 0;
}
