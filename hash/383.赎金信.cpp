/*
 * @lc app=leetcode.cn id=383 lang=cpp
 *
 * [383] 赎金信
 */

// @lc code=start
class Solution {
  public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<int, int> map;

        // 统计 magazine 的字符数
        for (auto ch : magazine) {
            if (map.find(ch- 'a') == map.end()) { // 如果没有
                map.insert(pair<int, int>(ch- 'a', 1));
            } else { // 如果有
                map[ch- 'a']++;
            }
        }
        for (auto ch : ransomNote) {
            if (map.find(ch-'a') == map.end()) { // 如果没有
                return false;
            } else {
                map[ch-'a']--;
            }
        }

        for (int i = 0; i < map.size(); i++) {
            if (map[i] < 0) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
