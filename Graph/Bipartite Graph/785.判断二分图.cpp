/*
 * @lc app=leetcode.cn id=785 lang=cpp
 *
 * [785] 判断二分图
 */

/*
 * 思路，对图进行DFS
 *      1. 需要判断回路
 *      2. 每次遍历的时候对他需要进行染色
 *      3. 二分图必须是无向图
 */
#include <vector>

using namespace std;

// @lc code=start
class Solution {
private:
    bool valid;
    vector<bool> visited;
    vector<int> color;
public:
    void traversal_dfs(vector<vector<int>> &graph, int i) {
        if (!valid) {
            return;
        }

        visited[i] = true;

        for (auto j: graph[i]) {
            if (!visited[j]) {
                color[j] = color[i] == 1 ? 2 : 1;
                traversal_dfs(graph, j);
            } else {
                if (color[j] == color[i]) {
                    valid = false;
                    return;
                }
            }
        }
    }

    bool isBipartite(vector<vector<int>> &graph) {
        valid = true;
        visited = vector(graph.size(), false);
        color = vector(graph.size(), 1);  // 所有节点都涂色
        // count = 0;
        for (int v = 0; v < graph.size(); v++) {
            if (!visited[v]) {
                traversal_dfs(graph, v);
            }
        }
        return valid;
    }
};
// @lc code=end

