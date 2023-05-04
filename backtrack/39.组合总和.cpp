/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start

/*
 * 无重复元素的整数数组
 * 凑出来相加等于 target
 *
 * 一定要搞清楚 树的横向遍历，和纵向遍历。
 *  第一个分支下的总是从第一个开始，第二个分支下的总是从第二个开始
 */
#include <vector>

using namespace std;

class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;

    void traversal(vector<int> &candidates, int startIndex, int sum, int target) {
        // 终止条件 当求和满足
        if (sum == target) {
            result.push_back(path);
            return;
        }
        if (sum > target) {
            return;
        }

        for (int i = startIndex; i < candidates.size(); i++) {
            // 对当前节点进行操作
            path.push_back(candidates[i]);
            sum += candidates[i];

            // 进行递归
            traversal(candidates, i, sum, target);
            int tmp = path[path.size() - 1];path.pop_back();
            sum -= tmp;
        }
    }

public:

    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        result.clear();
        path.clear();
        traversal(candidates, 0, 0, target);
        return result;
    }
};
// @lc code=end

int main() {
    Solution s;
    vector<int> a = {8, 7, 4, 3};
    s.combinationSum(a, 11);
    return 0;
}