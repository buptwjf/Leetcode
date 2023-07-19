//
// Created by 86188 on 2023/7/13.
//

#include "../include/user.h"

using namespace std;

/*
 * 问题：找出缺失的数字
 * 思路：利用二分法判断
 *      如果 nums[mid] == mid 则 缺失的数在 mid 的右边
 *      如果 nums[mid] != mid 则 缺失的数在 mid 的左边
 * */


class Solution {
public:
    int missingNumber(vector<int> &nums) {
        int lo = 0;
        int hi = nums.size() - 1;
        // 写二分法的最好方法是自己模拟，因为边界条件太细微了
        while (lo <= hi) {
            int mi = lo + (hi - lo) / 2;
            if (mi == nums[mi]) { // 缺失的数在 mid 的右边
                lo = mi + 1;
            } else if (mi != nums[mi]) {
                hi = mi - 1;
            }
        }
        return lo;
    }
};


int main() {
    Solution s;
    vector<int> v = {0, 1, 3};
    s.missingNumber(v);
    return 0;
}