//
// Created by 86188 on 2023/4/21.
//

#include <iostream>
#include <vector>
#include <string>

namespace test01 {
    void showVector(const std::vector<int> &v) {
        for (auto i: v) {
            std::cout << i << ",";
        }
        std::cout << std::endl;
    }

    /*
     * 输入 固定数目 的数组
     * 输入示例: 3 2 6 7 3 7
     * 1. cin
     * 2. 遇到空格和回车会停止
     */
    void cinTest() {
        std::vector<int> v(5);
        for (int i = 0; i < v.size(); i++) {
            std::cin >> v[i];
        }

//        for (auto i: v) {
//            std::cout << i << ",";
//        }
//        std::cout << std::endl;
    }


    /*
     * 输入字符串
     * 输入示例：
     * asdasdfasdf
     * 1. getline()
     * 2. 遇到回车停止
     */
    void getStringTest() {
        std::string s;
        getline(std::cin, s);
        std::cout << s << std::endl;
    }


    /*
     * 1. getchar() 获取单个字符
     * 2. 用来吃回车
     */
    void getCharTest() {   //该函数会从缓存区中读出一个字符，经常被用于判断是否换行
        char ch;
        ch = getchar();
        // 输出读入的字符
        std::cout << ch << std::endl;
    }
}


#include <iostream>
#include <vector>
#include <string>

namespace test02 {
    /*
    * 输入不固定数目的数组
    * 输入示例： 1 2 3 4 8
    */
    std::vector<int> cinVector() {
        std::vector<int> nums;
        int num;
        while (std::cin >> num) {
            nums.push_back(num);
            if (getchar() == '\n') {
                break;
            }
        }
        test01::showVector(nums);
    }


    /*
     * 常规模式：输入二维数组的行数和列数，再输入数组
     * 输入示例：
     *     2 2
     *     1 2 4 5
     */
    std::vector<std::vector<int>> cinTwoDimVector() {
        // m 行 n 列的二维数组
        int m, n;
        std::cin >> m >> n;
        // 声明二维数组
        std::vector<std::vector<int>> matrix(m, std::vector<int>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                std::cin >> matrix[i][j];
            }
        }

        // 遍历方式
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                std::cout << matrix[i][j] << " ";
            }
            std::cout << std::endl;
        }
        return matrix;
    }

    /* 常规模式：输入二维数组的行数和列数，再输入数组，每一行数据是逗号隔开的整数
     * 2 3
     * 1, 2, 3
     * 1, 2, 3
     */
    std::vector<std::vector<int>> cinStringTwoDimVector() {
        int m, n;
        std::cin >> m >> n;
        // 声明二维数字
        std::vector<std::vector<int>> matrix(m, std::vector<int>(n));

        // 读取字符串
        for (int i = 0; i < m; i++) {
            // 读入字符串
            std::string s;
            std::getline(std::cin, s);
            std::cout << s << std::endl;
            // 将读入的字符串按照逗号分隔为 vector<int>
            std::vector<int> vec;
            for (char j: s) {
                if (j != ',') {
                    int q = j - '0';
                    std::cout << "q" << q << ' ';
                    vec.push_back(q);
                }
            }
            matrix.push_back(vec);
        }

        // 遍历方式
        for (auto i: matrix) {
            for (auto j: i) {
                std::cout << j << " ";
            }
            std::cout << std::endl;
        }
        return matrix;
    }

}

namespace show {
    void showVector(const std::vector<int> &v) {
        for (auto i: v) {
            std::cout << i << ",";
        }
    }
}


#include <iostream>
#include <iomanip>

namespace test03 {
    /*
     * 保留小数点后 n 位 小数
     * 1. fixed和setprecision（n）结合可以实现保留小数点后几位，且会补 0
     * 2. 会进行四舍五入
     */
    void setPrecisionAfterPoint() {
        double s = 12.355;
        std::cout << std::fixed << std::setprecision(2);
        std::cout << s << std::endl;
    }

    /* 保留 n 位有效数字
     * 1. 使用 setprecision()
     * 2. 会采用科学计数法
     * 3. 会进行四舍五入
    */
    void setPrecision() {
        double s = 125.355;
        std::cout << std::setprecision(2);
        std::cout << s << std::endl;
    }
}

#include "algorithm"

int main() {
//    test01::cinTest();
//    test02::cinVector();
    test02::cinTwoDimVector();
//    test02::cinStringTwoDimVector();
    test03::setPrecision();
    return 0;
    std::vector<int> v = {1, 2, 3};

    std::sort(v.begin(), v.end());
}