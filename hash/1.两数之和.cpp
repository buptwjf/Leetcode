/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution {
  public:
    vector<int> twoSum(vector<int> &nums, int target) {
        // 创建 hash 表
        std::unordered_map<int, int> map;
        // 遍历当前元素，并寻找是否有匹配的 key
        for (int i = 0; i < nums.size(); i++) {
            auto iter = map.find(target - nums[i]); // 判断表中是否有此 key
            if (iter != map.end()) {
                return {iter->second, i}; // 如果有，直接返回
            }
            map.insert(pair<int, int>(nums[i], i)); // 如果没有，将当前 数值插入
        }
        return {};
    }
};
// @lc code=end
