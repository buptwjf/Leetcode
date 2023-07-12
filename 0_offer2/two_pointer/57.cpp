//
// Created by 86188 on 2023/6/27.
//

#include "../include/user.h"

using namespace std;
// 思路：双指针（左右指针）

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        int sum = nums[left] + nums[right];

        while(left < nums.size()-2 && right > 0){
            if(sum == target){
                break;
            }else if(sum < target){ // 扩大 sum
                sum -= nums[left];
                left++;
                sum+= nums[left];
            }else{
                cout << "-";
                sum -= nums[right];
                right--;
                sum += nums[right];
            }
        }
        return {nums[left], nums[right]};
    }
};