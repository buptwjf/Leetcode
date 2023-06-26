//
// Created by 86188 on 2023/6/25.
//
// 调整数组顺序使奇数位于偶数前面
class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        partition(nums.begin(), nums.end(), [](const int n){ return n&1; });
        return nums;
    }
};