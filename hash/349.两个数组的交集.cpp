/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] 两个数组的交集
 */

// @lc code=start
class Solution {  // 使用 hash 表来存储
  public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
        unordered_set<int> result_set; // 存放结果
        unordered_set<int> nums_set(nums1.begin(), nums1.end()); // 用 num1 初始化 unordered_set
        for (int num : nums2) { // 对 nums2 中的元素遍历
            if (nums_set.find(num) != nums_set.end()) { // 找到了这个元素
                result_set.insert(num);                 // 加入列表
            }
        }
        return vector<int>(result_set.begin(), result_set.end());
    }
};

// @lc code=end
