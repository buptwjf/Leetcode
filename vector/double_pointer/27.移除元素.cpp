/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
class Solution {  // t = O(n)
public:
    int removeElement(vector<int>& nums, int val) {
        int left = 0;
        int n = nums.size();
        for (int right = 0; right < nums.size(); right++){
            if (nums[right] != val){
                nums[left] = nums[right];
                left++;
            }
            else{
                n--;
            }
        }
        return n; // 注意left 作为下标，实际上是第 new_size + 1 个元素
    }
};
// @lc code=end


class Solution { // t = O(n)
public:
    int removeElement(vector<int>& nums, int val) {
        int left = 0;
        int n = nums.size();
        for (int right = 0; right < nums.size(); right++){
            if (nums[right] != val){
                nums[left] = nums[right];
                left++;
            }
            else{
                n--;
            }
        }
        return n; // 注意left 作为下标，实际上是第 new_size + 1 个元素s
    }
};



class Solution2 { // t = O(n) 但元素移动量最小
public:
    int removeElement(vector<int>& nums, int val) {
        int left = 0;
        int right = nums.size() -1;
        
        while (left <= right){ // 在不越位得条件下
            if (nums[right] != val){    // 后指针满足
                if(nums[left] != val){          // 前指针也满足
                    left++;                     // 前指针后移，等待下一位
                }
                else{
                    nums[left] =  nums[right];  // 进行操作
                    left++; right--;            // 操作完后，前指针后移，后指针前移
                    
                }
            }
            else{                       // 后指针不满足 
                right--;                // 后指针前移
            }
        }
        return left;  // 注意left 作为下标，实际上是第 new_size + 1 个元素
    }
};
