/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */

// @lc code=start


/*
 * N 皇后
 *
 * */
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {

private:
    vector<vector<string>> result;
    vector<string> path;

    bool isValue(int x, int y, int n) {
        for (int i = 0; i < path.size(); i++) {
            int pos = path[i].find('Q');

            if (pos == x) {
                return false;
            }
            if (pos + (n - i - 1) == x + (n - y - 1)) { // 成 45°
                return false;
            }
            if (pos - (n - i - 1) == x - (n - y - 1)) { // 成 135°
                return false;
            }
        }
        return true;
    }


    void backtracking(int startIndex, int deepIndex, int n) {
        if (path.size() == n) {
            result.push_back(path);
            return;
        }

        for (int i = startIndex; i < n; i++) {
            if (isValue(i, deepIndex, n)) {
                string cur = string(n, '.');
                cur[i] = 'Q';
                path.push_back(cur);
                backtracking(0, deepIndex + 1, n);
                path.pop_back();
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        result.clear();
        path.clear();
        backtracking(0, 0, n);
        return result;

    }
};
// @lc code=end

int main() {
    Solution s;
    s.solveNQueens(4);
    return 0;
}

