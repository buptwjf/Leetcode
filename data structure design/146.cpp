/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存
 */

/*
 * 思路：
 *      使用双向链表记录缓存池，使用 hash 表记录每一个链表节点的位置，做到随机查找
 *      难点：
 *          1. 自己手动实现一个双向链表(暂时没有自己写)
 *          2. 整体数据结构的设计
 *          3. 细节
 *              3.1 每对一个 key 操作，就要提升他的优先级
 */
#include <list>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

// @lc code=start

struct CacheNode {
    int _key;
    int _value;

    CacheNode();

    CacheNode(int key, int value) : _key(key), _value(value) {};
};

class LRUCache {
private:
    unsigned int _capacity;
    list<CacheNode> L;
    unordered_map<int, list<CacheNode>::iterator> map;

public:
    LRUCache(int num) {
        _capacity = num;
    }

    int get(int key) {
        cout << "get" << endl;

        auto i = map.find(key);
        cout << "get1" << endl;

        if (i == map.end()) {
            cout << "get2" << endl;

            return -1;
        } else {
            cout << "get2" << endl;
            cout << "i->first"<< i->first << endl;
            cout << "i->second->_key" << (i->second)->_key << endl;

            cout << "get3" << endl;

            int tmp = i->second->_value;

            L.erase(i->second);
            L.push_back(CacheNode(key, tmp));
            return tmp;
        }
    }

    void put(int key, int value) {
        cout << "put" << endl;

        auto i = map.find(key);
        if (i == map.end()) { // 没有
            if (L.size() == _capacity) { // 缓存池已经满了
                // 删除最久未使用的关键字
                int tmp = L.begin()->_key;
                L.pop_front();

                map.erase(tmp);
                // 插入最新的关键字
                L.push_back(CacheNode(key, value));
                map.insert(make_pair(key, --L.end()));
            } else {
                L.push_back(CacheNode(key, value));
                map.insert(make_pair(key, --L.end()));
            }
        } else { // 存在这个关键字，需要进行修改
            L.erase(i->second);
            L.push_back(CacheNode(key, value));
            map[key] = --L.end();
        }
    }

};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

int main() {
    LRUCache c(2);
    c.put(2, 1);
    c.put(1, 1);
    cout << c.get(2) << endl;
    c.put(4, 1);
    cout << c.get(1) << endl;
    cout << c.get(2) << endl;


    return 0;
}