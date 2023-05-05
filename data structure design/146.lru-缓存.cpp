/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存
 */
#include <deque>

#include <unordered_map>

using namespace std;

// @lc code=start

struct Cache {
    int _key;
    int _value;

    Cache(int key, int value) : _key(key), _value(value) {};
};

class LRUCache {
private:
    unsigned int capacity;
    deque<Cache> q;
    unordered_map<int, int> map;
public:
    LRUCache(int num) {
        capacity = num;
    }

    int get(int key) {
        unordered_map<int, int>::iterator i = map.find(key);
        if (i == map.end()) {
            return -1;
        } else {
            return i->second;
        }
    }

    void put(int key, int value) {
        unordered_map<int, int>::iterator i = map.find(key);
        if (i == map.end()) {
            if (q.size() == capacity) { // 当队列已经满了
                q.pop_back(); // 逐出最久未使用的元素
            }
            c = Cache(key, value);
            q.pop_front(c);
            map.insert(make_pair(key, value));
        } else {

        }
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

