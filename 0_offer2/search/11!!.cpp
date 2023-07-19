//
// Created by 86188 on 2023/7/14.
//
#include "../include/user.h"

using namespace std;

/*
 * 思路使用二分法，
 * 当 mi > lo  时， lo = mi
 * 当 mi < lo  时,  hi = mi
 * */
class Solution {
public:
    int minArray(vector<int> &numbers) {
        int lo = 0;
        int hi = numbers.size() - 1;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (numbers[mid] > numbers[hi]) {
                lo = mid + 1;
            } else if (numbers[mid] < numbers[hi]) {
                hi = mid;
            } else if (numbers[mid] == numbers[hi]) {
                hi--; // hi-- 的后果就会导致下一轮的 mid 也会 --
            }

        }
        return numbers[lo];
    }
};

int main() {
    Solution s;
    vector<int> v = {3, 4, 5, 1, 2};
    cout << s.minArray(v);
    return 0;
}