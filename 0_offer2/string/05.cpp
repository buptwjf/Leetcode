//
// Created by 86188 on 2023/6/23.
//

#include "../include/user.h"

using namespace std;

/*
 * 这个题给的是string，如果是字符串数组的话，并且需要不能使用额外空间的话，为了防止对字符的移动
 * 太多，可以使用双指针法从后往前进行判断
 * */
class Solution {
public:
    string replaceSpace(string s) {
        string res;
        for (auto i: s) {
            if (i == ' ') {
                res += "%20";
            } else {
                res += i;
            }
        }

        return res;
    }
};



int main(){
    string str = "asasd asdasd ";
    Solution s;
    cout << s.replaceSpace(str) << endl;
}