/*
 * @lc app=leetcode.cn id=210 lang=cpp
 *
 * [210] 课程表 II
 */

// @lc code=start

/*
 * 首先验证图有没有有环
 * 通过栈来输出图的拓扑排序
 */

#include <vector>

#include <stack>

using namespace std;

class Solution {
private:
    vector<vector<int>> graph;
    vector<int> visited;
    bool valid = true;
    stack<int> st;
    vector<int> order;


    void dfs(int i) {
        visited[i] = 1; // 这个节点在访问中
        for (auto v: graph[i]) {
            if (visited[v] == 0) {
                dfs(v);
                if (!valid) {  // 如果发现已经遇到环了，则退出
                    return;
                }
            } else if (visited[v] == 1) {
                valid = false;
                return;
            }
        }
        visited[i] = 2; // 遍历完所有邻居后，结束访问
        st.push(i);
    }

public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
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

        if (valid) {
            while (!st.empty()) {
                int cur = st.top();
                order.push_back(cur);
                st.pop();
            }
        }
        return order;
    }

};
// @lc code=end

