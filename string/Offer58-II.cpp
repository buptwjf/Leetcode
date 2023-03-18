/*
    字符串的左旋转操作是把字符串前面的若干个字符转移到字符串的尾部。
    请定义一个函数实现字符串左旋转操作的功能。比如，输入字符串"abcdefg"和数字2，
    该函数将返回左旋转两位得到的结果"cdefgab"。
*/
#include <iostream>
#include <string>
using namespace std;
class Solution {
  public:
    string reverseLeftWords(string s, int n) {
        // 1. 先翻转前[0, n-1] bacdefg 
        reverse(s, 0, n-1);
        cout << s << endl;
        // 2. 再翻转后[n+1, s.size()-1] bagfedc
        reverse(s, n, s.size()-1);
        cout << s << endl;
        // 3. 再翻转整体 cdefgab
        reverse(s, 0, s.size()-1);
        cout << s << endl;
        return s;
    }

    // 翻转[start, end]
    void reverse(string &s, int start, int end) {
        for (int i = start, j = end; i <= (end  + start) / 2; i++, j--) {
            swap(s[i], s[j]);
        }
    }
};

int main(int argc, char const *argv[])
{
    string s1 = "abcdefg";
    Solution s;
    s1= s.reverseLeftWords(s1, 2);
    return 0;
}
