/*
 * @lc app=leetcode.cn id=704 lang=cpp
 *
 * [704] 二分查找
 */

/*
    1. 二分查找主要是边界条件限制很重要，不同得边界条件会影响语法
    2. 该方法无法保证当向量重复时，返回秩最大的元素（最后的）
    3. 失败时候，没有返回失败的位置
*/


#include <vector>
using namespace std;
class Solution {
public:
        int search(vector<int>& nums, int target) {
        typedef int Rank;
        Rank lo, hi;
        lo = 0; hi = nums.size()-1; // !!!

        while (lo <= hi){ // !!!
            Rank mi = (hi + lo) / 2;
            // Rank mi = (hi + lo) / 2;
            if(nums[mi] == target){
                return mi;
            }
            else if(nums[mi] < target){
                lo = mi + 1;
            }
            else {
                hi = mi -1 ; // !!!
            }
        }
        return -1;
    }
};

class Solution1 {
public:
        int search(vector<int>& nums, int target) {
        typedef int Rank;
        Rank lo, hi;
        lo = 0; hi = nums.size(); // !!!

        while (lo < hi){  // !!!
            Rank mi = (hi + lo) / 2;
            if(nums[mi] == target){
                return mi;
            }
            else if(nums[mi] < target){
                lo = mi + 1;
            }
            else {
                hi = mi; // !!!
            }
        }
        return -1;
    }
};


