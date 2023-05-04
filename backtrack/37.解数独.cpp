/*
 * @lc app=leetcode.cn id=37 lang=cpp
 *
 * [37] 解数独
 */

// @lc code=start

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    bool isValue(int row, int col, char num, const vector<vector<char>> &board) {
        if (find(board[row].begin(), board[row].end(), num) != board[row].end()) {
            return false; // 同行
        }

        for (auto i: board) {
            if (i[col] == num) {
                return false;  // 同列
            }
        }

        int startRow = row / 3;
        int startCol = col / 3;

        for (int i = startRow * 3; i < startRow * 3 + 3; i++) {
            for (int j = startCol * 3; j < startCol * 3 + 3; j++)
                if (board[i][j] == num) {
                    return false;  // 同九宫格
                }
        }
        return true;
    }

    void backtracking(int startIndex, int deepIndex, int boardSize, vector<vector<char>> &board) {
        for (int i = deepIndex; i < boardSize; i++) {
            for (int j = startIndex; j < boardSize; j++) {
                if (board[i][j] == '.') {
                    for (int k = 1; k <= boardSize; k++) {
                        if (isValue(i, j, k + '0', board)) {
                            board[i][j] = k + '0';
                            if (startIndex == boardSize - 1) {
                                backtracking(0, deepIndex + 1, boardSize, board);
                            } else {
                                backtracking(startIndex + 1, deepIndex, boardSize, board);
                            }
                            board[i][j] = '.';
                        }

                    }
                }
            }
        }
    }

public:


    void solveSudoku(vector<vector<char>> &board) {
        backtracking(0, 0, 9, board);
    }
};
// @lc code=end

