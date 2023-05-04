/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start

/*
 * 最基础的子集问题
 * 关键：
 * 1. 画出递归树
 * 2. 题目已经给你排序和去重，所以不需要你自己
 * 3. 与之前的回溯区别不同的没有去重，并且对 path 的集合没有要求
 *
 */

#include <vector>

using namespace std;

class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;

    void traversal(vector<int> &nums, int startIndex){
        result.push_back(path);
        if(startIndex == nums.size()){
            return;
        }

        for(int i = startIndex; i< nums.size(); i++){
            path.push_back(nums[i]);
            traversal(nums, i+1);
            path.pop_back();
        }
    }
public:

    vector<vector<int>> subsets(vector<int> &nums) {
        result.clear();
        path.clear();
        traversal(nums, 0);
        return result;
    }
};
// @lc code=end

