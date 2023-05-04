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
    int sum = 0;

    void backtracking(int k, int n, int startIndex) {
        // 回溯终止条件，到达最后
        if (path.size() == k && sum == n) {
            result.push_back(path);
            return;
        }

        // 在宽度方向上循环
        for (int i = startIndex; i <= 9; i++) {
            if (sum + i <= n && path.size() < k) {  // 如果还能再往更深处探索，则入栈
                //  对当前节点进行处理
                path.push_back(i);
                sum += i;

                // 开始递归
                backtracking(k, n, i + 1);

                // 回溯操作
                int tmp = path[path.size() - 1];
                path.pop_back();
                sum -= tmp;

            }else{ // 剪枝算法
                break;
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
