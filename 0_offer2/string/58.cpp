//
// Created by 86188 on 2023/6/23.
//

#include "../include/user.h"
#include <algorithm>

using namespace std;

class Solution {
public:
    /*string reverseLeftWords(string s, int n) {
        string res = s.substr(n) + s.substr(0,n);
        return res;
    }*/
    string reverseLeftWords(string s, int n) {
        reverse(s.begin(), s.begin()+2);
        reverse(s.begin()+2, s.end());
        reverse(s.begin(), s.end());
        return s;
    }
};

int main() {
    string s = "cdabefg";
    Solution S;
    string res = S.reverseLeftWords(s, 2);
    cout << res << endl;
    return 0;
}