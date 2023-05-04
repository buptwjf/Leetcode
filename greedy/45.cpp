/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */
#include <vector>

using namespace std;

// @lc code=start
/*
 * 思路：需要找出潜力最大的两步中的第一步
 * */
class Solution {
public:
    int jump(vector<int> &nums) {
        int flag = 0;
        int start = 0;
        int num = 0;
        if (nums.size() == 1) return 0;

        while (start < nums.size()) {
            // 当到达末尾

            // 第一步跳跃
            flag = max(flag, start + nums[start]);

            // 第二部跳跃
            int nextFlag = start;
            int next = start;
            // 在第二步中找到最有潜力的next
            for (int j = start; j <= flag; j++) {

                if (flag >= nums.size() - 1) {
                    return num + 1;
                }
                if (nextFlag < j + nums[j]) {
                    nextFlag = max(nextFlag, j + nums[j]);
                    next = j;
                }
            }
            start = next;
            num++;
        }
        return num; // 这里其实没啥用？

    }
};

// @lc code=end
int main() {
    Solution s;
    vector<int> v = {2, 3, 1, 1, 4};
    s.jump(v);
    return 0;
}
