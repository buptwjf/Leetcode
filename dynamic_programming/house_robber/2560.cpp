/*
 * @lc app=leetcode.cn id=2560 lang=cpp
 *
 * [2560] 打家劫舍 IV
 */

// @lc code=start
#include <vector>
/*
    0 1 3 3 2 1 1 0.5  k = 2
    1 3  3
    3 2  2
    1 1  1
    2 1  2
    0 0.5 0.5
    有 k
*/
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

/*
 * 这个题不能用动态规划
 * 要得到最小能力 min_cab，从左往右遍历房屋，如果小于min_cab则打劫，并跳过下一间房屋。
 * 如果可以打劫到k个房屋则成功则 nums 中有 >=k 个数小于 min_cab
 * 而且 min_cab 可能有多个，需要找出最小的一个(用二分法)
 * */
class Solution {
private:
    int min_cap = INT32_MAX;

    bool isValid(vector<int> &nums, int k, int min_cab) {
        int count = 0;
        for (int j = 0; j < nums.size(); j++) {
            if (nums[j] <= min_cab) {
                count++;
                j++; // 跳过后一个
            }
        }
        return count >= k;
    }

public:
    int minCapability(vector<int> &nums, int k) {
        if (nums.size() == 1 && k == 1) {
            return nums[0];
        }
        vector<int> cp = nums;
        sort(cp.begin(), cp.end());
        cout << cp[1] << endl;
        int lo = 0;
        int mid;
        int hi = cp.size();
        while (lo < hi) {
            mid = lo + (hi - lo) / 2;
            if (isValid(nums, k, cp[mid])) { // mid 满足
                hi = mid; // 找最小的
            } else {
                lo = mid + 1;
            }
        }
        cout << lo << endl;
        return cp[lo];
    }


};

// @lc code=end
int main() {
    Solution s;
    vector<int> v = {2, 7, 9, 3, 1};
    s.minCapability(v, 2);
    return 0;

}
