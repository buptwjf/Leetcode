#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
  public:
    int sum_n(int n) {
        int sum = 0;
        // 对 n 的每位数求平方和
        while (n) {
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        return sum;
    }
    bool isHappy(int n) {
        unordered_set<int> set;
        while (1) {
            int temp = sum_n(n); // 对 n 求平方和
            
            if (temp == 1) {
                return true;
            } else if (set.find(temp) != set.end()) {
                return false; // 如果有重复则不为欢乐数
            } else {
                set.insert(temp);    // 插入 hash 表
                n = sum_n(n);
            }
        }
    }
};

int main(int argc, char const *argv[]) {
    Solution s1;
    cout << s1.sum_n(123);
    return 0;
}
