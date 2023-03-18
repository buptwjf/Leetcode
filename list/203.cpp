/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;

// 自定义 ListNode
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void printList(ListNode *const head);

class Solution {
  public:
    ListNode *removeElements(ListNode *head, int val) {
        // 删除头结点，确保得到第一个满足条件的节点
        while (head != NULL && head->val == val) {
            ListNode *tmp = head;
            head = head->next;
            delete tmp; // 删除内存
        }
        // 删除非头节点 不要从 ListNode* cur = head->next开始
        ListNode *cur = head;
        // 当连链表长度 >= 2 时
        while (cur != NULL && cur->next != NULL) // 一定要确保访问链表有值
        {
            if (cur->next->val == val) {
                ListNode *tmp = cur->next;
                cur->next = cur->next->next;
                delete tmp; // 删除内存
            } else {
                cur = cur->next;
            }
        }
        return head;
    }
};

class Solution1 {
  public:
    ListNode *removeElements(ListNode *head, int val) {

        // 虚拟头节点
        ListNode *dummyHead = new ListNode(0);
        dummyHead->next = head; // 将虚拟节点接到头节点之前
        ListNode* cur = dummyHead;
        while (cur->next != nullptr) {
            if (cur->next->val == val) {
                ListNode* tmp = cur->next;
                cur->next = cur->next->next;
                delete tmp;
            }else{
                cur = cur->next;
            }
        }
        // 删除头节点
        head = dummyHead->next;
        delete dummyHead;
        return head;
    }
};

class Solution2 { // 自己的方法，写法复杂
  public:
    ListNode *removeElements(ListNode *head, int val) {

        while (1) {
            // 当头节点为空，且头节点后没有其他节点
            if (head == NULL) {
                cout << "no data" << endl;
                return head;
            }

            // 删除头节点
            while (head->val == val) {
                cout << "head->val == val" << endl;
                ListNode *tmp = head;
                head = head->next;
                delete tmp;
                printList(head);
            }

            ListNode *a = head->next;

            while (a->val) { // && a->next != nullptr
                if (a->val == val) {
                    if (a->next != nullptr) {
                        ListNode *tmp = a->next; // 记录当前节点
                        a->val = a->next->val;
                        a->next = a->next->next;
                        delete tmp;
                    } else {
                        a = nullptr;
                        return head;
                    }
                } else {
                    if (a->next == nullptr) {
                        return head;
                    } else {
                        a = a->next;
                    }
                }
            }
            return head;
        } /* code */
    }
};

// 打印列表
void printList(ListNode *const head) {
    ListNode *cur = head;
    while (cur != NULL) {
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << endl;
}

// 使用向量构造列表
ListNode *listFromVector(ListNode *head, const vector<int> nums) {
    ListNode *a = new ListNode;
    a = head;
    // cout << "a->val = " << a->val << endl; // 输出 head 的内容
    // 构造链表
    for (int i = 0; i < nums.size(); i++) {
        a->next = new ListNode(nums[i]); // 头节点不存放数据
        a = a->next;
        cout << "a[" << i << "]=" << a->val << "\t";
    }
    cout << endl;
    return head;
}

int main(int argc, char const *argv[]) {
    // 创建链表
    vector<int> v = {1, 2, 3, 3, 4, 5, 6};
    vector<int> v1 = {6, 2, 6, 3, 4, 5, 6};
    vector<int> v2 = {6, 6, 6, 6};

    ListNode *head = new ListNode(0);

    cout << "head->val = " << head->val << endl;
    head = listFromVector(head, v);

    // 输出列表
    printList(head);

    Solution s;
    Solution s1;

    cout << "============== test ================" << endl;
    // head = s.removeElements(head, 6);
    head = s1.removeElements(head, 6);
    printList(head);

    return 0;
}

// @lc code=end
