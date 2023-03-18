#include <string>
#include <unordered_map>
using namespace std;

class Solution {
  public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<int, int> map;

        // 统计 magazine 的字符数
        for (auto ch : magazine) {
            if (map.find(ch - 'a') == map.end()) { // 如果没有
                map.insert(pair<int, int>(ch - 'a', 1));
            } else { // 如果有
                map[ch - 'a']++;
            }
        }
        for (auto ch : ransomNote) {
            if (map.find(ch - 'a') == map.end()) { // 如果没有
                return false;
            } else {
                map[ch - 'a']--;
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

// 对代码进行优化
// 使用数组作为 hash 表
class Solution1 {
  public:
    bool canConstruct(string ransomNote, string magazine) {
        int reccord[26] = {0};
        // 统计 magazine 的字符数
        if (ransomNote.size() > magazine.size()) {
            return false;
        }

        for (auto ch : magazine) { // 遍历杂志，得到 hash 表
            reccord[ch - 'a']++;
        }

        for (auto ch : ransomNote) {
            if (reccord[ch - 'a'] == 0) {
                return false;
            } else {
                reccord[ch - 'a']--;
            }
        }

        return true;
    }
};