/*
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] 旋转图像
 */

// @lc code=start

#include "vector"

using namespace std;

/*
 * 将 n×n 图像顺时针旋转 90°，必须原地旋转
 * 思路：先对矩阵进行转置，然后再对矩阵的每一行进行反转
 * */
class Solution {
public:
    void rotate(vector<vector<int>> &matrix) {
        int n = matrix.size();
        // 进行转置操作
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        // 对每一行进行 reverse
        for(int i = 0; i< n;i++){
            for(int j = 0; j < n/2; j++){
                swap(matrix[i][j], matrix[i][n-1-j]);
            }
        }
    }
};
// @lc code=end

