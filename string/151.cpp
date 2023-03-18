#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
  public:
    string reverseWords(string s) {
        extractSpace(s);
        reverse(s);
        reverse_words(s);
        return s;
    }

    // 1 去除空格 使用快慢指针
    void extractSpace(string &s) {
        int left = 0;
        int right = 0;
        while (s[right] == ' ') {
            right++;
        }
        for (; right < s.size(); right++) {

            // 删除中间的空格
            if (s[right] == ' ' && s[right + 1] != ' ' &&
                right < s.size() - 1) {
                cout << "s[right]" << s[right] << endl;
                s[left] = s[right];
                left++;
            } else if (s[right] != ' ') {
                cout << "s[right]" << s[right] << endl;
                s[left] = s[right];
                left++;
            }
        }
        cout << "left =" << left << endl;
        cout << "right =" << right << endl;

        s = string(s.begin(), s.begin() + left);
        cout << s << endl;
    }

    // 翻转 整体字符串
    void reverse(string &s) {
        for (int i = 0, j = s.size() - 1; i < s.size() / 2; i++, j--) {
            swap(s[i], s[j]);
        }
    }

    // 翻转 单个单词
    void reverse_words(string &s) {
        int left = 0;
        int right = 0;

        while (right < s.size()) {
            while (s[right] != ' ' && right < s.size()) {
                right++;
            }
            right = right - 1;
            int tmp = right;
            for (; left <= (right + left) / 2; left++, right--) {
                swap(s[left], s[right]);
            }
            left = tmp + 2;
            right = tmp + 2;
        }
    }
};

int main(int argc, char const *argv[]) {
    string s1 = "   the   sky is blue   ";
    cout << s1 << endl;
    Solution s;
    // s.extractSpace(s1);
    // cout << s1 << "**" << endl;
    // s.reverse(s1);
    // cout << s1 << "**" << endl;
    // s.reverse_words(s1);
    // cout << s1 << "**" << endl;
    s1 = s.reverseWords(s1);
    cout << s1 << "**" << endl;
    return 0;
}
