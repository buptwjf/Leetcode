//
// Created by 86188 on 2023/7/13.
//
#include "../include/user.h"

using namespace std;

/*
 * 问题：在一个 n * m 的二维数组中，每一行都按照从左到右 非递减 的顺序排序，每一列都按照从上到下 非递减 的顺序排序。
 * 思路：不能使用二分法，从右上角开始出发，当前数比 target 小的话往左走，大的话往右走
 * */
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>> &matrix, int target) {
        if (matrix.empty()) {
            return false;
        }
        int m = matrix.size();
        int n = matrix[0].size();

        // 从右上角出发
        int i = 0;
        int j = n - 1;
        while (i < m && j >= 0) {
            if (matrix[i][j] == target) {
                return true;
            } else if (matrix[i][j] < target) {
                i++;
            } else if (matrix[i][j] > target) {
                j--;
            }
        }
        return false;
    }
};