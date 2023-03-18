#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

typedef int Rank;

void printVerctor(vector<int> v) {
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

class Solution { // 时间复杂度 O(n) ， 所需要额外空间 O(n)
  public:
    vector<int> sortedSquares(vector<int> &nums) {
        Rank left = 0;
        Rank right = nums.size() - 1;
        int n = nums.size() - 1;
        vector<int> temp_nums(nums.size(), 0);

        while (left <= right) {
            if (abs(nums[left]) >= abs(nums[right])) {
                temp_nums[n--] = nums[left] * nums[left];
                left++;
            } else {
                temp_nums[n--] = nums[right] * nums[right];
                right--;
            }
        }
        nums = temp_nums;
        printVerctor(nums);
        return temp_nums;
    }
};

// class Solution {
// public:
//     vector<int> sortedSquares(vector<int>& nums) {
//         Rank left  = 0;
//         Rank right  = nums.size();
//         int temp;

//         while (left <= right){
//             if (abs(nums[left]) >= abs(nums[right])){
//                 temp = nums[right];
//                 nums[right] = nums[left] * nums[left];
//                 nums[left] = temp;
//                 right--;
//             }
//             else{
//                 nums[right] = nums[right] * nums[right];
//                 right--;
//             }
//             printVerctor(nums);
//         }
//     }
// };

int main(int argc, char const *argv[]) {
    vector<int> v1 = {-3, -2, -1, 0, 1, 2, 5};
    Solution s;
    s.sortedSquares(v1);
    return 0;
}
