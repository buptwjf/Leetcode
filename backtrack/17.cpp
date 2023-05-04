/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start

/*
 * 采用回溯策略，避免多个 for 循环嵌套
 * 1. 可以写一个映射表，简化工作
 * 2. 一共深度有 digits.size() 层
 *
 *
 */
#include "string"
#include <vector>

using namespace std;

class Solution {
  private:
    vector<string> result;
    vector<char> path;
    vector<string> letterMap = {"_",   "!@#", "abc",  "def", "ghi",
                                "jkl", "mno", "pqrs", "tuv", "wxyz"};

    void backtracking(string digits,
                      int deepIndex) { // 这里 deepIndex 代表树的层数
        // 当探测超过树的深度时候时，返回
        if (deepIndex >= digits.size()) {
            string tmp;
            for (auto i : path) {
                tmp += i;
            }
            result.push_back(tmp);
            return;
        }

        // 不同深度的节点宽度不同
        int n = letterMap[(digits[deepIndex]) - '0'].size();
        for (int i = 0; i < n; i++) {
            string tmp =
                letterMap[(digits[deepIndex]) - '0']; // 选出数字对应的字母
            path.push_back(tmp[i]);                   // 选出多个字母
            backtracking(digits, deepIndex + 1);
            path.pop_back();
        }
    }

  public:
    vector<string> letterCombinations(string digits) {

        result.clear();
        path.clear();
        if (digits.empty()) {
            return result;
        }
        backtracking(digits, 0);
        return result;
    }
};

// @lc code=end
int main(int argc, char const *argv[]) {
    Solution s;
    s.letterCombinations("23");
    return 0;
}
