/*
 * @lc app=leetcode.cn id=130 lang=cpp
 *
 * [130] 被围绕的区域
 */

// @lc code=start
#include <vector>

using namespace std;

/*
 * 任何边缘上的 O 或者与边缘上的 O 相连的 O 都不会变为 X
 *      1. 对边缘遍历：如果这个是 O 则对他进行 dfs 并对他相邻的 O 进行标记，
 *      2. 对所有未被标记的 O 转为 X
 */

class Solution {
private:
    vector<vector<bool>> visited;
    int sizeX;
    int sizeY;

    // 判断点是否在棋盘上
    bool validXY(int x, int y) {
        if (x >= 0 && x < sizeX && y >= 0 && y < sizeY) {
            return true;
        } else {
            return false;
        }
    }

    // 判断是否是边缘上的点
    bool isEdge(int x, int y) {
        if (x == 0 || y == 0 || x == sizeX - 1 || y == sizeY - 1) {
            return true;
        } else {
            return false;
        }
    }

    void dfs(vector<vector<char>> &board, int x, int y) {
        if (visited[x][y]) {
            return;
        }
        if (board[x][y] == 'O') {
            visited[x][y] = true;
            if (validXY(x + 1, y)) {
                dfs(board, x + 1, y);
            }
            if (validXY(x - 1, y)) {
                dfs(board, x - 1, y);
            }
            if (validXY(x, y + 1)) {
                dfs(board, x, y + 1);
            }
            if (validXY(x, y - 1)) {
                dfs(board, x, y - 1);
            }
        }
        return;
    }

public:
    void solve(vector<vector<char>> &board) {

        sizeX = board.size();
        sizeY = board[0].size();
        if (sizeX == 0 || sizeY == 0) {
            return;
        }
        visited.resize(sizeX, vector<bool>(sizeY, false));

        // 对棋盘边缘的每个点开始 DFS
        for (int startX = 0; startX < sizeX; startX++) {
            for (int startY = 0; startY < sizeY; startY++) {
                if (isEdge(startX, startY)) {
                    dfs(board, startX, startY);
                }
            }
        }

        // 对所有没有被 visited 的 'O' 设置未 true
        for (int i = 0; i < sizeX; i++) {
            for (int j = 0; j < sizeY; j++) {
                if (!visited[i][j] && (board[i][j] == 'O'))
                    board[i][j] = 'X';
            }
        }
        return;
    }
};
// @lc code=end
