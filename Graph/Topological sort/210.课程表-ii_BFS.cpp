/*
 * @lc app=leetcode.cn id=210 lang=cpp
 *
 * [210] 课程表 II
 */

// @lc code=start

/*
 * BFS 判断有无环和拓扑排序
 * 1. 如果一个节点的入度为0，则这个节点可以作为首节点
 * 2. 如果这个图可以进行拓扑排序，去掉入度为 0 的点，下一个入度为 0的点就是下个起点
 */

#include <vector>

#include <stack>

using namespace std;

class Solution {
private:
    vector<vector<int>> graph;
    bool valid = true;
    vector<int> indegree;
    vector<int> order;
    vector<bool> used;


public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
        // 先将所有的课程信息存入图
        graph.resize(numCourses);
        used.assign(numCourses, false);
        indegree.assign(numCourses, 0); // 所有节点的入度都为 0
        for (auto edge: prerequisites) {
            graph[edge[1]].push_back(edge[0]);
            indegree[edge[0]]++; // 入度加 1
        }


        // 对所有节点进行 bfs
        int start = -1;
        while (order.size() != numCourses) {
            bool flag = false;
            // 找到入度为 0 的节点 start
            for (int i = 0; i < indegree.size(); i++) {
                if (indegree[i] == 0 && !used[i]) {
                    start = i;
                    flag = true;
                    used[i] = true;
                    break;
                }
            }

            if (flag) { // 有入度为 0 的结点
                // 将相邻节点的入度减一
                for (auto j: graph[start]) {
                    indegree[j]--;
                }
                // 将这个节点作为第一个
                order.push_back(start);
            } else { // 不存在入度为 0 的节点
                break;
            }
        }
        if (order.size() == numCourses) {
            return order;
        } else {
            return vector<int>{};
        }
    }


};
// @lc code=end

