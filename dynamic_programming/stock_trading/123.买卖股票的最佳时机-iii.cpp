/*
 * @lc app=leetcode.cn id=123 lang=cpp
 *
 * [123] 买卖股票的最佳时机 III
 */
#include <vector>
using  namespace std;

/* 
    重新定义dp数组
    dp[i][k][0] 表示到第i天，最多还能有k次交易，这时候手里没有股票
    dp[i][k][1] 表示到第i天，最多还能有k次交易，这时候手里还有股票
    状态 k 的定义并不是「已进行的交易次数」，而是「最大交易次数的上限限制」
    每当买进一次股票后，可操作次数 -1（不应该在卖出的时候减 1）
    1. base case
    dp[0][...][0] = 0
    dp[0][0][1] = 不存在
    dp[0][k][1] = -prices[0] k!=0
    2. 状态转移方程
    dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1]+prices[i])  max(i-1天不持有 或 i-1天持有，第i天卖出)
    dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][0]-prices[i])  max(i-1天不持有 或 i-1天持有，第i天卖出)
    // 且要保证截至今天最大交易次数上限为 k，那么昨天的最大交易次数上限必须是 k - 1
    3. 最终结果为
    dp[i][k][0]
 */

// @lc code=start
#define MAX_TRANS 2
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int m = prices.size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(MAX_TRANS+1, vector<int>(2, 0)));
        //base case
        for(int i = 0; i <=MAX_TRANS; i++){
            dp[0][i][0] = 0;
            if(i==0){
                dp[0][i][1] = INT32_MIN;
            }else{
                dp[0][i][1] = -prices[0];
            }
        }

        for(int i = 1; i < m; i++){
            for(int j = 1; j <= MAX_TRANS ; j++){
                dp[i][j][0] = max(dp[i-1][j][0], dp[i-1][j][1]+prices[i]); // max(i-1天不持有 或 i-1天持有，第i天卖出)
                dp[i][j][1] = max(dp[i-1][j][1], dp[i-1][j-1][0]-prices[i]); // max(i-1天不持有 或 i-1天持有，第i天卖出)
            }
        }
        return dp[m-1][2][0];
    }
};
// @lc code=end

