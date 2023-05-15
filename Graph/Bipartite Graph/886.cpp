/*
 * @lc app=leetcode.cn id=886 lang=cpp
 *
 * [886] 可能的二分法
 */

// @lc code=start

/*
 * 思路类似于 二分法 但是需要自己建图
 * 1. 将每个人认为是一个顶点，厌恶关系认为是顶点的边
 * 2. 判断能不能对这个图进行二分
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
  private:
    vector<bool> visited;
    vector<vector<int>> graph;
    vector<bool> color;
    bool valid;

    void init(int n, vector<vector<int>> &dislikes) { // 构造邻接链表图
        cout << 1 << endl;
        graph.resize(n+1, {});
        cout << 1 << endl;

        visited.resize(n+1, false);
                cout << 1 << endl;

        color.resize(n+1, false);
                cout << 1 << endl;

        valid = true;
        for (auto i : dislikes) {
            graph[i[0]].push_back(i[1]);
            graph[i[1]].push_back(i[0]);
        }
        cout << 2 << endl;
    }

    void traversal_dfs(int i) {
        if (!valid) {
            return;
        }
        visited[i] = true;
        cout << 2 << endl;

        for (auto j : graph[i]) {
            if (!visited[j]) {
                color[j] = !color[i];
                traversal_dfs(j);
            } else {
                if (color[j] == color[i]) {
                    valid = false;
                    return;
                }
            }
        }
    }

  public:
    bool possibleBipartition(int n, vector<vector<int>> &dislikes) {
        init(n, dislikes);
        for (int v = 0; v < n; v++) {
            if (!visited[v]) {
                traversal_dfs(v);
            }
        }
        return valid;
    }
};
// @lc code=end


