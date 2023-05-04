/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 */

// @lc code=start

/*
 * 关键：
 *      1. 同层需要做剪枝，使用 used 数组, 当前元素和前面的元素相等时，且前一个元素已经使用，那么就跳过
 *      2. 每个树节点都是最终结果（不是叶节点）
 *
 */

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;

    void backtracking(vector<int> &nums, int startIndex, vector<bool> &used) {
        result.push_back(path);
        if (startIndex == nums.size()) {
            return;
        }

        for (int i = startIndex; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1] && used[i- 1]== false) {
                // 当 nums[i]与他的前一位相等时，且他的前一位的 used为0（也就是前一位已经递归 + 回溯过了）
                continue;
            }
            path.push_back(nums[i]);
            used[i] = true;
            backtracking(nums, i + 1, used);
            used[i] = false;
            path.pop_back();

        }


    }

public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        result.clear();
        path.clear();

        // 初始化 used 数组
        vector<bool> used(nums.size(), false);
        // 对 nums 进行排序
        sort(nums.begin(), nums.end());

        backtracking(nums, 0, used);
        return result;
    }
};
// @lc code=end

int main() {
    Solution s;
    vector<int> v = {1, 2, 2};
    s.subsetsWithDup(v);
    return 0;
}

