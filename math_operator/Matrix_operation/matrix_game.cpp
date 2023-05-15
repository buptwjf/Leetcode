//
// Created by 86188 on 2023/5/12.
//


/*
 * 创建矩阵的二维数组
 */

#include <vector>

using namespace std;

class Game {
    int m, n;  // m*n 的棋盘
    vector<bool> board;

    // 将 二维数组的坐标 (x, y) 转为一维数组的索引
    int encode(int x, int y) {
        return x * n + y;
    }

    // 将一维数组中的索引转化为二维数组中的坐标 (x, y)
    vector<int> decode(int index) {
        int x = index / n;
        int y = index % n;
        return {x, y};
    }


};