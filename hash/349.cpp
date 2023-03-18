#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
  public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
        unordered_set<int> result_set; // 存放结果
        unordered_set<int> nums_set(nums1.begin(), nums1.end());
        for (int num : nums2) { // 对 nums2 中的元素遍历
            if (nums_set.find(num) != nums_set.end()) { // 找到了这个元素
                result_set.insert(num);                 // 加入列表
            }
        }
        return vector<int>(result_set.begin(), result_set.end());
    }
};

// 当给定的数的范围小于 1000 时，可以使用数组作为 hash 表
class Solution1 {
  public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
        unordered_set<int> result_set; // 存放结果
        int hash[1005] = {0};          // 默认数值
        for (int num : nums1) {        // 对 nums1 中的元素遍历
            hash[num] = 1;             // 建立 hash 表
        }

        for (int num : nums2) {
            if (hash[num] == 1) {
                result_set.insert(num);
            }
        }
        return result_set;
    }
};