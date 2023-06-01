/*
 * @lc app=leetcode.cn id=514 lang=cpp
 *
 * [514] 自由之路
 */

// @lc code=start
#include <vector>
#include <string>
#include <math.h>
#include <unordered_map>

using namespace std;

class Solution {
private:
    // 字符 -> 索引列表
    unordered_map<char, vector<int>> charToIndex;
    // 备忘录
    vector<vector<int>> memo;

    // 计算圆盘在 ring[i]，输入 key[j...] 的最小操作数
    int dp(string ring, int i, string key, int j) {
        // base case
        if (j == key.size()) {
            return 0;
        }
        // 查找备忘录，避免重叠子
        if (memo[i][j] != 0) {
            return memo[i][j];
        }

        int n = ring.size();
        // 做选择
        int res = INT32_MAX;
        // ring 上可能有多个字符 key[j]
        for (int k: charToIndex[key[j]]) {
            int delta = abs(k - i);
            delta = min(delta, n - delta);
            int subProblem = dp(ring, k, key, j + 1);
            res = min(res, 1 + delta + subProblem);
        }
        memo[i][j] = res;
        return res;
    }

public:
    // 主函数
    int findRotateSteps(string ring, string key) {
        int m = ring.size();
        int n = key.size();
        memo = vector<vector<int>>(m, vector<int>(n, 0));
        for (int i = 0; i < ring.size(); i++) {
            char c = ring[i];
            charToIndex[c].push_back(i);
        }
        return dp(ring, 0, key, 0);
    }
};
// @lc code=end

