//
// Created by 86188 on 2023/7/13.
//

#include "../include/user.h"
#include <unordered_set>

using namespace std;

/*
 * 这道题关键：分析时间和空间复杂度
 * 1. 使用 hash 表，空间 O(n) ，时间 O(n)
 * 2. 使用 原地排序，二分或者快排 空间 O(1) ，时间 O(nlog(n))
 * 3. 使用 鸽巢原理，由于题目出现的 n 个数字都在 0~n-1 的范围内。将你每个
 * */

class Solution1 {
public:
    int findRepeatNumber(vector<int> &nums) {
        unordered_set<int> set;
        pair<unordered_set<int>::iterator, bool> res;
        for (auto &i: nums) {
            res = set.insert(i);
            if (!res.second) {
                return i;
            }
        }
    }
};

class Solution {
public:
    int findRepeatNumber(vector<int> &nums) {
        for (auto i: nums) {
            if (nums[abs(i)] < 0) {
                return abs(i);
            } else {
                nums[abs(i)] *= -1;
            }
        }
        // 如果没有在 for 循环中返回，那就代表是 0
        return 0;
    }

};