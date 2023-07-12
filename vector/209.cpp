/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */

// @lc code=start

#include <vector>
#include <iostream>
#include <cmath>
using namespace std;


typedef int Rank;


/*
    使用滑动窗口法，注意的几个条件为：
    1. 停止条件：right < nums.size()
    2. 移动条件：不满足大小
    3. 缩小条件：满足大小
*/

void printVerctor(vector<int> v)
{
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
    cout << endl;	
}


class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        Rank left = 0;
        Rank right = 0;
        int min = 0;
        int sum = 0;
        int flag = 0;

        while(left <= right && right <= (nums.size()-1)){
            // 计算 sum 
            if(min == 0 ){              // 不满足
                sum = sum + nums[right];  // 一直加到满足
            } 
            else { 
                if(flag == 1) // 满足得到窗口宽度
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
            
            cout << "sum = " << sum << endl;    

            cout << "right = " << right << endl;    
            cout << "left = " << left << endl;    
            cout << "min = " << min << endl;    
            cout << "*********" << endl;
        }
        return min;
    }
};
// @lc code=end


class Solution1 {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int Sublength;
        int result = INT32_MAX;
        int start = 0;
        int end;
        int sum = 0; // 滑动窗口之内的元素和
        for ( end = 0; end < nums.size(); end++){
            sum += nums[end]; // 一直取和
            while(sum >= target){ // 直到满足
                Sublength = (end - start + 1); // 滑动窗口的长度
                result = result < Sublength ? result : Sublength;
                sum -= nums[start++];
            }
        }

        result = (result == INT32_MAX) ? 0 : result;  // 如果最终还是没有满足要求，则返回 0
        cout << "result = " << result << endl;
        return result;
    }
};


int main(int argc, char const *argv[]){
    // vector<int> v = {2,3,1,2,4,3};
    vector<int> v = {5,1,3,5,10,7,4,9,2,8};

    int target = 15;
    // Solution s;
    Solution1 s1;

    // s.minSubArrayLen(target, v);
    s1.minSubArrayLen(target, v);
    return 0;
}