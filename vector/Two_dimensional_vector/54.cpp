/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */

// @lc code=start

#include <vector>

using namespace std;

/*
 * 问题：按顺时针螺旋顺序打印 m × n 的矩阵
 * 思路：
 *      确定 up down left right 四个方向的位置，然后遍历数组
 * */
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int up = 0;
        int down = m - 1;
        int left = 0;
        int right = n - 1;
        vector<int> res;
        while (res.size() < m * n) {
            // 从左到右
            if(up <= down){ // 这个边界条件很重要，
                for (int i = left; i <= right; i++) {
                    res.push_back(matrix[up][i]);
                }
                up++;
                cout << "1" << endl;
            }
            // 从上到下
            if (left <= right) {
                for (int i = up; i <= down; i++) {
                    res.push_back(matrix[i][right]);
                }
            }
            right--;
            cout << "2" << endl;
            // 从右到左
            if (up <= down) {
                for (int i = right; i >= left; i--) {
                    res.push_back(matrix[down][i]);
                }
                down--;
                cout << "3" << endl;
            }
            // 从下到上
            if (left <= right) {
                for (int i = down; i >= up; i--) {
                    res.push_back(matrix[i][left]);
                }
                left++;
                cout << "4" << endl;
            }
        }
        return res;
    }
};
// @lc code=end

