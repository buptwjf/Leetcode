//
// Created by 86188 on 2023/7/25.
//

#include "../include/user.h"
#include "algorithm"

using namespace std;

/*
 * 问题：全排列去重
 * 思路：首先对输入进行排列，对于同一层的树，如果当前位和前一位一样，并且前一位使用过，那么就不用
 *
 * */
class Solution {
private:
    vector<string> res;
    string path;
    int size;
public:
    vector<string> permutation(string s) {
        res.clear();
        path.clear();
        this->size = s.size();
        // 对输入进行排序
        sort(s.begin(), s.end());
        vector<bool> used = vector(size, false);
        backtrack(s, used);
        return res;
    }

    void backtrack(string s, vector<bool> used) {
        if (path.size() == this->size) {
            res.push_back(path);
        }
        for (int i = 0; i < size; i++) {
            if (used[i] || (i > 0 && s[i] == s[i - 1] && used[i - 1])) {
                // if (used[i] || (i > 0 && s[i] == s[i - 1] && !used[i - 1])) { // 这样写也可以 在树层上去重，效率更高
                continue;
            }
            path.push_back(s[i]);
            used[i] = true;
            backtrack(s, used);
            path.pop_back();
            used[i] = false;
        }
    }
};