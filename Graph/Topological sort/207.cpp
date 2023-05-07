/*
 * @lc app=leetcode.cn id=207 lang=cpp
 *
 * [207] 课程表
 */

#include <vector>

using namespace std;
/*
 * 判断图中有没有环：
 * 1.对图进行 dfs，开始遍历,当遍历他们的所有子邻居的过程中，如果还遇到他，那么就是有环
 * 2.每个节点设置三种状态
 */
// @lc code=start
class Solution {
private:
    vector<vector<int>> graph;
    vector<int> visited;
    bool result = true;

    void dfs(int i) {
        visited[i] = 1; // 这个节点在访问中
        for (auto v: graph[i]) {
            if (visited[v] == 0) {
                dfs(v);
                if (!result) {  // 如果发现已经遇到环了，则退出
                    return;
                }
            } else if (visited[v] == 1) {
                result = false;
                return;
            }
        }
        visited[i] = 2; // 遍历完所有邻居后，结束访问
    }

public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
        // 先将所有的课程信息存入图
        graph.resize(numCourses);
        visited.assign(numCourses, 0); // 初始化为都未访问的状态
        for (auto edge: prerequisites) {
            graph[edge[1]].push_back(edge[0]);
        }
        // 对所有节点进行 dfs
        for (int i = 0; i < numCourses; i++) {
            if (!visited[i]) {
                dfs(i);
            }
        }
        return result;
    }
};
// @lc code=end

int main() {
    Solution s;
    vector<vector<int>> p = {{1, 0}};
    s.canFinish(2, p);
    return 0;
}
