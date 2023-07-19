//
// Created by 86188 on 2023/7/13.
//
#include "../include/user.h"

using namespace std;

/*
 * 问题：统计一个数字在排序数组中出现次数
 * 思路：两次二分查找，，分别寻找这个数的最小和最大
 * */
class Solution {
public:
    int search(vector<int> &nums, int target) {
        if (nums.empty()) {
            return 0;
        }
        int left = searchLeft(nums, target);
        int right = searchRight(nums, target);
        int num = right - left + 1;
        return num;
    }

    // 找到左界限
    int searchLeft(vector<int> &nums, int target) {
        int lo = 0;
        int hi = nums.size();
        while (lo < hi) {
            int mi = lo + (hi - lo) / 2;
            if (nums[mi] == target) {
                hi = mi; // 这个是关键
            } else if (nums[mi] < target) {
                lo = mi + 1;
            } else if (nums[mi] > target) {
                hi = mi;
            }
        }
        return lo; // 这块需要自己模拟 此时 lo = hi
    }

    int searchRight(vector<int> &nums, int target) {
        int lo = 0;
        int hi = nums.size();
        while (lo < hi) {
            int mi = lo + (hi - lo) / 2;
            if (nums[mi] == target) {
                lo = mi + 1; // 这个是关键
            } else if (nums[mi] < target) {
                lo = mi + 1;
            } else if (nums[mi] > target) {
                hi = mi;
            }
        }
        return hi - 1; // 这块需要自己模拟，此时 lo = hi
    }

};

int main() {
    Solution s;
    vector<int> v = {1, 2, 2, 2, 3, 5, 7};
    s.searchRight(v, 2);
    return 0;
}