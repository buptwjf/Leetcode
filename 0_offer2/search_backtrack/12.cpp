//
// Created by 86188 on 2023/7/20.
//
#include "../include/user.h"

using namespace std;

/*
 * 问题从一个矩阵中找到是否存在一个word，每个字母只能用一次
 * 思路：
 * 1. 先找到首字母所在的格子，然后从那个位置开始遍历
 * 2. 遍历按 上、下、左、右的顺序
 * 3. 每找到符合的字母。就压入栈中
 * 4. 每当找不到时，就进行回溯
 * 5. 用一个大小相等的 board 进行记录该字母是否被使用过
 * */
class Solution {
private:
    vector<vector<char>> board;
    string word;
    vector<vector<bool>> used;
    int m;
    int n;

    bool backtrack(int i, int j, int k) {
        if (board[i][j] != word[k]) {
            return false;
        }
        if (k == word.size() - 1) {
            return true;
        }
        used[i][j] = true;
        vector<pair<int, int>> directions{{0,  1},
                                          {0,  -1},
                                          {1,  0},
                                          {-1, 0}};
        bool result = false;
        // 在上下左右进行查找
        for (auto dir: directions) {
            int newX = i + dir.first;
            int newY = j + dir.second;
            if (newX >= 0 && newX < m && newY >= 0 && newY < n && !used[newX][newY]) {
                int flag = backtrack(newX, newY, k + 1);
                if (flag) {
                    result = true;
                    break;
                }
            }
        }
        used[i][j] = false;
        return result;
    }

public:

    bool exist(vector<vector<char>> &board, string word) {
        if (word.empty()) {
            return true;
        }
        // 初始化 used 数组

        this->m = board.size();
        this->n = board[0].size();
        vector<pair<int, int>> visited;
        this->board = board;
        this->word = word;
        this->used = vector(m, vector(n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                bool flag = backtrack(i, j, 0);
                if (flag) {
                    return true;
                }
            }
        }
        return false;
    }

};

int main() {
    vector<vector<char>> v = {{'A', 'B', 'C', 'E'},
                              {'S', 'F', 'C', 'S'},
                              {'A', 'D', 'E', 'E'}};
    string word = "ABCCED";
    Solution s;
    cout << s.exist(v, word);
    return 0;
}