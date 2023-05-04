/*
 * @lc app=leetcode.cn id=37 lang=cpp
 *
 * [37] 解数独
 */

// @lc code=start

#include <vector>
#include <algorithm>
#include <iostream>

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

    bool backtracking(int boardSize, vector<vector<char>> &board) {
        for (int i = 0; i < boardSize; i++) {
            for (int j = 0; j < boardSize; j++) {
                if (board[i][j] == '.') {
                    for (char k = '1'; k <= '9'; k++) {
                        if (isValue(i, j, k, board)) {
                            board[i][j] = k;
                            if (backtracking(boardSize, board)) {
                                return true;
                            }
                            board[i][j] = '.';
                        }
                    }
                    return false;  // 9个数都试完了，都不行，那么就返回false
                }

            }
        }
        return true;
    }

public:


    void solveSudoku(vector<vector<char>> &board) {
        backtracking(9, board);
    }
};
// @lc code=end


int main() {
    char *a[9][9] = {"5", "3", ".", ".", "7", ".", ".", ".", ".",
                     "6", ".", ".", "1", "9", "5", ".", ".", ".",
                     ".", "9", "8", ".", ".", ".", ".", "6", ".",
                     "8", ".", ".", ".", "6", ".", ".", ".", "3", "4", ".", ".", "8",
                     ".", "3", ".", ".", "1", "7", ".", ".", ".", "2", ".", ".", ".", "6", ".", "6", ".", ".", ".", ".",
                     "2", "8", ".", ".", ".", ".", "4", "1", "9", ".", ".", "5", ".", ".", ".", ".", "8", ".", ".", "7",
                     "9"};
    cout << a[1][1] << endl;
    vector<vector<char>> v;
    for (int i = 0; i < 9; i++) {
        vector<char> v1;
        for (int j = 0; j < 9; j++) {
            v1.push_back(*a[i][j]);
        }
        v.push_back(v1);
    }
    Solution s;
    s.solveSudoku(v);
    return 0;

}