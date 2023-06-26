//
// Created by 86188 on 2023/6/23.
//
#include "../include/user.h"

using namespace std;

class Solution {
public:
    bool isNumber(string s) {
        // 首先去掉前后的空格
        int i = 0;
        while (i < s.size() && s[i] == ' ') {
            i++;
        }
        s = s.substr(i);
        while (s.back() == ' ') {
            s.pop_back();
        }

        bool numFlag = false;
        bool dotFlag = false;
        bool eFlag = false;
        for (int i = 0; i < s.size(); i++) {
            if (isdigit(s[i])) {
                numFlag = true;
            } else if (s[i] == '.' && !dotFlag && !eFlag) { // 只能出现一个 . 并且 e 不能出现
                dotFlag = true;
            } else if ((s[i] == 'E' || s[i] == 'e') && !eFlag && numFlag) { // e 只能出现一次，且出现之前必须有数字
                eFlag = true;
                numFlag = false;  // 出现 E 后面必须跟着一个整数
            } else if ((s[i] == '+' || s[i] == '-') && (i == 0 || s[i - 1] == 'e' || s[i - 1] == 'E')) {
                // 如果有 + -，必须为第一位，并且前一位为 E
            } else {
                return false;
            }
        }
        return numFlag;
    }
};

int main() {
    string str = "  12  ";
    Solution s;
    s.isNumber(str);
    return 0;
}