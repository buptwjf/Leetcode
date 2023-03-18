#include <vector>
#include <iostream>
using namespace std;


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
    vector<vector<int>> generateMatrix(int n) {
        int d = n;
        vector<vector<int>>v(n,vector<int>(n,0));//m行n列的数组

        int i = 0; // 行
        int j = 0; // 列
        

        // 定义 x 和 y 的起始位置
        int startx = 0;
        int starty = 0;

        int loop = n / 2;
        int mid = n / 2;


        int a = 0;
        int offset = 1; // 需要定义循环长度，每次循环右边界
        
        // 先跑一圈
        while(loop --){
            for(j = starty; j < (n - offset); j++){
            v[i][j] = a++;
            cout << "v[" << i << "][" << j << "]"<< v[i][j] <<"\t";   // i = 0;  j = 2
            }
            cout << endl;

            for(i = startx; i < (n - offset); i++){
                v[i][j] = a++;                                            // x = 2;  j = 2
                cout << "v[" << i << "][" << j << "]"<< v[i][j] <<"\t";
            }
            cout << endl;

            for(; j > starty; j --){                                      // x = 2;   j = 0;
                v[i][j] = a++;
                cout << "v[" << i << "][" << j << "]"<< v[i][j] <<"\t";
            }
            cout << endl;

            for(; i > startx; i--){                      
                v[i][j] = a++;
                cout << "v[" << i << "][" << j << "]"<< v[i][j] << "\t";
            }
            cout << endl;
            
            starty++;
            startx++;

            offset++;
        }

        if(n % 2){ // 如果 n 为奇数，则需要给矩阵最中间的位置赋值
            v[mid][mid] = a;
            cout << "v[" << mid << "][" << mid << "]=" << a << endl;
        }

        return v;
    }
};


int main(int argc, char const *argv[]){
    Solution s;
    int n = 6;
    s.generateMatrix(n);
    return 0;
}
