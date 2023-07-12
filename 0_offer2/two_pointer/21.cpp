//
// Created by 86188 on 2023/6/25.
//
// 调整数组顺序使奇数位于偶数前面

#include "../include/user.h"
#include <algorithm>

using namespace std;

// 极简方法
// 采用 partition 函数
//class Solution1 {
//public:
//    vector<int> exchange(vector<int>& nums) {
//        partition(nums.begin(), nums.end(), [](const int n){ return n&1; });
//        return nums;
//    }
//};
//


// 快慢指针
// 时间 O(n)， 空间 O(1)
class Solution {
public:
    vector<int> exchange(vector<int> &nums) {
        int slow = 0;
        int fast = 0;
        // 维护 [0, slow) 都是奇数
        while (fast < nums.size()) {
            if (nums[fast] % 2 == 1) { // 奇数
                // 把 fast 的放到 slow
                int tmp = nums[slow];
                nums[slow] = nums[fast];
                nums[fast] = tmp;
                slow++;
            }
            fast++;
        }
        return nums;
    }
};