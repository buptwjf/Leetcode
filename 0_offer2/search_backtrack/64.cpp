//
// Created by 86188 on 2023/7/22.
//
#include "../include/user.h"

using namespace std;

/*
 * 问题：求 1+2+...+4+n
 * 思路：递归
 * */
class Solution {
public:
    int dfs(int i) {
        if (i == 1) {
            return 1;
        }
        int sum = i + dfs(i - 1);
        return sum;
    }

    int sumNums(int n) {
        return dfs(n);
    }
};