#include <algorithm>
#include <iostream>
#include <string.h>
using namespace std;

/*
    方法 1
    1. 组成 s+s
    2. 去除收末尾的元素
    3. 同时还能找到一个 s
*/
class Solution {
  public:
    bool repeatedSubstringPattern(string s) {
        string s2 = s + s;
        s2.erase(s2.begin());
        s2.erase(s2.end() - 1);
        if (s2.find(s) != std::string::npos) {
            return true;
        } else {
            return false;
        }
    }
};

/*
    方法 2
    1. 寻找该字符的 next数组
    2. 寻找这个字符串的最长相等前后缀
    3.
   数组长度减去最长相同前后缀的长度相当于是第一个周期的长度，也就是一个周期的长度，
        如果这个周期可以被整除，就说明整个数组就是这个周期的循环。
    4. 如果这个数组是可重复的，那么他的 next 数组为
        a    b   s   f   a    b   s   f   a   b    s   f
        -1  -1  -1  -1   0    1   2   3   4   5    6   7

*/
class Solution1 {
  public:
    bool repeatedSubstringPattern(string s) {
        if (s.size() == 1) {
            return false;
        }

        int next[s.size()];

        getNext(next, s);
        for (int k = 0; k < s.size(); k++) {
            cout << "next[" << k << "]=" << next[k] << endl;
        }

        int len = s.size();
        cout << "len = " << len << endl;
        cout << "next[len-1] = " << next[len - 1] << endl;
        cout << "len % (len - next[len - 1] - 1) = "
             << len % (len - next[len - 1] - 1) << endl;

        if (next[len - 1] != -1 && len % (len - next[len - 1] - 1) == 0) {
            return true;
        } else {
            return false;
        }
    }

    void getNext(int *next, string model) {
        int j = -1;
        next[0] = j;

        // i 为子串的后缀，j 为子串的前缀
        for (int i = 1; i < model.size(); i++) {
            while (j >= 0 && model[i] != model[j + 1]) {
                j = next[j];
            }
            if (model[i] == model[j + 1]) {
                j++;
            }
            next[i] = j;
        }
    }
};

int main(int argc, char const *argv[]) {
    Solution1 s;
    string s1 = "abababaaba";
    cout << s.repeatedSubstringPattern(s1);
    return 0;
}
