//
// Created by 86188 on 2023/7/21.
//

#include "../include/user.h"

using namespace std;

/*
 * 问题：统计 x + y  < k 的所有格子
 * 思路：使用 dfs
 * */
class Solution {
public:
    // 根据一个数，返回他各个位数的和
    int getSum(int x) {
        int sum = 0;
        while (x > 0) {
            sum += x % 10;
            x /= 10;
        }
        return sum;
    }

    int movingCount(int m, int n, int k) {
        vector<vector<bool>> visited = vector(m, vector<bool>(n, false));   // 使用visited 数组进行统计
        int count = 0;
        dfs(0, 0, visited, m, n, k, count);
        return count;
    }

    void dfs(int i, int j, vector<vector<bool>> &visited, int m, int n, int k, int &count) {
        // 当超出范围
        if (i < 0 || i >= m || j < 0 || j >= n) {
            return;
        }
        if (getSum(i) + getSum(j) > k) {
            return;
        }
        if (visited[i][j]) {
            return;
        } else {
            visited[i][j] = true;
            count++;
            dfs(i + 1, j, visited, m, n, k, count);
            dfs(i - 1, j, visited, m, n, k, count);
            dfs(i, j + 1, visited, m, n, k, count);
            dfs(i, j - 1, visited, m, n, k, count);
            return;
        }
    }
};

int main() {
    Solution s;
//    cout << s.getSum(22);
    cout << s.movingCount(2,3,1);
    return 0;
}