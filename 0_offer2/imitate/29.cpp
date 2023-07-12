class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;

        int m = matrix.size();          
        if( m== 0){
            return res;
        }
        int n = matrix[0].size();
      
        int up = 0;
        int down = m - 1;
        int left = 0;
        int right = n - 1;
        
        while (res.size() < m * n) {
            // 从左到右
            if(up <= down){ // 这个边界条件很重要，
                for (int i = left; i <= right; i++) {
                    res.push_back(matrix[up][i]);
                }
                up++;
            }
            // 从上到下
            if (left <= right) {
                for (int i = up; i <= down; i++) {
                    res.push_back(matrix[i][right]);
                }
            }
            right--;
            // 从右到左
            if (up <= down) {
                for (int i = right; i >= left; i--) {
                    res.push_back(matrix[down][i]);
                }
                down--;
            }
            // 从下到上
            if (left <= right) {
                for (int i = down; i >= up; i--) {
                    res.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        return res;
    }
};