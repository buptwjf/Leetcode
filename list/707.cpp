#include <iostream>
using namespace std;



// 单链表写的时候一定注意不能越界

class MyLinkedList { // 设计单链表
  public:
    // 引入 ListNode 结构体
    struct ListNode {
        int val;
        ListNode *next;

        // ListNode 构造函数
        ListNode() : val(0), next(nullptr){};
        ListNode(int x) : val(x), next(nullptr){};
        ListNode(int x, ListNode *next) : val(x), next(next){};
    };

    // 构造函数
    MyLinkedList();

    // 获取第 Index 的值 [0， size)
    int get(int index);

    // 在头部插入
    void addAtHead(int val);

    // 在尾部插入
    void addAtTail(int val);

    // 在第index个节点之前插入一个新节点，例如index为0，那么新插入的节点为链表的新头节点。
    // 如果index 等于链表的长度，则说明是新插入的节点为链表的尾结点
    // 如果index大于链表的长度，则返回空
    // 如果index小于0，则在头部插入节点
    void addAtIndex(int index, int val);

    // 删除第index个节点，如果index
    // 大于等于链表的长度，直接return，注意index是从0开始的
    void deleteAtIndex(int index);

    void printList() const;

    //   private:
    ListNode *_head; // 头结点
    int _size;       // 列表长度
};

// 构造函数
inline MyLinkedList::MyLinkedList() {

    _head = new ListNode();
    _size = 0;
}

// 根据索引返回值，返回第 index 个元素
inline int MyLinkedList::get(int index) {
    if (0 <= index <= _size) {
        ListNode *cur = _head->next;
        while (index--) {
            cur = cur->next;
        }
        cout << cur->val << endl;
        return cur->val;
    } else {
        return -1;
    }
}

//  打印链表
inline void MyLinkedList::printList() const {
    ListNode *cur = _head;
    while (cur->next != nullptr) {
        cout << "->" << cur->next->val;
        cur = cur->next;
    }
    cout << endl;

    // 第二种写法
    // ListNode *cur = _head;
    // int num = _size;
    // cout << "_size = " << _size << "\t";
    // while (num--) {
    //     cout << "->" << cur->next->val;
    //     cur = cur->next;
    // }
    // cout << endl;
}

// 在 head 之前添加一个新节点作为首节点
inline void MyLinkedList::addAtHead(int val) {
    ListNode *first = new ListNode();
    first->val = val;
    first->next = _head->next;
    _head->next = first;
    _size++;
}


// 在链表最后面添加一个节点
inline void MyLinkedList::addAtTail(int val) {
    ListNode *last = new ListNode(val, nullptr);
    ListNode *cur = _head;
    while (cur->next != nullptr) {
        cur = cur->next;
    }
    cur->next = last;
    _size++;
}

// 在链表中的第 index 个节点之前添加值为 val  的节点
inline void MyLinkedList::addAtIndex(int index, int val) {
    if (index > _size) {
        cout << "error" << endl;
    } else {
        ListNode *cur = _head;
        ListNode *new_node = new ListNode(val);

        if (index < 0) { // 在头部插入
            new_node->next = _head->next;
            _head->next = new_node;
            _size++;
        } else {
            // head 0 1 2 x 3
            while (index--) { // 找到第 index - 1 个
                cur = cur->next;
            }
            new_node->next = cur->next;
            cur->next = new_node;
            _size++;
        }
    }
}

inline void MyLinkedList::deleteAtIndex(int index) {
    ListNode *cur = _head;
    if (index < _size) {
        while (index--) { // 找到它的前一个
            cur = cur->next;
        }
        ListNode *tmp = cur->next;
        cur->next = cur->next->next;
        delete tmp;
        _size--;
    } else {
        cout << "error" << endl;
    }
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

    // list1.get(1);
    // list1.printList();

    // list1.deleteAtIndex(1);
    // list1.printList();

    // list1.get(1);
    // cout << "-------" << endl;
    // list1.printList();

    return 0;
}
