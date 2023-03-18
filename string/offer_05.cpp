#include <iostream>
#include <string>
using namespace std;

class Solution {
  public:
    string replaceSpace(string s) {

        // 得到替换空格之后应该的总长度
        int oldSize = s.size();
        int newSize = s.size();
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                newSize += 2;
            }
        }
        // 重新申请空间
        s.resize(newSize);
        // 双指针，一个指向新数组的末尾，一个指向旧数组的末尾
        int i = oldSize - 1;
        int j = newSize - 1;
        for (; i >= 0; i--) {
            if (s[i] == ' ') {
                s[j] = '0';
                s[j - 1] = '2';
                s[j - 2] = '%';
                j -= 3;
            } else {
                s[j] = s[i];
                j -= 1;
            }
        }
        return s;
    }
};