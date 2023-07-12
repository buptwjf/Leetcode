//
// Created by 86188 on 2023/6/27.
//


#include "../include/user.h"
#include "algorithm"

using namespace std;

/*
 * 使用 stl 这样时间复杂度为 O(1)， 空间复杂为 O(1)
 * */
class Solution {
public:
    string reverseWords(string s) {
        // 去掉首尾的空格
        while (*s.begin() == ' ') {
            s.erase(s.begin());
        }
        while (*(s.end() - 1) == ' ') {
            s.erase(s.end() - 1);
        }
        // 先去掉重复的空格
        for (auto i = s.begin(); i < s.end(); i++) {
            if (*(i - 1) == ' ' && *i == ' ') {
                s.erase(i);
            }
        }
        // 翻转整个字符串
        reverse(s.begin(), s.end());

        // 操作精细
        // 翻转
        auto start = s.begin();
        while (start != s.end()) {
            auto end = start;
            while (end != s.end() && *end != ' ') {
                end++;
            }
            reverse(start, end);
            start = end;
            if (start != s.end()) {
                start++;
            }
        }
        cout << s << endl;
        return s;
    }
};

int main() {
    Solution s;
    s.reverseWords("   asd asd  as   ");
    return 0;
}