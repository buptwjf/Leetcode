/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 */

// @lc code=start

#include <vector>
class Solution {
  public:
    vector<vector<int>> generateMatrix(int n) {

        // 初始化 二维矩阵
        vector<vector<int>> v(n, vector<int>(n, 0)); // n行n列的数组

        int i = 0; // 行
        int j = 0; // 列

        // 1. 定义 x 和 y 的起始位置
        int startx = 0;
        int starty = 0;

        // 2. 定义循环次数
        int loop = n / 2;

        // 3. 定义最中间的元素
        int mid = n / 2;

        int a = 1;

        // 定义循环的偏移量
        int offset = 1; // 需要定义循环长度，每次循环右边界

        while (loop--) {

            // 每次走完一轮就要调整初始的位置
            i = startx;
            j = starty;

            // 定义好四次循环 并设定好每次循环的初始，结束条件
            for (j = starty; j < (n - offset); j++) {
                v[i][j] = a++;
                cout << "v[" << i << "][" << j << "]" << v[i][j]
                     << "\t"; // i = 0;  j = 2
            }
            cout << endl;

            for (i = startx; i < (n - offset); i++) {
                v[i][j] = a++; // x = 2;  j = 2
                cout << "v[" << i << "][" << j << "]" << v[i][j] << "\t";
            }
            cout << endl;

            for (; j > starty; j--) { // x = 2;   j = 0;
                v[i][j] = a++;
                cout << "v[" << i << "][" << j << "]" << v[i][j] << "\t";
            }
            cout << endl;

            for (; i > startx; i--) {
                v[i][j] = a++;
                cout << "v[" << i << "][" << j << "]" << v[i][j] << "\t";
            }
            cout << endl;

            // 填充完一趟后，调整起始结束位置
            starty++;
            startx++;

            offset++;
        }

        // 如果 n 为奇数，则需要给矩阵最中间的位置赋值
        if (n % 2) {
            v[mid][mid] = a;
            cout << "v[" << mid << "][" << mid << "]=" << a << endl;
        }
        return v;
    }
};
// @lc code=end
