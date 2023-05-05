#include <iostream>
#include <vector>
using namespace std;


// 两种写法，都可以

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
    int removeElement(vector<int>& nums, int val) {
        int left = 0;
        int n = nums.size();
        for (int right = 0; right < n; right++){
            if (nums[right] != val){
                nums[left] = nums[right];
                left++;
            }
            printVerctor(nums);
        }
        return left;
    }
};



class Solution1 {
public:
    int removeElement(vector<int>& nums, int val) {

        int left = 0;
        int n = nums.size();
        for (int right = 0; right < n; right++){
            if (nums[right] == val){
                continue;
            }
            else{
                nums[left++] = nums[right];
            }
            printVerctor(nums);
        }
        return left;
    }
};

// 为了减少元素的移动量，可以将右边的不等于 val 的元素移动到左边等于 val 的元素
class Solution2 {
public:
    int removeElement(vector<int>& nums, int val) {

        int left = 0;
        int right = nums.size() -1;
        
        while (left <= right){
            if (nums[right] != val){
                if(nums[left] != val){
                    left++;
                }
                else{
                    nums[left] =  nums[right];
                    left++;
                    right--;
                }
            }
            else{
                right--;
            }
            cout << "\n*********" << endl;
            printVerctor(nums);
            cout << "left =" << left << endl;
            cout << "right = " << right << endl;
            cout << "\n*********" << endl;
        }
        return left;
    }
};


int main(int argc, char const *argv[])
{
    vector<int> v1 = {0,1,2,2,3,0,4,2}; 
    int a = 2;
    int b;
    Solution s;
    Solution1 s1;
    Solution2 s2;
    // b = s.removeElement(v1, a);
    // b = s1.removeElement(v1, a);
    b = s2.removeElement(v1, a);

    cout << "num = " << b << endl;
    
    return b;
}
