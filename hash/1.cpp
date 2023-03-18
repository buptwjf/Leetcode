#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // 创建 hash 表
        unordered_map<int, int> map;
        // 遍历当前元素，并寻找是否有匹配的 key
        auto iter = map.find(target - nums[i]);
        if(iter != map.end()){
            return {iter->second, i};
        }
        else{
            map.insert(nums[i], i);
        }

    }
};