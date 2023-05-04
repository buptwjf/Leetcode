/*
 * @lc app=leetcode.cn id=491 lang=cpp
 *
 * [491] 递增子序列
 */

// @lc code=start

/*
 * 递增子序列
 * 输入数组为 {4，6，7，6}
 * 递增子序列为 {4,6} {4,6,7} {4,7} {6,7} {4,6,6}
 * 在每层遍历中，需要去重
 *
 */
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;

    void backtracking(vector<int> &nums, int startIndex) {
        if (path.size() > 1) {
            result.push_back(path);
        }


        unordered_set<int> usedSet;
        for (int i = startIndex; i < nums.size(); i++) {
            pair<unordered_set<int>::iterator, bool> ret = usedSet.insert(nums[i]);
            if (!path.empty() && nums[i] < path.back() || !ret.second)   // 这一块的逻辑是关键，一定要写清楚
                continue;
            }
            path.push_back(nums[i]);

            backtracking(nums, i + 1);
            path.pop_back();

        }
    }

public:
    vector<vector<int>> findSubsequences(vector<int> &nums) {
        result.clear();
        path.clear();
        backtracking(nums, 0);
        return result;
    }
};
// @lc code=end

int main() {
    Solution s;
    vector<int> v = {1, 2, 1, 1, 1};
    s.findSubsequences(v);
    return 0;
}
