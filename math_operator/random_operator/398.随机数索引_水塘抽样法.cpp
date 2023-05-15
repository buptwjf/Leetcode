/*
 * @lc app=leetcode.cn id=398 lang=cpp
 *
 * [398] 随机数索引
 */

// @lc code=start
#include <vector>
#include <random>
using namespace std;

/*
 * 水塘抽样法：
 *      空间 O(1)， 每次取随机数 时间 O(n)
 * 遍历 nums，当我们第 i 次遇到值为 target, target 的元素时，
 * 随机选择区间 [0,i) 内的一个整数，
    如果其等于 0，则将返回值置为该元素的下标，否则返回值不变。
 * 
 * hash表/数组法：
 *      空间 O(n), 每次取随机数 时间 O(1)
 *
 */
class Solution {
    vector<int> &nums;
public:
    Solution(vector<int> &nums) : nums(nums) {}

    int pick(int target) {
        int ans;
        for (int i = 0, cnt = 0; i < nums.size(); ++i) {
            if (nums[i] == target) {
                ++cnt; // 第 cnt 次遇到 target
                if (rand() % cnt == 0) {
                    ans = i;
                }
            }
        }
        return ans;
    }
};


/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
// @lc code=end

