/*
 * @lc app=leetcode.cn id=797 lang=cpp
 *
 * [797] 所有可能的路径
 */

/*
 * 输入：graph = [[1,2],[3],[3],[]]
    输出：[[0,1,3],[0,2,3]]
    解释：有两条路径 0 -> 1 -> 3 和 0 -> 2 -> 3
 * */
#include <vector>

using namespace std;
/*
 * 采用 DFS 算法遍历 有向无环图 DAG
 * 题目相当于给你提供了一个 邻接链表
 */
// @lc code=start

/*
    此题事无环图，因此不需要判定是否有回路
*/
class Solution {
    vector<vector<int>> results;
    vector<int> path;
public:
    void dfs(vector<vector<int>> &graph, int x, int n) {
        if (x == n) { // 当遍历到 节点 n-1 时
            results.push_back(path);
        }
        for (auto i: graph[x]) {
            path.push_back(i);
            dfs(graph, i, n);
            path.pop_back();
        }

    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph) {
        results.clear();
        
        path.clear();
        path.push_back(0);
        dfs(graph, 0, graph.size()-1);
        return results;
    }
};
// @lc code=end

