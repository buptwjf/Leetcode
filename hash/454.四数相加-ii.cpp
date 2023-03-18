/*
 * @lc app=leetcode.cn id=454 lang=cpp
 *
 * [454] 四数相加 II
 */

// @lc code=start
class Solution {
  public:
    int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3,
                     vector<int> &nums4) {
        // 1. 创建 hash map
        unordered_map<int, int> map; // key 放置 A B 的和， value 放置和的次数
        for (int a : nums1) {
            for (int b : nums2) {
                map[a + b]++;
            }
        }

        int count = 0;
        // 遍历 C 和 D 找出他们和的数，看 map 里有没有他
        for (int c : nums3) {
            for (int d : nums4) {
                if (map.find(-(c + d)) != map.end()) {
                    count += map[-(c + d)];
                }
            }
        }
        return count;
    }
};
// @lc code=end
