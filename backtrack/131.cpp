/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */

// @lc code=start

/*
 * 分隔回文子串
 * 1. 怎么分隔 ? 这是难点
 *      1.1 每层怎么切割
 *      1.2 切割完到下层应该怎么办
 * 2. 分隔之后判断是不是回文字串
 * 3. 判断回文串有没有什么更简单的办法
 *      3.1 动态规划
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Solution {
private:
    vector<vector<string>> result;
    vector<string> path;

    bool isPalindrome(string s, int start, int end) {
        while (end >= start) {
            if (s[start] == s[end - 1]) {
                start++;
                end--;
            } else {
                return false;
            }
        }
        return true;
    }

    void traversal(string s, int startIndex) {
        if (startIndex == s.size()) {
            result.push_back(path);
            return;
        }

        for (int i = startIndex + 1; i <= s.size(); i++) {
            if (isPalindrome(s, startIndex, i)) { // [ ) 区间内是否是回文串
                string str = s.substr(startIndex, i - startIndex);
                path.push_back(str);
            } else {
                continue;
            }
            traversal(s, i);
            path.pop_back();
        }


    }

public:
    vector<vector<string>> partition(string s) {
        result.clear();
        path.clear();
        traversal(s, 0);
        return result;
    }
};
// @lc code=end

int main(){
    Solution s;
    s.partition("aab");
    return 0;
}