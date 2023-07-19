//
// Created by 86188 on 2023/7/17.
//
/*
 *需求：只出现一次的数字
 * 方法：可以用 unordered_map 或者 用一个数组作为哈希表
 **/

#include "../include/user.h"

using namespace std;

class Solution {
public:
    char firstUniqChar(string s) {
        if (s.empty()) {
            return ' ';
        }
        int count[26] = {0};
        for (auto c: s) {
            count[c - 'a']++;
        }

        for (auto c: s) {
            if (count[c - 'a'] == 1) {
                return c;
            }
        }
        return ' ';
    }
};


int main() {
    string s = "leetcode";
    Solution s1;
    s1.firstUniqChar(s);
    return 0;
}