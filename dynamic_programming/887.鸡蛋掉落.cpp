/*
 * @lc app=leetcode.cn id=887 lang=cpp
 *
 * [887] 鸡蛋掉落
 */
/*
 * 使用动态规划
 * 定义：dp[i][j]表示当前状态有 K 个鸡蛋，对面有 N 个楼
 * */
// @lc code=start
#include <climits>
#include <string>
#include <vector>
using namespace std;

class Solution {
  private:
    vector<vector<int>> memo;

    int dp(int k, int n) { // k 个鸡蛋，面对 n 层
        // base case
        int res = INT32_MAX / 2;
        if (k == 1) {
            return n;
        }
        if (n == 0) {
            return 0;
        }
        if (memo[k][n] != -1) {
            return memo[k][n];
        }

        int lo = 1;
        int hi = n;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            int broken = dp(k - 1, mid - 1);
            int not_broken = dp(k, n - mid);
            // res = min(max(碎， 没碎)+1)        }
            if (broken > not_broken) {
                hi = mid - 1;
                res = min(res, broken + 1);
            } else {
                lo = mid + 1;
                res = min(res, not_broken + 1);
            }
        }
        memo[k][n] = res;
        return res;
    }

  public:
    int superEggDrop(int k, int n) {
        memo = vector<vector<int>>(k + 1, vector<int>(n + 1, -1));
        return dp(k, n);
    }
};
// @lc code=end