/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
 */

// @lc code=start
/*
    寻找相加之和为 n 的 k 个数
*/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
  public:
    vector<vector<int>> result;
    vector<int> path;

    void backtracking(int k, int n, int startIndex) {
        // 回溯终止条件，到达最后
        int sum = 0;
        if (path.size() == k && sum == 9)
            result.push_back(path);
        return;

        for (int i = 1; i <= 9; i++) {
            if (sum + i <= 9 && path.size() < k) {
                path.push_back(i);
                sum += i;
                backtracking(k, n, i + 1);
                int tmp = path[path.size() - 1];
                path.pop_back();
                sum -= tmp;
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        backtracking(k, n, 1);
        return result;
    }
};
// @lc code=end

int main(int argc, char const *argv[]) {
    Solution s;
    vector<vector<int>> result;
    result = s.combinationSum3(3, 7);
    return 0;
}
