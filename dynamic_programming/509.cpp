/*
 * @lc app=leetcode.cn id=509 lang=cpp
 *
 * [509] 斐波那契数
 */

// @lc code=start

/*
    1 1 2 3 5 8
*/
#include <vector>

using namespace std;

class Solution {
public:
    int fib(int n) {
        if (n < 0) {
            return -1;
        }
        vector<long long> dp(n + 1, 0);
        dp[0] = 0;
        if(n >= 1){
            dp[1] = 1;
        }

        for(int i =2; i<= n;i++){
            dp[i] = dp[i-1] + dp[i-2];
        }

        return dp[n];
    }
};
// @lc code=end

int main() {
    Solution s;
    s.fib(0);
    return 0;
}
