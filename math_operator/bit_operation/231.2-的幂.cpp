/*
 * @lc app=leetcode.cn id=231 lang=cpp
 *
 * [231] 2 的幂
 */

// @lc code=start

/*
    一个数如果是 2 的指数，那么它的二进制表示一定只含有一个 1：
*/
class Solution {
  public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) {
            return false;
        }
        return (n & (n - 1))==0; // 需要加括号 == 运算符优先级更高
    }
};
// @lc code=end
