/*
 * @lc app=leetcode.cn id=384 lang=cpp
 *
 * [384] 打乱数组
 */
#include <iostream>
#include <vector>
#include <random>

using namespace std;

/*
 * 这个可以扩展到二维数组上，并放置地雷
 * 做法：
 *      1. 将二维矩阵转化成一维数组
 *      2. 将 K 个地雷，放置在一维数组的前几个上，然后进行一维数组的打乱
 */

// @lc code=start
class Solution {
private:
    vector<int> nums;
    // initialize with random seed
    default_random_engine generator{random_device{}()};

public:
    Solution(vector<int> &nums) {
        this->nums = nums;
    }

    vector<int> reset() {
        return nums;
    }

    // 使用洗牌算法，共能生成 n! 种可能
    // 洗牌算法的前提是可以随机访问的数据结构
    vector<int> shuffle() {
        int n = nums.size();
        vector<int> copy = nums;
        for (int i = 0; i < n; i++) {
            // 生成一个[i, n-1] 的均匀分布
            uniform_int_distribution<int> distribution(i, n - 1);
            // 在均匀分布中随机选一个数
            int r = distribution(generator);
            // 交换 nums[i] 和 nums[r]
            swap(copy[i], copy[r]);
        }
        return copy;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
// @lc code=end

