/*
 * @lc app=leetcode.cn id=912 lang=cpp
 *
 * [912] 排序数组
 */
#include "../../include/user.h"

using namespace std;

// @lc code=star

// 拉布拉多的归并排序写法

class Solution {
public:
    vector<int> sortArray(vector<int> &nums) {
        temp.resize(nums.size(), 0);
        sort(nums, 0, nums.size() - 1);
        return nums;
    }

private:
    vector<int> temp; // 归并排序必须要有个辅助数组

    // 将子数组 nums[lo, hi]进行排序
    void sort(vector<int> &nums, int lo, int hi) {
        // 递归终止条件
        if (lo == hi) {
            return;
        }
        // 防止溢出
        int mid = lo + (hi - lo) / 2;
        // 先对左边进行排序
        sort(nums, lo, mid);
        // 再对右边进行排序
        sort(nums, mid + 1, hi);
        merge(nums, lo, mid, hi);
    }

    // 使用双指针法，合并 [lo, mid] [mid+1, hi] 两个有序数组
    void merge(vector<int> &nums, int lo, int mid, int hi) {
        // 初始化辅助数组
        int i = lo, j = mid + 1;
        for (int p = lo; p <= hi; p++) {
            if (i == mid + 1) { // 左边数组以全部被合并
                temp[p] = nums[j++];
            } else if (j == hi + 1) { // 右边数组已经被合并
                temp[p] = nums[i++];
            } else if (nums[i] > nums[j]) {
                temp[p] = nums[j++];
            } else {
                temp[p] = nums[i++];
            }
        }

        for (int i = lo; i <= hi; i++) {
            nums[i] = temp[i];
        }
    }
};

// @lc code=end
