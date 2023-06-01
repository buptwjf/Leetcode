/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */

// @lc code=start

/*
 * 最长递增子序列
 * 思路：采用 patience game 的方法
 * 1. 遍历整个数组，将每个元素放入一个牌堆中
 * 2. 后面的纸牌，只能放入比自己大的牌堆中，如果当前纸牌数字过大，那么需要新建一个堆
 * 3. 堆的数量就是最长递增子序列的长度
 */
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    int has_pos(int target, vector<int> top) {
        int pos = -1;
        int low = 0;
        int high = top.size();
        // 要找到比 target 大的最小的位置
        while (low < high) {
            int mid = (high + low) / 2;
            if (top[mid] >= target) { // 要去左边寻找
                pos = mid;
                high = mid;
            } else { // 中间的数小于等于 mid
                low = mid + 1;
            }
        }
        return pos;
    }

public:
    int lengthOfLIS(vector<int> &nums) {
        // 创建牌堆
        vector<int> top;
        for (auto &i: nums) {
            if (top.empty()) {
                top.push_back(i);
            } else {
                // 查找是否有合适的位置
                int pos = has_pos(i, top);
                if (pos == -1) { // 没有合适的位置
                    top.push_back(i);
                } else { // 有合适的位置
                    top[pos] = i;
                }
            }
        }
        return top.size();
    }
};
// @lc code=end

int main() {
    Solution s;
    vector<int> v = {10, 9, 2, 5, 3, 7, 101, 18};
    s.lengthOfLIS(v);
    return 0;
}
