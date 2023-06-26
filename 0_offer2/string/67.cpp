//
// Created by 86188 on 2023/6/23.
//
#include "../include/user.h"
#include <algorithm>

using namespace std;

class Solution {
public:
    int strToInt(string str) {
        // 首先去除前方空格
        int i = 0;
        int sign = 1;
        int result = 0;

        while (str[i] == ' ') {
            i++;
        }
        if (str[i] == '+' || str[i] == '-') {
            sign = str[i++] == '+' ? 1 : -1;
        }

        while (str[i] >= '0' && str[i] <= '9') {
        //  在每次迭代之前，我们检查当前的结果是否已经超过了 INT_MAX / 10。
        //  如果超过了，那么无论下一个数字是什么，乘以10后的结果都会溢出。
        //  如果当前的结果等于 INT_MAX / 10，我们还需要检查下一个数字字符是否大于 INT_MAX % 10。
        //  如果下一个数字大于 INT_MAX % 10，那么无论怎样，乘以10后的结果也会溢出。
            if (result > INT32_MAX / 10 || (result == INT_MAX / 10 && (str[i] - '0') > INT_MAX % 10)) {
                return sign == 1 ? INT32_MAX : INT32_MIN; // 2147483647
            }
            result = result * 10 + (str[i] - '0');
            i++;
        }
        return sign * result;
    }
};

int main(){
    Solution s;
    string str = "-91283472332";
    int a = s.strToInt(str);
    return 0;
}