//
// Created by 86188 on 2023/7/21.
//
#include "../include/user.h"

using namespace std;

class Solution {
public:
    int movingCount(int m, int n, int k) {
        vector<vector<bool>> visited(m, vector<bool>(n, false)); // 初始化 visited 矩阵为 false
        dfs(m, n, k, 0, 0, visited);
        return res;
    }

    // 记录合法坐标数
    int res = 0;

    void dfs(int m, int n, int k, int i, int j, vector<vector<bool>> &visited) {
        if (i < 0 || j < 0 || i >= m || j >= n) {
            // 超出索引边界
            return;
        }

        if (i / 10 + i % 10 + j / 10 + j % 10 > k) {
            // 坐标和超出 k 的限制
            return;
        }

        if (visited[i][j]) {
            // 之前已经访问过当前坐标
            return;
        }

        // 走到一个合法坐标
        res++;
        visited[i][j] = true;

        // DFS 遍历上下左右
        dfs(m, n, k, i + 1, j, visited);
        dfs(m, n, k, i, j + 1, visited);
        dfs(m, n, k, i - 1, j, visited);
        dfs(m, n, k, i, j - 1, visited);
    }
};