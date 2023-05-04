/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原 IP 地址
 */

// @lc code=start

/*
 * 1. 采用回溯的思路进行暴力遍历
 *      1.1 每层应该
 *
 */
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
private:
    vector<string> result;
    string path;

    bool isEffectiveIP(string str) {
        if (stoi(str) > 255) {
            return false;
        }
        if (str[0] == '0' && str.size() > 1) {
            return false;
        }
        std::cout << fixed() << setprecision(2);
        return true;
    }

    void traversal(string s, int startIndex, int& count){
        if(count == 4){
            if(startIndex == s.size()) {
                path.erase(path.size() - 1, 1); // 删除最后一个 .
                result.push_back(path);
                path += '.';
                return;
            }else{
                return;
            }
        }

        for(int i = startIndex+1; i <= s.size(); i++){  // [ startIndex->x 的前闭后开区间)
            string str = s.substr(startIndex, i-startIndex);
            int strSize = str.size();
            if(isEffectiveIP((str))){
                path += str;
                path += '.';
                count++;
            }else{
                break;
            }
            traversal(s, i, count);
            path.erase(path.size()-strSize-1, strSize+1);
            count--;
        }


    }

public:
    vector<string> restoreIpAddresses(string s) {
        result.clear();
        path.clear();
        int count = 0;
        traversal(s, 0, count);
        return result;
    }
};
// @lc code=end

int main(){
    Solution s;
    s.restoreIpAddresses("25525511135");
    return 0;
}
