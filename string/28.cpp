#include <iostream>
#include <string>

using namespace std;
/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 找出字符串中第一个匹配项的下标
 */

// @lc code=start
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) {
            return 0;
        }
        // 前缀表减一作为 next数组
        cout << needle.size() << endl;
        int next[needle.size()];
        getNext(needle, next);
        int k = 0;
        while (next[k]) {
            cout << "next[" << k << "]=" << next[k] << endl;
            k++;
        }

        int j = -1; // 因为 next 数组里记录的起始位置为 -1
        // 从 0 开始遍历文本串
        for (int i = 0; i < haystack.size(); i++) {
            // 如果不相同
            while (j >= 0 && haystack[i] != needle[j + 1]) {
                j = next[j]; // j寻找之前匹配的位置
            }
            // 如果相同 j 向后移动
            if (haystack[i] == needle[j + 1]) {
                cout << "i=" << i << endl;
                j++; //
                cout << "j=" << j << endl;
            }
            // 当 j = 到末尾时，结束
            if (j == (needle.size() - 1)) {
                cout << i - needle.size() + 1;
                return (i - needle.size() + 1);
            }
        }
        return -1;
    }

    void getNext(string needle, int *next) {
        // 定义两个指针 i，j;  j 指向前缀末尾位置，i指向后缀末尾位置
        int j = -1;
        next[0] = j;
        for (int i = 1; i < needle.size(); i++) { // 不同长度 i 寻找前后缀
            while (j >= 0 && needle[i] != needle[j + 1]) {
                j = next[j];
            }
            if (needle[i] == needle[j + 1]) { // 找到相同的前后缀
                j++;
                // 同时向后移动i 和 j
                // 说明找到了相同的前后缀，同时还要将j（前缀的长度）赋给next[i],
                // 因为next[i]要记录相同前后缀的长度。
            }
            next[i] = j; // 将 j (前缀的长度)赋给 next[i]
        }
        /*
            初始化时：                                      next[0]=-1
            当 i = 1 时， needle[1] = needle[0]  j = 0      next[1]=0
            当 i = 2 时,  needle[2]!= needle[1]  j = -1     next[2]=-1
            当 i = 3 时,  needle[3] = needle[0]  j = 0      next[3]=0
            当 i = 4 时， needle[4] = needle[1]  j = 1      next[4]=1
            当 i = 5 时， needle[5]!= needle[2]  j = -1     next[5]=-1
        */
    }
};

// @lc code=end

int main(int argc, char const *argv[]) {
    cout << "中国 " << endl;
    Solution s;
    s.strStr("hello", "ll");
    return 0;
}
