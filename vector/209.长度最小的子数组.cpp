/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */

// @lc code=start
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int right = 0;
        int min = 0;
        int sum = 0;
        int flag = 0;
        while(left <= right && right <= (nums.size()-1)){
            // 计算 sum 
            if(min == 0 ){

                sum = sum + nums[right];

            } // 不满足
            else {
                if(flag == 1)
                    sum = sum - nums[left-1];// 执行 i++
                else
                    sum = sum -nums[ left-1] + nums[right]; // 执行 left++，right++
            }

            if(sum < target ){ // 不满足
                if(min == 0)  // 还没有好的
                    right++;
                else{
                    left++;
                    right++;
                    flag = 0;
                }
            }
            else{
                flag = 1;
                min = right - left + 1;
                left++;
            }
        }
        return min;
    }

};
// @lc code=end

