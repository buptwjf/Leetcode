/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start

/*
    n 为输入的 数的总数，k 为
    给定两个整数 n 和 k，返回范围 [1, n] 中所有可能的 k 个数的组合。

    回溯问题要注意剪枝：不要让树深入太深
    本题中有 n 个数，k 个组合
        当还需要的数为 k-path.size()，则从 n-(k-path.szie())+1 处开始都是合理的

*/

#include <iostream>
#include <vector>
using namespace std;
class Solution {
  private:
    vector<vector<int>> result; // 用来存放最终的结果
    vector<int> path;           // 用来存放符合条件的结果

  public:
    void backtracking(int n, int k, int startIndex) { // 回溯的函数左值一般是空
        if (path.size() == k) {                       // 终止条件
            result.push_back(path);
            return;
        }
        // for(int i = startIndex; i <= n; i++){
        for (int i = startIndex; i <= n - (k - path.size()) + 1; i++) {  // 回溯的剪枝操作

            path.push_back(i);         // 处理节点
            backtracking(n, k, i + 1); // 递归
            path.pop_back();           // 回溯，撤销处理的节点
        }
    }
    vector<vector<int>> combine(int n, int k) {
        result.clear();
        path.clear();
        backtracking(n, k, 1);
        return result;
    }
};
// @lc code=end
