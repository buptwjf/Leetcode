//
// Created by 86188 on 2023/7/25.
//

#include "../include/user.h"

using namespace std;

/*
 * 问题：全排列不去重问题
 * 思路：套用最简单的回溯框架
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
        vector<bool> used = vector(size, false);
        backtrack(s, used);
        return res;
    }

    void backtrack(string s, vector<bool> used) {
        if (path.size() == this->size) {
            res.push_back(path);
        }
        for (int i = 0; i < size; i++) {
            if (used[i]) {
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